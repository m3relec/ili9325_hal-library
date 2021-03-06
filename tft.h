/*
                           ....::::: In The Name Of GOD :::::....

    TFT LCD (ILI9325-ILI9320 LCD Driver) Functions
    By Ali Imanifar   Shahrood University of Technology    1389/06/16   

*/
 #ifndef _tft_H_
    #define _tft_H_                            
#include "stm32f1xx_hal.h"



 #define PORTRAIT   1


 #define LCD_CONTROLPORT_PORT  GPIOB

 #define LCD_RST_PIN  10
 
 #define LCD_RS_PIN  8

 #define LCD_CS_PIN  9
 
 #define LCD_RD_PIN  6
  
 #define LCD_WR_PIN  7
 
 #define LCD_DATAPORT_MSB_PORT  GPIOA 
 
 #define LCD_DATAPORT_LSB_PORT  GPIOC




#define HIGH 1
#define LOW  0

#define RST_LOW       LCD_CONTROLPORT_PORT->ODR&=~(1<<LCD_RST_PIN)
#define RST_HIGH      LCD_CONTROLPORT_PORT->ODR|=(1<<LCD_RST_PIN)
#define RS_LOW        LCD_CONTROLPORT_PORT->ODR&=~(1<<LCD_RS_PIN)
#define RS_HIGH       LCD_CONTROLPORT_PORT->ODR|=(1<<LCD_RS_PIN)
#define CS_LOW        LCD_CONTROLPORT_PORT->ODR&=~(1<<LCD_CS_PIN)
#define CS_HIGH       LCD_CONTROLPORT_PORT->ODR|=(1<<LCD_CS_PIN)
#define RD_LOW        LCD_CONTROLPORT_PORT->ODR&=~(1<<LCD_RD_PIN)
#define RD_HIGH       LCD_CONTROLPORT_PORT->ODR|=(1<<LCD_RD_PIN)
#define WR_LOW        LCD_CONTROLPORT_PORT->ODR&=~(1<<LCD_WR_PIN)
#define WR_HIGH       LCD_CONTROLPORT_PORT->ODR|=(1<<LCD_WR_PIN)

void LCD_DATAPORT_INPUT (void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin =0XFF;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCD_DATAPORT_MSB_PORT, &GPIO_InitStruct);
  HAL_GPIO_Init(LCD_DATAPORT_LSB_PORT, &GPIO_InitStruct);
} 

void LCD_DATAPORT_OUTPUT (void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin =0XFF;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCD_DATAPORT_MSB_PORT, &GPIO_InitStruct);
  HAL_GPIO_Init(LCD_DATAPORT_LSB_PORT, &GPIO_InitStruct);
} 

void LCD_CONTROLPORT_PORT_OUTPUT(void)
{
  GPIO_InitTypeDef GPIO_InitStruct;
  GPIO_InitStruct.Pin=(1<<LCD_RST_PIN)|(1<<LCD_RS_PIN)|(1<<LCD_CS_PIN)|(1<<LCD_RD_PIN)|(1<<LCD_WR_PIN);
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
  HAL_GPIO_Init(LCD_CONTROLPORT_PORT, &GPIO_InitStruct);
}  

//#define LCD_DATAPORT_INPUT          LCD_DATAPORT_MSB_DDR=0x00;LCD_DATAPORT_LSB_DDR=0x00
//#define LCD_DATAPORT_OUTPUT         LCD_DATAPORT_MSB_DDR=0xFF;LCD_DATAPORT_LSB_DDR=0xFF
#define LCD_DATAPORT_CLEAR          {LCD_DATAPORT_MSB_PORT->ODR=0x00;LCD_DATAPORT_LSB_PORT->ODR=0x00;}

#define TS_INS_START_OSC             0x00
#define TS_INS_DRIV_OUT_CTRL         0x01
#define TS_INS_DRIV_WAV_CTRL         0x02
#define TS_INS_ENTRY_MOD             0x03
#define TS_INS_RESIZE_CTRL           0x04
#define TS_INS_DISP_CTRL1            0x07
#define TS_INS_DISP_CTRL2            0x08
#define TS_INS_DISP_CTRL3            0x09
#define TS_INS_DISP_CTRL4            0x0A
#define TS_INS_RGB_DISP_IF_CTRL1     0x0C
#define TS_INS_FRM_MARKER_POS        0x0D
#define TS_INS_RGB_DISP_IF_CTRL2     0x0F
#define TS_INS_POW_CTRL1             0x10
#define TS_INS_POW_CTRL2             0x11
#define TS_INS_POW_CTRL3             0x12
#define TS_INS_POW_CTRL4             0x13
#define TS_INS_GRAM_HOR_AD           0x20
#define TS_INS_GRAM_VER_AD           0x21
#define TS_INS_RW_GRAM               0x22
#define TS_INS_POW_CTRL7             0x29
#define TS_INS_FRM_RATE_COL_CTRL     0x2B
#define TS_INS_GAMMA_CTRL1           0x30
#define TS_INS_GAMMA_CTRL2           0x31
#define TS_INS_GAMMA_CTRL3           0x32
#define TS_INS_GAMMA_CTRL4           0x35 
#define TS_INS_GAMMA_CTRL5           0x36
#define TS_INS_GAMMA_CTRL6           0x37
#define TS_INS_GAMMA_CTRL7           0x38
#define TS_INS_GAMMA_CTRL8           0x39
#define TS_INS_GAMMA_CTRL9           0x3C
#define TS_INS_GAMMA_CTRL10          0x3D
#define TS_INS_HOR_START_AD          0x50
#define TS_INS_HOR_END_AD            0x51
#define TS_INS_VER_START_AD          0x52
#define TS_INS_VER_END_AD            0x53
#define TS_INS_GATE_SCAN_CTRL1       0x60
#define TS_INS_GATE_SCAN_CTRL2       0x61
#define TS_INS_GATE_SCAN_CTRL3       0x6A
#define TS_INS_PART_IMG1_DISP_POS    0x80
#define TS_INS_PART_IMG1_START_AD    0x81
#define TS_INS_PART_IMG1_END_AD      0x82
#define TS_INS_PART_IMG2_DISP_POS    0x83
#define TS_INS_PART_IMG2_START_AD    0x84
#define TS_INS_PART_IMG2_END_AD      0x85
#define TS_INS_PANEL_IF_CTRL1        0x90
#define TS_INS_PANEL_IF_CTRL2        0x92
#define TS_INS_PANEL_IF_CTRL3        0x93
#define TS_INS_PANEL_IF_CTRL4        0x95
#define TS_INS_PANEL_IF_CTRL5        0x97
#define TS_INS_PANEL_IF_CTRL6        0x98           


