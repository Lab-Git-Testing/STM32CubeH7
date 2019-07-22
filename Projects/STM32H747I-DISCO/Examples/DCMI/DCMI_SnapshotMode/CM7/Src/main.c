/**
  ******************************************************************************
  * @file    DCMI/DCMI_SnapshotMode/CM7/Src/main.c
  * @author  MCD Application Team
  * @brief   This example describe how to configure the camera interface (DCMI) in snapshot
  *          mode to handle a single image capture in QVGA (320x240) resolution and RGB565
  *          format and display the obtained image on LCD screen.
  *          This is the main program for Cortex-M7.    
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32H7xx_HAL_Examples
  * @{
  */

/** @addtogroup DCMI_SnapshotMode
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Camera resolution is QVGA (320x240) */
static uint32_t   CameraResX = QVGA_RES_X;
static uint32_t   CameraResY = QVGA_RES_Y;
static uint32_t   LcdResX    = 0;
static uint32_t   LcdResY    = 0;

__IO uint32_t camera_frame_ready = 0;
__IO uint32_t lcd_frame_ready = 0;

/* Private function prototypes -----------------------------------------------*/
static void SystemClock_Config(void);
static void DMA2D_ConvertFrameToARGB8888(void *pSrc, void *pDst, uint32_t xsize, uint32_t ysize);
static void DMA2D_TransferCompleteCallback(DMA2D_HandleTypeDef *hdma2d);
static void CPU_CACHE_Enable(void);
static void MPU_Config(void);
void Error_Handler(void);

/* Exported functions ---------------------------------------------------------*/

/**
  * @brief  Main program
  * @param  None
  * @retval None
  */
int main(void)
{
  /* System Init, System clock, voltage scaling and L1-Cache configuration are done by CPU1 (Cortex-M7) 
     in the meantime Domain D2 is put in STOP mode(Cortex-M4 in deep-sleep)
  */

  /* Configure the MPU attributes as Write Through for SDRAM*/
  MPU_Config();
  
  /* Enable the CPU Cache */
  CPU_CACHE_Enable();
  
  CameraResX = QVGA_RES_X;
  CameraResY = QVGA_RES_Y;
										  

  /* STM32H7xx HAL library initialization:
       - Systick timer is configured by default as source of time base, but user 
         can eventually implement his proper time base source (a general purpose 
         timer for example or other time source), keeping in mind that Time base 
         duration should be kept 1ms since PPP_TIMEOUT_VALUEs are defined and 
         handled in milliseconds basis.
       - Set NVIC Group Priority to 4
       - Low Level Initialization
     */
  HAL_Init();

  /* Configure the system clock to 400 MHz */
  SystemClock_Config();

  /* When system initialization is finished, Cortex-M7 could wakeup (when needed) the Cortex-M4  by means of 
     HSEM notification or by any D2 wakeup source (SEV,EXTI..)   */   
  
  /* LEDs initialization */  
  BSP_LED_Init(LED_RED);
  BSP_LED_Init(LED_GREEN);
  
  /*##- Initialise the LCD #################################################*/
  /* Proceed to LTDC, DSI and LCD screen initialization with the configuration filled in above */
  /* for stageNb == 1 */
  BSP_LCD_Init();
  BSP_LCD_LayerDefaultInit(1, LCD_FRAME_BUFFER);   
  BSP_LCD_SelectLayer(1);

  /* Get LCD width and height*/  
  LcdResX = BSP_LCD_GetXSize();
  LcdResY = BSP_LCD_GetYSize();  

  /* Reset and power down camera to be sure camera is Off prior start testing BSP */
  BSP_CAMERA_PwrDown();
    
  /* Prepare using DMA2D the 800x480 LCD frame buffer to display background color black */
  /* and title of the example                                                           */
  BSP_LCD_Clear(LCD_COLOR_BLACK);
  BSP_LCD_SetTextColor(LCD_COLOR_WHITE);
  BSP_LCD_SetBackColor(LCD_COLOR_BLUE);
  BSP_LCD_SetFont(&Font16);

  /* Print example description */
  BSP_LCD_DisplayStringAt(0, 440, (uint8_t *)"DCMI Snapshot example", CENTER_MODE);   

  /*## Camera Initialization and capture start ############################*/
  /* Initialize the Camera in QVGA mode */
  if(BSP_CAMERA_Init(CAMERA_R320x240) != CAMERA_OK)
  {
    Error_Handler(); 
  }

  /* Wait 1s to let auto-loops in the camera module converge and lead to correct exposure */
  HAL_Delay(1000);

  /* Start the Camera Snapshot Capture */
  BSP_CAMERA_SnapshotStart((uint8_t *)CAMERA_FRAME_BUFFER);

  /* Wait until camera frame is ready : DCMI Frame event */
  while(camera_frame_ready == 0)
  {
  }
  
  /* Stop the camera to avoid having the DMA2D work in parallel of Display */
  /* which cause perturbation of LTDC                                      */
  BSP_CAMERA_Stop();

  /* Copy the Camera captured frame to the LCD display buffer using DMA2D */
  DMA2D_ConvertFrameToARGB8888((uint32_t *)(CAMERA_FRAME_BUFFER), (uint32_t *)(LCD_FRAME_BUFFER), CameraResX, CameraResY);
  
  /* Wait until DMA2D transfer complete : LCD frame is ready  */
  while(lcd_frame_ready == 0)
  {
  }
  
  BSP_LCD_ClearStringLine(460);
  BSP_LCD_DisplayStringAt(0, 460, (uint8_t *)"Capture OK - Test End", CENTER_MODE);

  while (1)
  {
    HAL_Delay(100);
    BSP_LED_Toggle(LED_GREEN);
  }
}

