/*********************************************************************
*                SEGGER Microcontroller GmbH & Co. KG                *
*        Solutions for real time microcontroller applications        *
*                           www.segger.com                           *
**********************************************************************
*                                                                    *
* C-file generated by                                                *
*                                                                    *
*        Bitmap Converter (ST) for emWin V5.32.                      *
*        Compiled Oct  8 2015, 11:58:22                              *
*                                                                    *
*        (c) 1998 - 2015 Segger Microcontroller GmbH & Co. KG        *
*                                                                    *
**********************************************************************
*                                                                    *
* Source file: score                                                 *
* Dimensions:  69 * 17                                               *
* NumColors:   65536 colors + 8 bit alpha channel                    *
*                                                                    *
**********************************************************************
*/

#include <stdlib.h>

#include "GUI.h"

#ifndef GUI_CONST_STORAGE
  #define GUI_CONST_STORAGE const
#endif

extern GUI_CONST_STORAGE GUI_BITMAP bmscore;

#if defined ( __ICCARM__ )
#pragma location="ExtQSPIFlashSection" 
#else
__attribute__((section(".ExtQSPIFlashSection")))  
#endif
static GUI_CONST_STORAGE unsigned char _acscore[] = {
  0xE5,0xFF,0xFF, 0x76,0xFF,0xFF, 0x33,0xFF,0xFF, 0x25,0xFF,0xFF, 0x60,0xFF,0xFF, 0xDB,0xFF,0xFF, 0xFF,0x00,0x00, 0xFF,0x00,0x00, 0xE0,0xFF,0xFF, 0x6A,0xFF,0xFF, 0x1E,0xFF,0xFF, 0x07,0xFF,0xFF, 0x2D,0xFF,0xFF, 0xBB,0xFF,0xFF, 0xFD,0xFF,0xFF, 
        0xFF,0x00,0x00, 0xFE,0xFF,0xFF, 0xC1,0xFF,0xFF, 0x64,0xFF,0xFF, 0x34,0xFF,0xFF, 0x2E,0xFF,0xFF, 0x5F,0xFF,0xFF, 0xCB,0xFF,0xFF, 0xFE,0xFF,0xFF, 0xEC,0xFF,0xFF, 0x3C,0xFF,0xFF, 0x19,0xFF,0xFF, 0x5D,0xFF,0xFF, 0x3B,0xFF,0xFF, 0x33,0xFF,0xFF, 
        0x8D,0xFF,0xFF, 0xF7,0xFF,0xFF, 0xBB,0xFF,0xFF, 0x45,0xFF,0xFF, 0x3C,0xFF,0xFF, 0x3C,0xFF,0xFF, 0x3E,0xFF,0xFF, 0x46,0xFF,0xFF, 0x58,0xFF,0xFF,
  0x53,0xFF,0xFF, 0x03,0xFF,0xFF, 0x0C,0xFF,0xFF, 0x10,0xFF,0xFF, 0x00,0xFF,0xFF, 0x4E,0xFF,0xFF, 0xEE,0xFF,0xFF, 0xE6,0xFF,0xFF, 0x3B,0xFF,0xFF, 0x01,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x1E,0xFF,0xFF, 0xD9,0xFF,0xFF, 
        0xFD,0xFF,0xFF, 0xAF,0xFF,0xFF, 0x13,0xFF,0xFF, 0x00,0xFF,0xFF, 0x02,0xFF,0xFF, 0x01,0xFF,0xFF, 0x00,0xFF,0xFF, 0x22,0xFF,0xFF, 0xCB,0xFF,0xFF, 0xE5,0xFF,0xFF, 0x18,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 
        0x07,0xFF,0xFF, 0xA2,0xFF,0xFF, 0x8B,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x0C,0xFF,0xFF,
  0x0A,0xFF,0xFF, 0x00,0xFF,0xFF, 0x74,0xFF,0xFF, 0xA7,0xFF,0xFF, 0x0B,0xFF,0xFF, 0x1D,0xFF,0xFF, 0xD4,0xFF,0xFF, 0x87,0xFF,0xFF, 0x00,0xFF,0xFF, 0x02,0xFF,0xFF, 0x58,0xFF,0xFF, 0x80,0xFF,0xFF, 0x0A,0xFF,0xFF, 0x00,0xFF,0xFF, 0x90,0xFF,0xFF, 
        0xE8,0xFF,0xFF, 0x32,0xFF,0xFF, 0x00,0xFF,0xFF, 0x23,0xFF,0xFF, 0x93,0xFF,0xFF, 0x8A,0xFF,0xFF, 0x12,0xFF,0xFF, 0x00,0xFF,0xFF, 0x60,0xFF,0xFF, 0xE1,0xFF,0xFF, 0x14,0xFF,0xFF, 0x00,0xFF,0xFF, 0x24,0xFF,0xFF, 0x73,0xFF,0xFF, 0x30,0xFF,0xFF, 
        0x00,0xFF,0xFF, 0x5E,0xFF,0xFF, 0x8B,0xFF,0xFF, 0x00,0xFF,0xFF, 0x2C,0xFF,0xFF, 0x98,0xFF,0xFF, 0x9D,0xFF,0xFF, 0xA4,0xFF,0xFF, 0xAB,0xFF,0xFF,
  0x22,0xFF,0xFF, 0x00,0xFF,0xFF, 0x29,0xFF,0xFF, 0x9E,0xFF,0xFF, 0xD3,0xFF,0xFF, 0xE1,0xFF,0xFF, 0xEA,0xFF,0xFF, 0x3C,0xFF,0xFF, 0x00,0xFF,0xFF, 0x3E,0xFF,0xFF, 0xEE,0xFF,0xFF, 0xF2,0xFF,0xFF, 0x45,0xFF,0xFF, 0x00,0xFF,0xFF, 0x6D,0xFF,0xFF, 
        0xC1,0xFF,0xFF, 0x02,0xFF,0xFF, 0x00,0xFF,0xFF, 0xB6,0xFF,0xFF, 0xFF,0x00,0x00, 0xFD,0xFF,0xFF, 0x7E,0xFF,0xFF, 0x01,0xFF,0xFF, 0x2B,0xFF,0xFF, 0xC7,0xFF,0xFF, 0x10,0xFF,0xFF, 0x00,0xFF,0xFF, 0xB2,0xFF,0xFF, 0xFE,0xFF,0xFF, 0x70,0xFF,0xFF, 
        0x00,0xFF,0xFF, 0x62,0xFF,0xFF, 0x8D,0xFF,0xFF, 0x00,0xFF,0xFF, 0x47,0xFF,0xFF, 0xFA,0xFF,0xFF, 0xFF,0x00,0x00, 0xFF,0x00,0x00, 0xFF,0x00,0x00,
  0xA3,0xFF,0xFF, 0x1F,0xFF,0xFF, 0x01,0xFF,0xFF, 0x08,0xFF,0xFF, 0x4D,0xFF,0xFF, 0xDD,0xFF,0xFF, 0xDC,0xFF,0xFF, 0x21,0xFF,0xFF, 0x00,0xFF,0xFF, 0x81,0xFF,0xFF, 0xFE,0xFF,0xFF, 0xFE,0xFF,0xFF, 0xD4,0xFF,0xFF, 0xBD,0xFF,0xFF, 0xEC,0xFF,0xFF, 
        0xA2,0xFF,0xFF, 0x00,0xFF,0xFF, 0x17,0xFF,0xFF, 0xEC,0xFF,0xFF, 0xFF,0x00,0x00, 0xFF,0x00,0x00, 0xAE,0xFF,0xFF, 0x04,0xFF,0xFF, 0x1C,0xFF,0xFF, 0xB4,0xFF,0xFF, 0x0C,0xFF,0xFF, 0x00,0xFF,0xFF, 0xAF,0xFF,0xFF, 0xB8,0xFF,0xFF, 0x1E,0xFF,0xFF, 
        0x02,0xFF,0xFF, 0xA7,0xFF,0xFF, 0x8F,0xFF,0xFF, 0x00,0xFF,0xFF, 0x0E,0xFF,0xFF, 0x31,0xFF,0xFF, 0x39,0xFF,0xFF, 0x47,0xFF,0xFF, 0xD7,0xFF,0xFF,
  0xF5,0xFF,0xFF, 0xC5,0xFF,0xFF, 0x76,0xFF,0xFF, 0x16,0xFF,0xFF, 0x00,0xFF,0xFF, 0x51,0xFF,0xFF, 0xC7,0xFF,0xFF, 0x19,0xFF,0xFF, 0x00,0xFF,0xFF, 0x93,0xFF,0xFF, 0xFF,0x00,0x00, 0xFF,0x00,0x00, 0xFE,0xFF,0xFF, 0xF4,0xFF,0xFF, 0xFE,0xFF,0xFF, 
        0x9F,0xFF,0xFF, 0x00,0xFF,0xFF, 0x1E,0xFF,0xFF, 0xEE,0xFF,0xFF, 0xFF,0x00,0x00, 0xFF,0x00,0x00, 0xB9,0xFF,0xFF, 0x05,0xFF,0xFF, 0x19,0xFF,0xFF, 0xB0,0xFF,0xFF, 0x08,0xFF,0xFF, 0x00,0xFF,0xFF, 0x38,0xFF,0xFF, 0x17,0xFF,0xFF, 0x04,0xFF,0xFF, 
        0x55,0xFF,0xFF, 0xF1,0xFF,0xFF, 0x91,0xFF,0xFF, 0x00,0xFF,0xFF, 0x01,0xFF,0xFF, 0x04,0xFF,0xFF, 0x04,0xFF,0xFF, 0x13,0xFF,0xFF, 0xC2,0xFF,0xFF,
  0x5F,0xFF,0xFF, 0x53,0xFF,0xFF, 0xCF,0xFF,0xFF, 0xB4,0xFF,0xFF, 0x00,0xFF,0xFF, 0x06,0xFF,0xFF, 0xA5,0xFF,0xFF, 0x2A,0xFF,0xFF, 0x00,0xFF,0xFF, 0x65,0xFF,0xFF, 0xF9,0xFF,0xFF, 0xFF,0x00,0x00, 0xC2,0xFF,0xFF, 0x4E,0xFF,0xFF, 0xA8,0xFF,0xFF, 
        0xB6,0xFF,0xFF, 0x00,0xFF,0xFF, 0x04,0xFF,0xFF, 0xCE,0xFF,0xFF, 0xFF,0x00,0x00, 0xFE,0xFF,0xFF, 0x91,0xFF,0xFF, 0x02,0xFF,0xFF, 0x24,0xFF,0xFF, 0xBB,0xFF,0xFF, 0x05,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x2F,0xFF,0xFF, 
        0xEE,0xFF,0xFF, 0xFF,0x00,0x00, 0x92,0xFF,0xFF, 0x00,0xFF,0xFF, 0x29,0xFF,0xFF, 0x93,0xFF,0xFF, 0x97,0xFF,0xFF, 0x9F,0xFF,0xFF, 0xEF,0xFF,0xFF,
  0x1C,0xFF,0xFF, 0x00,0xFF,0xFF, 0x50,0xFF,0xFF, 0x9A,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0xA8,0xFF,0xFF, 0x67,0xFF,0xFF, 0x00,0xFF,0xFF, 0x09,0xFF,0xFF, 0x6A,0xFF,0xFF, 0x8A,0xFF,0xFF, 0x23,0xFF,0xFF, 0x00,0xFF,0xFF, 0x49,0xFF,0xFF, 
        0xD7,0xFF,0xFF, 0x24,0xFF,0xFF, 0x00,0xFF,0xFF, 0x39,0xFF,0xFF, 0xAF,0xFF,0xFF, 0xA4,0xFF,0xFF, 0x1D,0xFF,0xFF, 0x00,0xFF,0xFF, 0x4C,0xFF,0xFF, 0xD6,0xFF,0xFF, 0x01,0xFF,0xFF, 0x00,0xFF,0xFF, 0x34,0xFF,0xFF, 0x07,0xFF,0xFF, 0x05,0xFF,0xFF, 
        0x51,0xFF,0xFF, 0xDB,0xFF,0xFF, 0x93,0xFF,0xFF, 0x00,0xFF,0xFF, 0x2B,0xFF,0xFF, 0xA1,0xFF,0xFF, 0xA5,0xFF,0xFF, 0xA5,0xFF,0xFF, 0xB3,0xFF,0xFF,
  0x72,0xFF,0xFF, 0x04,0xFF,0xFF, 0x01,0xFF,0xFF, 0x04,0xFF,0xFF, 0x00,0xFF,0xFF, 0x17,0xFF,0xFF, 0xD2,0xFF,0xFF, 0xD8,0xFF,0xFF, 0x2B,0xFF,0xFF, 0x01,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x13,0xFF,0xFF, 0xB0,0xFF,0xFF, 
        0xFB,0xFF,0xFF, 0x94,0xFF,0xFF, 0x0A,0xFF,0xFF, 0x00,0xFF,0xFF, 0x0C,0xFF,0xFF, 0x09,0xFF,0xFF, 0x00,0xFF,0xFF, 0x18,0xFF,0xFF, 0xB8,0xFF,0xFF, 0xD9,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0xAF,0xFF,0xFF, 0x87,0xFF,0xFF, 0x13,0xFF,0xFF, 
        0x00,0xFF,0xFF, 0x74,0xFF,0xFF, 0x93,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x00,0xFF,0xFF, 0x12,0xFF,0xFF,
  0xEB,0xFF,0xFF, 0x71,0xFF,0xFF, 0x1C,0xFF,0xFF, 0x03,0xFF,0xFF, 0x25,0xFF,0xFF, 0xA2,0xFF,0xFF, 0xFA,0xFF,0xFF, 0xFF,0x00,0x00, 0xD9,0xFF,0xFF, 0x69,0xFF,0xFF, 0x2F,0xFF,0xFF, 0x2B,0xFF,0xFF, 0x52,0xFF,0xFF, 0xBD,0xFF,0xFF, 0xFC,0xFF,0xFF, 
        0xFF,0x00,0x00, 0xFB,0xFF,0xFF, 0xA3,0xFF,0xFF, 0x41,0xFF,0xFF, 0x19,0xFF,0xFF, 0x1F,0xFF,0xFF, 0x50,0xFF,0xFF, 0xC0,0xFF,0xFF, 0xFC,0xFF,0xFF, 0xE2,0xFF,0xFF, 0x2C,0xFF,0xFF, 0x2D,0xFF,0xFF, 0xD3,0xFF,0xFF, 0xFB,0xFF,0xFF, 0xB8,0xFF,0xFF, 
        0x3D,0xFF,0xFF, 0xCC,0xFF,0xFF, 0xAD,0xFF,0xFF, 0x22,0xFF,0xFF, 0x1E,0xFF,0xFF, 0x1E,0xFF,0xFF, 0x1E,0xFF,0xFF, 0x1E,0xFF,0xFF, 0x3A,0xFF,0xFF
};

GUI_CONST_STORAGE GUI_BITMAP bmscore = {
  39, // xSize
  10, // ySize
  117, // BytesPerLine
  24, // BitsPerPixel
  (unsigned char *)_acscore,  // Pointer to picture data
  NULL,  // Pointer to palette
  GUI_DRAW_BMPAM565
};

/*************************** End of file ****************************/
