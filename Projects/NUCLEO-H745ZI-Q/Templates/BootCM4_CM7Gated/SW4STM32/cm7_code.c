/*
;******************** (C) COPYRIGHT 2018 STMicroelectronics ********************
;* File Name          : cm7_code.s
;* @author  MCD Application Team
;* Description        : Coretx-M7 binary code include .s file
;*                      allowing to include the Coretx-M7 binary into the
;*                      Coretx-M4 MDK-ARM project
;******************************************************************************
;* @attention
;*
;* Copyright (c) 2018 STMicroelectronics.
;* All rights reserved.
;*
;* This software component is licensed by ST under BSD 3-Clause license,
;* the "License"; You may not use this file except in compliance with the
;* License. You may obtain a copy of the License at:
;*                        opensource.org/licenses/BSD-3-Clause
;*
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "string.h"

#if defined (__GNUC__)
asm(".section .cm7_code,\"a\";"
                             ".incbin \"../Debug_CM7/STM32H745I_Nucleo_CM7.bin\";"
);
#endif 

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