/**
  * @brief  Converts a line to an ARGB8888 pixel format.
  * @param  pSrc: Pointer to source buffer
  * @param  pDst: Output color
  * @param  ColorMode: Input color mode
  * @retval None
  */
static void DMA2D_ConvertFrameToARGB8888(void *pSrc, void *pDst, uint32_t xsize, uint32_t ysize)
{
  uint32_t xPos, yPos, destination;   
  
  /* Calculate the destination transfer address */
  xPos = (LcdResX  - xsize)/2;
  yPos = (LcdResY  - ysize)/2;  
  
  /* Enable DMA2D clock */
  __HAL_RCC_DMA2D_CLK_ENABLE();

  /* Configure the DMA2D Mode, Color Mode and output offset */
  hdma2d_discovery.Init.Mode         = DMA2D_M2M_PFC;
  hdma2d_discovery.Init.ColorMode    = DMA2D_OUTPUT_ARGB8888; /* Output color out of PFC */
  hdma2d_discovery.Init.OutputOffset = LcdResX - xsize;
  hdma2d_discovery.Init.AlphaInverted = DMA2D_REGULAR_ALPHA;  /* No Output Alpha Inversion*/  
  hdma2d_discovery.Init.RedBlueSwap   = DMA2D_RB_REGULAR;     /* No Output Red & Blue swap */ 

  /* DMA2D Callbacks Configuration */
  hdma2d_discovery.XferCpltCallback  = DMA2D_TransferCompleteCallback;  

  /* Foreground Configuration */
  hdma2d_discovery.LayerCfg[1].AlphaMode = DMA2D_NO_MODIF_ALPHA;
  hdma2d_discovery.LayerCfg[1].InputAlpha = 0xFF; /* fully opaque */
  hdma2d_discovery.LayerCfg[1].InputColorMode = DMA2D_INPUT_RGB565;
  hdma2d_discovery.LayerCfg[1].InputOffset = 0;
  hdma2d_discovery.LayerCfg[1].RedBlueSwap = DMA2D_RB_REGULAR; /* No ForeGround Red/Blue swap */
  hdma2d_discovery.LayerCfg[1].AlphaInverted = DMA2D_REGULAR_ALPHA; /* No ForeGround Alpha inversion */ 
  
  hdma2d_discovery.Instance = DMA2D;

  /* DMA2D Initialization */
  if(HAL_DMA2D_Init(&hdma2d_discovery) == HAL_OK) 
  {
    if(HAL_DMA2D_ConfigLayer(&hdma2d_discovery, 1) != HAL_OK) 
    {
      Error_Handler();      
    }
  }
  else
  {
    Error_Handler();
  } 
  
  /* Calculate the destination transfer address */
  xPos = (LcdResX  - xsize)/2;
  yPos = (LcdResY  - ysize)/2;  
  
  destination = (uint32_t)pDst + (yPos * LcdResX + xPos) * ARGB8888_BYTE_PER_PIXEL;
  
  /* Starts the DMA2D transfer */
  if(HAL_DMA2D_Start_IT(&hdma2d_discovery, (uint32_t)pSrc, destination, xsize, ysize) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief  Camera line event callback
  * @param  None
  * @retval None
  */
void BSP_CAMERA_FrameEventCallback(void)
{
  camera_frame_ready = 1;
}

/**
 * @brief  DMA2D Transfer completed callback
 * @param  hdma2d: DMA2D handle.
 * @retval None
 */
static void DMA2D_TransferCompleteCallback(DMA2D_HandleTypeDef *hdma2d)
{
  lcd_frame_ready = 1;
}

/**
  * @brief  System Clock Configuration
  *         The system Clock is configured as follow : 
  *            System Clock source            = PLL (HSE)
  *            SYSCLK(Hz)                     = 400000000 (Cortex-M7 CPU Clock)
  *            HCLK(Hz)                       = 200000000 (Cortex-M4 CPU, Bus matrix Clocks)
  *            AHB Prescaler                  = 2
  *            D1 APB3 Prescaler              = 2 (APB3 Clock  100MHz)
  *            D2 APB1 Prescaler              = 2 (APB1 Clock  100MHz)
  *            D2 APB2 Prescaler              = 2 (APB2 Clock  100MHz)
  *            D3 APB4 Prescaler              = 2 (APB4 Clock  100MHz)
  *            HSE Frequency(Hz)              = 25000000
  *            PLL_M                          = 5
  *            PLL_N                          = 160
  *            PLL_P                          = 2
  *            PLL_Q                          = 4
  *            PLL_R                          = 2
  *            VDD(V)                         = 3.3
  *            Flash Latency(WS)              = 4
  * @param  None
  * @retval None
  */
static void SystemClock_Config(void)
{
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_OscInitTypeDef RCC_OscInitStruct;
  HAL_StatusTypeDef ret = HAL_OK;
  
  /*!< Supply configuration update enable */
  HAL_PWREx_ConfigSupply(PWR_DIRECT_SMPS_SUPPLY);

  /* The voltage scaling allows optimizing the power consumption when the device is 
     clocked below the maximum system frequency, to update the voltage scaling value 
     regarding system frequency refer to product datasheet.  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}
  
  /* Enable HSE Oscillator and activate PLL with HSE as source */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_OFF;
  RCC_OscInitStruct.CSIState = RCC_CSI_OFF;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;

  RCC_OscInitStruct.PLL.PLLM = 5;
  RCC_OscInitStruct.PLL.PLLN = 160;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  RCC_OscInitStruct.PLL.PLLP = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLQ = 4;

  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_2;
  ret = HAL_RCC_OscConfig(&RCC_OscInitStruct);
  if(ret != HAL_OK)
  {
    Error_Handler();
  }
  
/* Select PLL as system clock source and configure  bus clocks dividers */
  RCC_ClkInitStruct.ClockType = (RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_D1PCLK1 | RCC_CLOCKTYPE_PCLK1 | \
                                 RCC_CLOCKTYPE_PCLK2  | RCC_CLOCKTYPE_D3PCLK1);

  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;  
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2; 
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2; 
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2; 
  ret = HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_4);
  if(ret != HAL_OK)
  {
    Error_Handler();
  }

 /*
  Note : The activation of the I/O Compensation Cell is recommended with communication  interfaces
          (GPIO, SPI, FMC, QSPI ...)  when  operating at  high frequencies(please refer to product datasheet)       
          The I/O Compensation Cell activation  procedure requires :
        - The activation of the CSI clock
        - The activation of the SYSCFG clock
        - Enabling the I/O Compensation Cell : setting bit[0] of register SYSCFG_CCCSR
 */
 
  /*activate CSI clock mondatory for I/O Compensation Cell*/  
  __HAL_RCC_CSI_ENABLE() ;
    
  /* Enable SYSCFG clock mondatory for I/O Compensation Cell */
  __HAL_RCC_SYSCFG_CLK_ENABLE() ;
  
  /* Enables the I/O Compensation Cell */    
  HAL_EnableCompensationCell();  
}

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* Turn LED REDon */
  BSP_LED_On(LED_RED);
  while(1)
  {
  }
}

