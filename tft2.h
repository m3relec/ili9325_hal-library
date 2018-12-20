/*
                           ....::::: In The Name Of GOD :::::....

    TFT LCD (ILI9325-ILI9320 LCD Driver) Functions
    By Ali Imanifar   Shahrood University of Technology    1389/06/16   
            PORTED FROM AVR TO STM32 BY MASOUD REZAPOUR
*/
 
#ifndef _TFT2_H_
	#define _TFT2_H_

#include "stm32f1xx_hal.h"
#include "Graphic.h"


 #define PORTRAIT   1


 #define LCD_CONTROLPORT_PORT  GPIOB

 #define LCD_RST_PIN  10
 
 #define LCD_RS_PIN  8

 #define LCD_CS_PIN  9
 
 #define LCD_RD_PIN  6
  
 #define LCD_WR_PIN  7
 
 #define LCD_DATAPORT_MSB_PORT  GPIOA   //D10-D17 >>>> PA0-PA7
 
 #define LCD_DATAPORT_LSB_PORT  GPIOC   //D1-D8 >>>> PC0-PC7




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


//#define RED                  0x001F
//#define GREEN                0x07E0
//#define BLUE                 0xF800
//#define YELLOW               0x07FF
//#define PURPLE               0xF81F
//#define BLACK                0x0000
//#define WHITE                0xFFFF



void LCD_DATAPORT_INPUT (void);

void LCD_DATAPORT_OUTPUT (void); 

void LCD_CONTROLPORT_PORT_OUTPUT(void);
//-----------------------------------------------------------------------
	// send a word data to the lcd
//-----------------------------------------------------------------------
void lcd_write_index_register(char ins);
	
//-----------------------------------------------------------------------
	// write a word data into the WDR lcd register
//-----------------------------------------------------------------------
void lcd_write_wdr(int data);
	
//-----------------------------------------------------------------------
	// read data from rdr lcd register
//-----------------------------------------------------------------------
int lcd_read_rdr(void);


//-----------------------------------------------------------------------
	// clears the lcd panel
//-----------------------------------------------------------------------
void lcd_clear_screen(void);
//-----------------------------------------------------------------------
	// set background color
//-----------------------------------------------------------------------
void lcd_background_color(int color);
	
//-----------------------------------------------------------------------	
	// lcd initialization
//-----------------------------------------------------------------------	
void lcd_init(void);
	
//-----------------------------------------------------------------------
	// turn on a pixel on the lcd screen
//-----------------------------------------------------------------------
void lcd_write_pixel(unsigned int x,unsigned int y,int color);
//-----------------------------------------------------------------------
	// Read A Pixel Color On The LCD Screen
//-----------------------------------------------------------------------
int lcd_read_pixel(int x,int y);

//-----------------------------------------------------------------------
	// draw a line with x0,y0 and x1,y1 coordinates
//-----------------------------------------------------------------------	
void lcd_draw_line(int x0,int y0,int x1,int y1,int color) ;
//-----------------------------------------------------------------------
	// draw a fill(1) or no fill(0) rectangular with specified color    
//-----------------------------------------------------------------------	

void lcd_draw_rectangle2(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1,char fill,int color);
  
void lcd_draw_rectangle(unsigned int x0,unsigned int y0,unsigned int x1,unsigned int y1,int color);
//-----------------------------------------------------------------------
	// draw a fill(1) or no fill(0) circle with specified color 
//-----------------------------------------------------------------------	
void lcd_draw_circle(unsigned int x0,unsigned int y0,unsigned int radius,char fill,int color) ;
//-----------------------------------------------------------------------
	// Show A Picture On The LCD Screen
//-----------------------------------------------------------------------
void lcd_write_pic(unsigned int x,unsigned int y,const unsigned int *pointer);

//-----------------------------------------------------------------------	 
	// This Functions Goes The Cursor To X And Y Positions
//-----------------------------------------------------------------------	 
void lcd_gotoxy(unsigned char x,unsigned char y);
//-----------------------------------------------------------------------	
	// Puts A Character On The LCD Screen
//-----------------------------------------------------------------------	
void lcd_putchar(char character,int forground_color,char background_color_activation,int background_color);

//-----------------------------------------------------------------------	
	// Show A String That Stored In The Flash Memory Of The Microcontroller  
//-----------------------------------------------------------------------	
void lcd_putsf(const char *string,int forground_color,char background_color_activation,int background_color);
//-----------------------------------------------------------------------	
	// Show A String That Stored In The SRAM Of The Microcontroller    
//-----------------------------------------------------------------------	
void lcd_puts(char *string,int forground_color,char background_color_activation,int background_color);

#endif