#ifdef LANDSCAPE
#define TS_SIZE_X					320
#define TS_SIZE_Y					240
#define TS_VAL_ENTRY_MOD			0x0028
#define TS_INS_GRAM_ADX				TS_INS_GRAM_VER_AD
#define TS_INS_GRAM_ADY				TS_INS_GRAM_HOR_AD
#define TS_INS_START_ADX   			TS_INS_VER_START_AD
#define TS_INS_END_ADX   			TS_INS_VER_END_AD
#define TS_INS_START_ADY   			TS_INS_HOR_START_AD
#define TS_INS_END_ADY   			TS_INS_HOR_END_AD
#else
#define TS_SIZE_X                    240
#define TS_SIZE_Y                    320
#define TS_VAL_ENTRY_MOD             0x0030
#define TS_INS_GRAM_ADX              TS_INS_GRAM_HOR_AD
#define TS_INS_GRAM_ADY              TS_INS_GRAM_VER_AD
#define TS_INS_START_ADX             TS_INS_HOR_START_AD
#define TS_INS_END_ADX               TS_INS_HOR_END_AD
#define TS_INS_START_ADY             TS_INS_VER_START_AD
#define TS_INS_END_ADY               TS_INS_VER_END_AD
#endif


#define RED                  0x001F
#define GREEN                0x07E0
#define BLUE                 0xF800
#define YELLOW               0x07FF
#define PURPLE               0xF81F
#define BLACK                0x0000
#define WHITE                0xFFFF



unsigned char x_text=0,y_text=0;