/**
  * @brief  CPU L1-Cache enable.
  * @param  None
  * @retval None
  */
static void CPU_CACHE_Enable(void)
{
  /* Enable I-Cache */
  SCB_EnableICache();

  /* Enable D-Cache */
  SCB_EnableDCache();
}

/**
  * @brief  Configure the MPU attributes as Write Through for External SDRAM.
  * @note   The Base Address is 0xD0000000 .
  *         The Configured Region Size is 32MB because same as SDRAM size.
  * @param  None
  * @retval None
  */
static void MPU_Config(void)
{
  MPU_Region_InitTypeDef MPU_InitStruct;
  
  /* Disable the MPU */
  HAL_MPU_Disable();

  /* Configure the MPU attributes as WT for SDRAM */
  MPU_InitStruct.Enable = MPU_REGION_ENABLE;
  MPU_InitStruct.BaseAddress = SDRAM_DEVICE_ADDR;
  MPU_InitStruct.Size = MPU_REGION_SIZE_32MB;
  MPU_InitStruct.AccessPermission = MPU_REGION_FULL_ACCESS;
  MPU_InitStruct.IsBufferable = MPU_ACCESS_NOT_BUFFERABLE;
  MPU_InitStruct.IsCacheable = MPU_ACCESS_CACHEABLE;
  MPU_InitStruct.IsShareable = MPU_ACCESS_NOT_SHAREABLE;
  MPU_InitStruct.Number = MPU_REGION_NUMBER0;
  MPU_InitStruct.TypeExtField = MPU_TEX_LEVEL0;
  MPU_InitStruct.SubRegionDisable = 0x00;
  MPU_InitStruct.DisableExec = MPU_INSTRUCTION_ACCESS_ENABLE;

  HAL_MPU_ConfigRegion(&MPU_InitStruct);

  /* Enable the MPU */
  HAL_MPU_Enable(MPU_PRIVILEGED_DEFAULT);
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