const unsigned char font8x16[97][16]= 
{
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // space 0x20
0x00,0x00,0x18,0x3C,0x3C,0x3C,0x18,0x18,0x18,0x00,0x18,0x18,0x00,0x00,0x00,0x00, // !
0x00,0x63,0x63,0x63,0x22,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // "
0x00,0x00,0x00,0x36,0x36,0x7F,0x36,0x36,0x36,0x7F,0x36,0x36,0x00,0x00,0x00,0x00, // #
0x0C,0x0C,0x3E,0x63,0x61,0x60,0x3E,0x03,0x03,0x43,0x63,0x3E,0x0C,0x0C,0x00,0x00, // $
0x00,0x00,0x00,0x00,0x00,0x61,0x63,0x06,0x0C,0x18,0x33,0x63,0x00,0x00,0x00,0x00, // %
0x00,0x00,0x00,0x1C,0x36,0x36,0x1C,0x3B,0x6E,0x66,0x66,0x3B,0x00,0x00,0x00,0x00, // &
0x00,0x30,0x30,0x30,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // '
0x00,0x00,0x0C,0x18,0x18,0x30,0x30,0x30,0x30,0x18,0x18,0x0C,0x00,0x00,0x00,0x00, // (
0x00,0x00,0x18,0x0C,0x0C,0x06,0x06,0x06,0x06,0x0C,0x0C,0x18,0x00,0x00,0x00,0x00, // )
0x00,0x00,0x00,0x00,0x42,0x66,0x3C,0xFF,0x3C,0x66,0x42,0x00,0x00,0x00,0x00,0x00, // *
0x00,0x00,0x00,0x00,0x18,0x18,0x18,0xFF,0x18,0x18,0x18,0x00,0x00,0x00,0x00,0x00, // +
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x18,0x30,0x00,0x00, // ,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // -
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00, // .
0x00,0x00,0x01,0x03,0x07,0x0E,0x1C,0x38,0x70,0xE0,0xC0,0x80,0x00,0x00,0x00,0x00, // / (forward slash)
0x00,0x00,0x3E,0x63,0x63,0x63,0x6B,0x6B,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // 0 0x30
0x00,0x00,0x0C,0x1C,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3F,0x00,0x00,0x00,0x00, // 1
0x00,0x00,0x3E,0x63,0x03,0x06,0x0C,0x18,0x30,0x61,0x63,0x7F,0x00,0x00,0x00,0x00, // 2
0x00,0x00,0x3E,0x63,0x03,0x03,0x1E,0x03,0x03,0x03,0x63,0x3E,0x00,0x00,0x00,0x00, // 3
0x00,0x00,0x06,0x0E,0x1E,0x36,0x66,0x66,0x7F,0x06,0x06,0x0F,0x00,0x00,0x00,0x00, // 4
0x00,0x00,0x7F,0x60,0x60,0x60,0x7E,0x03,0x03,0x63,0x73,0x3E,0x00,0x00,0x00,0x00, // 5
0x00,0x00,0x1C,0x30,0x60,0x60,0x7E,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // 6
0x00,0x00,0x7F,0x63,0x03,0x06,0x06,0x0C,0x0C,0x18,0x18,0x18,0x00,0x00,0x00,0x00, // 7
0x00,0x00,0x3E,0x63,0x63,0x63,0x3E,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // 8
0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x3F,0x03,0x03,0x06,0x3C,0x00,0x00,0x00,0x00, // 9
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00, // :
0x00,0x00,0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x18,0x18,0x18,0x30,0x00,0x00, // ;
0x00,0x00,0x00,0x06,0x0C,0x18,0x30,0x60,0x30,0x18,0x0C,0x06,0x00,0x00,0x00,0x00, // <
0x00,0x00,0x00,0x00,0x00,0x00,0x7E,0x00,0x00,0x7E,0x00,0x00,0x00,0x00,0x00,0x00, // =
0x00,0x00,0x00,0x60,0x30,0x18,0x0C,0x06,0x0C,0x18,0x30,0x60,0x00,0x00,0x00,0x00, // >
0x00,0x00,0x3E,0x63,0x63,0x06,0x0C,0x0C,0x0C,0x00,0x0C,0x0C,0x00,0x00,0x00,0x00, // ?
0x00,0x00,0x3E,0x63,0x63,0x6F,0x6B,0x6B,0x6E,0x60,0x60,0x3E,0x00,0x00,0x00,0x00, // @ 0x40
0x00,0x00,0x08,0x1C,0x36,0x63,0x63,0x63,0x7F,0x63,0x63,0x63,0x00,0x00,0x00,0x00, // A
0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x33,0x33,0x33,0x33,0x7E,0x00,0x00,0x00,0x00, // B
0x00,0x00,0x1E,0x33,0x61,0x60,0x60,0x60,0x60,0x61,0x33,0x1E,0x00,0x00,0x00,0x00, // C
0x00,0x00,0x7C,0x36,0x33,0x33,0x33,0x33,0x33,0x33,0x36,0x7C,0x00,0x00,0x00,0x00, // D
0x00,0x00,0x7F,0x33,0x31,0x34,0x3C,0x34,0x30,0x31,0x33,0x7F,0x00,0x00,0x00,0x00, // E
0x00,0x00,0x7F,0x33,0x31,0x34,0x3C,0x34,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00, // F
0x00,0x00,0x1E,0x33,0x61,0x60,0x60,0x6F,0x63,0x63,0x37,0x1D,0x00,0x00,0x00,0x00, // G
0x00,0x00,0x63,0x63,0x63,0x63,0x7F,0x63,0x63,0x63,0x63,0x63,0x00,0x00,0x00,0x00, // H
0x00,0x00,0x3C,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00, // I
0x00,0x00,0x0F,0x06,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,0x00,0x00,0x00, // J
0x00,0x00,0x73,0x33,0x36,0x36,0x3C,0x36,0x36,0x33,0x33,0x73,0x00,0x00,0x00,0x00, // K
0x00,0x00,0x78,0x30,0x30,0x30,0x30,0x30,0x30,0x31,0x33,0x7F,0x00,0x00,0x00,0x00, // L
0x00,0x00,0x63,0x77,0x7F,0x6B,0x63,0x63,0x63,0x63,0x63,0x63,0x00,0x00,0x00,0x00, // M
0x00,0x00,0x63,0x63,0x73,0x7B,0x7F,0x6F,0x67,0x63,0x63,0x63,0x00,0x00,0x00,0x00, // N
0x00,0x00,0x1C,0x36,0x63,0x63,0x63,0x63,0x63,0x63,0x36,0x1C,0x00,0x00,0x00,0x00, // O
0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x30,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00, // P 0x50
0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x63,0x63,0x6B,0x6F,0x3E,0x06,0x07,0x00,0x00, // Q
0x00,0x00,0x7E,0x33,0x33,0x33,0x3E,0x36,0x36,0x33,0x33,0x73,0x00,0x00,0x00,0x00, // R
0x00,0x00,0x3E,0x63,0x63,0x30,0x1C,0x06,0x03,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // S
0x00,0x00,0xFF,0xDB,0x99,0x18,0x18,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00, // T
0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // U
0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x63,0x63,0x36,0x1C,0x08,0x00,0x00,0x00,0x00, // V
0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x6B,0x6B,0x7F,0x36,0x36,0x00,0x00,0x00,0x00, // W
0x00,0x00,0xC3,0xC3,0x66,0x3C,0x18,0x18,0x3C,0x66,0xC3,0xC3,0x00,0x00,0x00,0x00, // X
0x00,0x00,0xC3,0xC3,0xC3,0x66,0x3C,0x18,0x18,0x18,0x18,0x3C,0x00,0x00,0x00,0x00, // Y
0x00,0x00,0x7F,0x63,0x43,0x06,0x0C,0x18,0x30,0x61,0x63,0x7F,0x00,0x00,0x00,0x00, // Z
0x00,0x00,0x3C,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x30,0x3C,0x00,0x00,0x00,0x00, // [
0x00,0x00,0x80,0xC0,0xE0,0x70,0x38,0x1C,0x0E,0x07,0x03,0x01,0x00,0x00,0x00,0x00, // \ (back slash)
0x00,0x00,0x3C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x3C,0x00,0x00,0x00,0x00, // ]
0x08,0x1C,0x36,0x63,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ^
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x00,0x00, // _
0x18,0x18,0x0C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ` 0x60
0x00,0x00,0x00,0x00,0x00,0x3C,0x46,0x06,0x3E,0x66,0x66,0x3B,0x00,0x00,0x00,0x00, // a
0x00,0x00,0x70,0x30,0x30,0x3C,0x36,0x33,0x33,0x33,0x33,0x6E,0x00,0x00,0x00,0x00, // b
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x60,0x60,0x60,0x63,0x3E,0x00,0x00,0x00,0x00, // c
0x00,0x00,0x0E,0x06,0x06,0x1E,0x36,0x66,0x66,0x66,0x66,0x3B,0x00,0x00,0x00,0x00, // d
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x63,0x7E,0x60,0x63,0x3E,0x00,0x00,0x00,0x00, // e
0x00,0x00,0x1C,0x36,0x32,0x30,0x7C,0x30,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00, // f
0x00,0x00,0x00,0x00,0x00,0x3B,0x66,0x66,0x66,0x66,0x3E,0x06,0x66,0x3C,0x00,0x00, // g
0x00,0x00,0x70,0x30,0x30,0x36,0x3B,0x33,0x33,0x33,0x33,0x73,0x00,0x00,0x00,0x00, // h
0x00,0x00,0x0C,0x0C,0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00,0x00,0x00, // i
0x00,0x00,0x06,0x06,0x00,0x0E,0x06,0x06,0x06,0x06,0x06,0x66,0x66,0x3C,0x00,0x00, // j
0x00,0x00,0x70,0x30,0x30,0x33,0x33,0x36,0x3C,0x36,0x33,0x73,0x00,0x00,0x00,0x00, // k
0x00,0x00,0x1C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x0C,0x1E,0x00,0x00,0x00,0x00, // l
0x00,0x00,0x00,0x00,0x00,0x6E,0x7F,0x6B,0x6B,0x6B,0x6B,0x6B,0x00,0x00,0x00,0x00, // m
0x00,0x00,0x00,0x00,0x00,0x6E,0x33,0x33,0x33,0x33,0x33,0x33,0x00,0x00,0x00,0x00, // n
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x63,0x63,0x63,0x63,0x3E,0x00,0x00,0x00,0x00, // o
0x00,0x00,0x00,0x00,0x00,0x6E,0x33,0x33,0x33,0x33,0x3E,0x30,0x30,0x78,0x00,0x00, // p 0x70
0x00,0x00,0x00,0x00,0x00,0x3B,0x66,0x66,0x66,0x66,0x3E,0x06,0x06,0x0F,0x00,0x00, // q
0x00,0x00,0x00,0x00,0x00,0x6E,0x3B,0x33,0x30,0x30,0x30,0x78,0x00,0x00,0x00,0x00, // r
0x00,0x00,0x00,0x00,0x00,0x3E,0x63,0x38,0x0E,0x03,0x63,0x3E,0x00,0x00,0x00,0x00, // s
0x00,0x00,0x08,0x18,0x18,0x7E,0x18,0x18,0x18,0x18,0x1B,0x0E,0x00,0x00,0x00,0x00, // t
0x00,0x00,0x00,0x00,0x00,0x66,0x66,0x66,0x66,0x66,0x66,0x3B,0x00,0x00,0x00,0x00, // u
0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x36,0x36,0x1C,0x1C,0x08,0x00,0x00,0x00,0x00, // v
0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x63,0x6B,0x6B,0x7F,0x36,0x00,0x00,0x00,0x00, // w
0x00,0x00,0x00,0x00,0x00,0x63,0x36,0x1C,0x1C,0x1C,0x36,0x63,0x00,0x00,0x00,0x00, // x
0x00,0x00,0x00,0x00,0x00,0x63,0x63,0x63,0x63,0x63,0x3F,0x03,0x06,0x3C,0x00,0x00, // y
0x00,0x00,0x00,0x00,0x00,0x7F,0x66,0x0C,0x18,0x30,0x63,0x7F,0x00,0x00,0x00,0x00, // z
0x00,0x00,0x0E,0x18,0x18,0x18,0x70,0x18,0x18,0x18,0x18,0x0E,0x00,0x00,0x00,0x00, // {
0x00,0x00,0x18,0x18,0x18,0x18,0x18,0x00,0x18,0x18,0x18,0x18,0x18,0x00,0x00,0x00, // |
0x00,0x00,0x70,0x18,0x18,0x18,0x0E,0x18,0x18,0x18,0x18,0x70,0x00,0x00,0x00,0x00, // }
0x00,0x00,0x3B,0x6E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00, // ~
0x00,0x70,0xD8,0xD8,0x70,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00  // DEL
};  


//-----------------------------------------------------------------------
	// send a word data to the lcd
//-----------------------------------------------------------------------
void lcd_write_index_register(char ins)
    {
    CS_LOW;
    RS_LOW;
    LCD_DATAPORT_MSB_PORT->ODR=0x00; 
    LCD_DATAPORT_LSB_PORT->ODR=ins;
    WR_LOW; 
    WR_HIGH;
    CS_HIGH;        
    }
	
//-----------------------------------------------------------------------
	// write a word data into the WDR lcd register
//-----------------------------------------------------------------------
void lcd_write_wdr(int data)
    { 
    CS_LOW;
    RS_HIGH;
    LCD_DATAPORT_MSB_PORT->ODR=(data>>8); 
    LCD_DATAPORT_LSB_PORT->ODR=data; 
    WR_LOW;
    WR_HIGH;
    CS_HIGH;           
    }
	
//-----------------------------------------------------------------------
	// read data from rdr lcd register
//-----------------------------------------------------------------------
int lcd_read_rdr(void)
    { 
    int data_lsb,data_msb,rdr_data;  
    LCD_DATAPORT_CLEAR;
    LCD_DATAPORT_INPUT();
    RD_LOW;
	WR_HIGH;
	CS_LOW;
    //RS_HIGH;
    data_lsb=LCD_DATAPORT_LSB_PORT->IDR;
    data_msb=LCD_DATAPORT_MSB_PORT->IDR;
	rdr_data=((data_msb<<8)|data_lsb);
    CS_HIGH;
    RD_HIGH;
	WR_HIGH;
	LCD_DATAPORT_OUTPUT();
    return rdr_data;
    }


//-----------------------------------------------------------------------
	// clears the lcd panel
//-----------------------------------------------------------------------
void lcd_clear_screen(void)
    {  
    unsigned long int counter;
    lcd_write_index_register(TS_INS_GRAM_ADX);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_GRAM_ADY);
    lcd_write_wdr(0);             
    lcd_write_index_register(TS_INS_START_ADX);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_END_ADX);
    #ifdef PORTRAIT
    lcd_write_wdr(239);
    #else
    lcd_write_wdr(319); 
    #endif
    lcd_write_index_register(TS_INS_START_ADY);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_END_ADY);
    #ifdef PORTRAIT
    lcd_write_wdr(319);
    #else
    lcd_write_wdr(239); 
    #endif 
    lcd_write_index_register(TS_INS_RW_GRAM);
    for(counter=0;counter<76800;counter++)
      lcd_write_wdr(0xFFFF); 
    }
//-----------------------------------------------------------------------
	// set background color
//-----------------------------------------------------------------------
void lcd_background_color(int color)
    {  
    unsigned long int counter;
    lcd_write_index_register(TS_INS_GRAM_ADX);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_GRAM_ADY);
    lcd_write_wdr(0);             
    lcd_write_index_register(TS_INS_START_ADX);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_END_ADX);
    #ifdef PORTRAIT
    lcd_write_wdr(239);
    #else
    lcd_write_wdr(319); 
    #endif
    lcd_write_index_register(TS_INS_START_ADY);
    lcd_write_wdr(0);
    lcd_write_index_register(TS_INS_END_ADY);
    #ifdef PORTRAIT
    lcd_write_wdr(319);
    #else
    lcd_write_wdr(239); 
    #endif 
    lcd_write_index_register(TS_INS_RW_GRAM);
    for(counter=0;counter<76800;counter++)
      lcd_write_wdr(color); 
    }
	
//-----------------------------------------------------------------------	
	// lcd initialization
//-----------------------------------------------------------------------	
void lcd_init(void)
    { 
    LCD_DATAPORT_OUTPUT();
    LCD_CONTROLPORT_PORT->ODR|=(1<<LCD_RST_PIN)|(1<<LCD_RS_PIN)|(1<<LCD_CS_PIN)|(1<<LCD_RD_PIN)|(1<<LCD_WR_PIN);
    LCD_CONTROLPORT_PORT_OUTPUT();
    
          
    // reset lcd chipset
    RST_LOW;
    HAL_Delay(1);       
    RST_HIGH;          
    
    lcd_write_index_register(0x00E3);
    lcd_write_wdr(0x3008);                     //set the internal timing
    lcd_write_index_register(0x00E7);
    lcd_write_wdr(0x0012);                     //set the internal timing
    lcd_write_index_register(0x00EF);
    lcd_write_wdr(0x1231);                     //set the internal timing
    lcd_write_index_register(TS_INS_START_OSC);
    lcd_write_wdr(0x0001);                     //start oscillator
    HAL_Delay(50);

    lcd_write_index_register(TS_INS_DRIV_OUT_CTRL);
    lcd_write_wdr(0x0100);                     //set SS, SM
    lcd_write_index_register(TS_INS_DRIV_WAV_CTRL);
    lcd_write_wdr(0x0700);                     //set 1 line inversion
    
    lcd_write_index_register(TS_INS_ENTRY_MOD);
    lcd_write_wdr(TS_VAL_ENTRY_MOD);            //set GRAM write direction, BGR=0

    lcd_write_index_register(TS_INS_RESIZE_CTRL);
    lcd_write_wdr(0x0000);                     //no resizing

    lcd_write_index_register(TS_INS_DISP_CTRL2);
    lcd_write_wdr(0x0202);                     //front & back porch periods = 2
    lcd_write_index_register(TS_INS_DISP_CTRL3);
    lcd_write_wdr(0x0000);                     
    lcd_write_index_register(TS_INS_DISP_CTRL4);
    lcd_write_wdr(0x0000);                     
    lcd_write_index_register(TS_INS_RGB_DISP_IF_CTRL1);
    lcd_write_wdr(0x0000);                     //select system interface                
    lcd_write_index_register(TS_INS_FRM_MARKER_POS);
    lcd_write_wdr(0x0000);                     
    lcd_write_index_register(TS_INS_RGB_DISP_IF_CTRL2);
    lcd_write_wdr(0x0000);                    
    
    lcd_write_index_register(TS_INS_POW_CTRL1);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_POW_CTRL2);
    lcd_write_wdr(0x0007);                     
    lcd_write_index_register(TS_INS_POW_CTRL3);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_POW_CTRL4);
    lcd_write_wdr(0x0000);                     
    HAL_Delay(200);

    lcd_write_index_register(TS_INS_POW_CTRL1);
    lcd_write_wdr(0x1690);
    lcd_write_index_register(TS_INS_POW_CTRL2);
    lcd_write_wdr(0x0007); //lcd_write_wdr(0x0137);                     
    HAL_Delay(50);

    lcd_write_index_register(TS_INS_POW_CTRL3);
    lcd_write_wdr(0x001A); //lcd_write_wdr(0x013C);
    HAL_Delay(50);

    lcd_write_index_register(TS_INS_POW_CTRL4);
    lcd_write_wdr(0x1800); //lcd_write_wdr(0x1400);
    lcd_write_index_register(TS_INS_POW_CTRL7);
    lcd_write_wdr(0x002A); //lcd_write_wdr(0x0007);
    HAL_Delay(50);

    lcd_write_index_register(TS_INS_GRAM_HOR_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GRAM_VER_AD);
    lcd_write_wdr(0x0000);

    lcd_write_index_register(TS_INS_GAMMA_CTRL1);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GAMMA_CTRL2);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GAMMA_CTRL3);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GAMMA_CTRL4);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GAMMA_CTRL5);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_GAMMA_CTRL6);
    lcd_write_wdr(0x0406);
    lcd_write_index_register(TS_INS_GAMMA_CTRL7);
    lcd_write_wdr(0x0006);
    lcd_write_index_register(TS_INS_GAMMA_CTRL8);
    lcd_write_wdr(0x0404);
    lcd_write_index_register(TS_INS_GAMMA_CTRL9);
    lcd_write_wdr(0x0700);
    lcd_write_index_register(TS_INS_GAMMA_CTRL10);
    lcd_write_wdr(0x0A08);

    lcd_write_index_register(TS_INS_HOR_START_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_HOR_END_AD);
    lcd_write_wdr(0x00EF);
    lcd_write_index_register(TS_INS_VER_START_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_VER_END_AD);
    lcd_write_wdr(0x013F);
    lcd_write_index_register(TS_INS_GATE_SCAN_CTRL1);
    lcd_write_wdr(0xA700);
    lcd_write_index_register(TS_INS_GATE_SCAN_CTRL2);
    lcd_write_wdr(0x0001);
    lcd_write_index_register(TS_INS_GATE_SCAN_CTRL3);
    lcd_write_wdr(0x0000);

    lcd_write_index_register(TS_INS_PART_IMG1_DISP_POS);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PART_IMG1_START_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PART_IMG1_END_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PART_IMG2_DISP_POS);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PART_IMG2_START_AD);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PART_IMG2_END_AD);
    lcd_write_wdr(0x0000);

    lcd_write_index_register(TS_INS_PANEL_IF_CTRL1);
    lcd_write_wdr(0x0010);
    lcd_write_index_register(TS_INS_PANEL_IF_CTRL2);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PANEL_IF_CTRL3);
    lcd_write_wdr(0x0003);
    lcd_write_index_register(TS_INS_PANEL_IF_CTRL4);
    lcd_write_wdr(0x0110);
    lcd_write_index_register(TS_INS_PANEL_IF_CTRL5);
    lcd_write_wdr(0x0000);
    lcd_write_index_register(TS_INS_PANEL_IF_CTRL6);
    lcd_write_wdr(0x0000);

    lcd_write_index_register(TS_INS_DISP_CTRL1);
    lcd_write_wdr(0x0133);
    
    lcd_write_index_register(TS_INS_FRM_RATE_COL_CTRL);
    lcd_write_wdr(0x000D);
    
    lcd_clear_screen();
    }
	
//-----------------------------------------------------------------------
	// turn on a pixel on the lcd screen
//-----------------------------------------------------------------------
void lcd_write_pixel(unsigned int x,unsigned int y,int color)
    { 
    #ifdef LANDSCAPE
    y=239-y;
    #endif
    lcd_write_index_register(TS_INS_GRAM_ADX);
    lcd_write_wdr(x); 
    lcd_write_index_register(TS_INS_GRAM_ADY);
    lcd_write_wdr(y);
    lcd_write_index_register(TS_INS_START_ADX);
    lcd_write_wdr(x);
    lcd_write_index_register(TS_INS_END_ADX);
    lcd_write_wdr(x); 
    lcd_write_index_register(TS_INS_START_ADY);
    lcd_write_wdr(y);
    lcd_write_index_register(TS_INS_END_ADY);
    lcd_write_wdr(y); 
    lcd_write_index_register(TS_INS_RW_GRAM);
    lcd_write_wdr(color);
    }
//-----------------------------------------------------------------------
	// Read A Pixel Color On The LCD Screen
//-----------------------------------------------------------------------
int lcd_read_pixel(int x,int y)
    { 
		int pixel;
    #ifdef LANDSCAPE
    y=239-y;
    #endif
    lcd_write_index_register(TS_INS_GRAM_ADX);
    lcd_write_wdr(x); 
    lcd_write_index_register(TS_INS_GRAM_ADY);
    lcd_write_wdr(y);
    lcd_write_index_register(TS_INS_START_ADX);
    lcd_write_wdr(x);
    lcd_write_index_register(TS_INS_END_ADX);
    lcd_write_wdr(x); 
    lcd_write_index_register(TS_INS_START_ADY);
    lcd_write_wdr(y);
    lcd_write_index_register(TS_INS_END_ADY);
    lcd_write_wdr(y); 
    lcd_write_index_register(TS_INS_RW_GRAM);
	pixel=lcd_read_rdr();
    return pixel;
    }

//-----------------------------------------------------------------------
	// draw a line with x0,y0 and x1,y1 coordinates
//-----------------------------------------------------------------------	
void lcd_draw_line(int x0,int y0,int x1,int y1,int color) 
    {
    int dy=y1-y0;
    int dx=x1-x0;
    int stepx,stepy;
    if(dy<0) {dy=-dy;stepy=-1;} else {stepy=1;}
    if(dx<0) {dx=-dx;stepx=-1;} else {stepx=1;}
    dy<<=1; 
    dx<<=1; 
    lcd_write_pixel(x0,y0,color);
    if(dx>dy) 
      {
      int fraction=dy-(dx>>1); 
      while(x0!=x1) 
        {
        if(fraction>=0) 
          {
          y0+=stepy;
          fraction-=dx; 
          }
        x0+=stepx;
        fraction+=dy; 
        lcd_write_pixel(x0,y0,color);
        }
      } 
    else 
      {
      int fraction=dx-(dy>>1);
      while (y0 != y1) 
        {
        if(fraction>=0) 
          {
          x0+=stepx;
          fraction-=dy;
          }
        y0+=stepy;
        fraction+=dx;
        lcd_write_pixel(x0,y0,color);
        }
      }
    }
//-----------------------------------------------------------------------
	// draw a fill(1) or no fill(0) rectangular with specified color    
//-----------------------------------------------------------------------	

void lcd_draw_rectangle(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1,char fill,int color)
    { 
    if(fill)
      {
      unsigned int counter_x; 
      unsigned char counter_y; 
      
      lcd_write_index_register(TS_INS_GRAM_ADX);
      lcd_write_wdr(x0);
      lcd_write_index_register(TS_INS_GRAM_ADY);
      lcd_write_wdr(y0);  
      lcd_write_index_register(TS_INS_START_ADX);
      lcd_write_wdr(x0);
      lcd_write_index_register(TS_INS_END_ADX);
      lcd_write_wdr(x1);
      #ifdef PORTRAIT
      lcd_write_index_register(TS_INS_START_ADY);
      lcd_write_wdr(y0);
      lcd_write_index_register(TS_INS_END_ADY);
      lcd_write_wdr(y1); 
      #else
      lcd_write_index_register(TS_INS_START_ADY);
      lcd_write_wdr(239-y1);
      lcd_write_index_register(TS_INS_END_ADY);
      lcd_write_wdr(239-y0);
      #endif  
      lcd_write_index_register(TS_INS_RW_GRAM);
      for(counter_y=y0;counter_y<=y1;counter_y++)
        {
        for(counter_x=x0;counter_x<=x1;counter_x++)
          lcd_write_wdr(color);
        }  
      } 
    else
      {
      lcd_draw_line(x0,y0,x1,y0,color);
      lcd_draw_line(x1,y0,x1,y1,color);
      lcd_draw_line(x1,y1,x0,y1,color); 
      lcd_draw_line(x0,y1,x0,y0,color);
      }
    }
  
void lcd_draw_rectangle2(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1,int color)
{ 
//    if(fill)
//      {
//      unsigned int counter_x; 
//      unsigned char counter_y; 
      
/*      lcd_write_index_register(TS_INS_GRAM_ADX);
      lcd_write_wdr(x0);
      lcd_write_index_register(TS_INS_GRAM_ADY);
      lcd_write_wdr(y0);  
      lcd_write_index_register(TS_INS_START_ADX);
      lcd_write_wdr(x0);
      lcd_write_index_register(TS_INS_END_ADX);
      lcd_write_wdr(x1);
      #ifdef PORTRAIT
      lcd_write_index_register(TS_INS_START_ADY);
      lcd_write_wdr(y0);
      lcd_write_index_register(TS_INS_END_ADY);
      lcd_write_wdr(y1); 
      #else
      lcd_write_index_register(TS_INS_START_ADY);
      lcd_write_wdr(239-y1);
      lcd_write_index_register(TS_INS_END_ADY);
      lcd_write_wdr(239-y0);
      #endif  
      lcd_write_index_register(TS_INS_RW_GRAM);
      for(counter_y=y0;counter_y<=y1;counter_y++)
        {
        for(counter_x=x0;counter_x<=x1;counter_x++)
          lcd_write_wdr(color);
        }  
      } 
    else
      {*/
      lcd_draw_line(x0,y0,x1,y0,color);
      lcd_draw_line(x1,y0,x1,y1,color);
      lcd_draw_line(x1,y1,x0,y1,color); 
      lcd_draw_line(x0,y1,x0,y0,color);
//      }
}
//-----------------------------------------------------------------------
	// draw a fill(1) or no fill(0) circle with specified color 
//-----------------------------------------------------------------------	
void lcd_draw_circle(unsigned int x0,unsigned int y0,unsigned int radius,char fill,int color) 
    { 
    int x_offset,y_offset,error; 
    x_offset=0; 
    y_offset=radius; 
    error=1-radius; 

    do 
      { 
      if(fill) 
        { 
        lcd_draw_line(x0-x_offset,y0+y_offset,x0+x_offset,y0+y_offset,color); 
        lcd_draw_line(x0-x_offset,y0-y_offset,x0+x_offset,y0-y_offset,color); 
        lcd_draw_line(x0-y_offset,y0+x_offset,x0+y_offset,y0+x_offset,color); 
        lcd_draw_line(x0-y_offset,y0-x_offset,x0+y_offset,y0-x_offset,color); 
        } 
      else 
        { 
        lcd_write_pixel(x_offset+x0,y_offset+y0,color); 
        lcd_write_pixel(y_offset+x0,x_offset+y0,color); 
        lcd_write_pixel(x0-x_offset,y_offset+y0,color); 
        lcd_write_pixel(x0-y_offset,x_offset+y0,color); 
        lcd_write_pixel(y_offset+x0,y0-x_offset,color); 
        lcd_write_pixel(x_offset+x0,y0-y_offset,color); 
        lcd_write_pixel(x0-x_offset,y0-y_offset,color); 
        lcd_write_pixel(x0-y_offset,y0-x_offset,color); 
        } 

      if(error<0) 
        error+=(3+(2*(x_offset++))); 
      else 
        error+=(5+(2*((x_offset++)-(y_offset--)))); 
      }while(x_offset<=y_offset); 
    } 

//-----------------------------------------------------------------------
	// Show A Picture On The LCD Screen
//-----------------------------------------------------------------------
void lcd_write_pic(unsigned int x,unsigned int y,const unsigned int *pointer)
     {
     unsigned long int counter,compare_value=(unsigned long int)pointer[0]*pointer[1];
     lcd_write_index_register(TS_INS_GRAM_ADX);
     lcd_write_wdr(x); 
     lcd_write_index_register(TS_INS_START_ADX);
     lcd_write_wdr(x);
     lcd_write_index_register(TS_INS_END_ADX);
     lcd_write_wdr(x+pointer[0]-1);   
     #ifdef PORTRAIT
     lcd_write_index_register(TS_INS_GRAM_ADY);
     lcd_write_wdr(y);
     lcd_write_index_register(TS_INS_START_ADY);
     lcd_write_wdr(y);
     lcd_write_index_register(TS_INS_END_ADY);
     lcd_write_wdr(y+pointer[1]-1);
     #else     
     lcd_write_index_register(TS_INS_GRAM_ADY);
     lcd_write_wdr(239-y);
     lcd_write_index_register(TS_INS_START_ADY);
     lcd_write_wdr(239-(y+pointer[1]));
     lcd_write_index_register(TS_INS_END_ADY);
     lcd_write_wdr(239-y);
     #endif 
     lcd_write_index_register(TS_INS_RW_GRAM);  
     for(counter=0,pointer+=2;counter<compare_value;counter++,pointer++)
       lcd_write_wdr(*pointer);
     }

//-----------------------------------------------------------------------	 
	// This Functions Goes The Cursor To X And Y Positions
//-----------------------------------------------------------------------	 
void lcd_gotoxy(unsigned char x,unsigned char y)
    {
    if(x>40 || y>15) 
        {
        y+=x/40;
        x%=40;
        }
    x_text=x;
    y_text=y;
    }
	
//-----------------------------------------------------------------------	
	// Puts A Character On The LCD Screen
//-----------------------------------------------------------------------	
void lcd_putchar(char character,int forground_color,char background_color_activation,int background_color)
    {  
    int temporary_color;
    unsigned char width_counter,length_counter;
    char character_segment_data;
    for(length_counter=0;length_counter<16;length_counter++)
        {
        character_segment_data=font8x16[character-0x20][length_counter];
        for(width_counter=0;width_counter<8;width_counter++)
            {
            if(character_segment_data&(128>>width_counter)) 
              lcd_write_pixel(((int)x_text*8)+width_counter,((int)y_text*16)+length_counter,forground_color);
            else 
              {
              if(background_color_activation)
                {
                temporary_color=lcd_read_rdr();
                temporary_color=lcd_read_rdr();
                lcd_write_wdr(temporary_color);
                } 
              else
                lcd_write_pixel(((int)x_text*8)+width_counter,((int)y_text*16)+length_counter,background_color);
              }            
            }
        }
    
    if(++x_text>40)
        {            
        x_text=0;
        if(++y_text>15) y_text=0;
        }
    } 

//-----------------------------------------------------------------------	
	// Show A String That Stored In The Flash Memory Of The Microcontroller  
//-----------------------------------------------------------------------	
void lcd_putsf(const char *string,int forground_color,char background_color_activation,int background_color)
    {
    while(*string)
      lcd_putchar(*string++,forground_color,background_color_activation,background_color);
    }
//-----------------------------------------------------------------------	
	// Show A String That Stored In The SRAM Of The Microcontroller    
//-----------------------------------------------------------------------	
void lcd_puts(char *string,int forground_color,char background_color_activation,int background_color)
    {
    while(*string)
      lcd_putchar(*string++,forground_color,background_color_activation,background_color);
    }

#endif