#include "stdio.h"
#include "stm32g0xx_ll_gpio.h"

#define CMD_DISPLAY_OFF         0xAE
#define CMD_DISPLAY_ON          0xAF
#define CMD_SET_DISP_START_LINE 0x40
#define CMD_SET_PAGE            0xB0
#define CMD_SET_COLUMN_UPPER    0x10
#define CMD_SET_COLUMN_LOWER    0x00
#define CMD_SET_ADC_NORMAL      0xA0
#define CMD_SET_ADC_REVERSE     0xA1
#define CMD_SET_DISP_NORMAL     0xA6
#define CMD_SET_DISP_REVERSE    0xA7
#define CMD_SET_ALLPTS_NORMAL   0xA4
#define CMD_SET_ALLPTS_ON       0xA5
#define CMD_SET_BIAS_9          0xA2
#define CMD_SET_BIAS_7          0xA3
#define CMD_RMW                 0xE0
#define CMD_RMW_CLEAR           0xEE
#define CMD_INTERNAL_RESET      0xE2
#define CMD_SET_COM_NORMAL      0xC0
#define CMD_SET_COM_REVERSE     0xC8
#define CMD_SET_POWER_CONTROL   0x28
#define CMD_SET_RESISTOR_RATIO  0x20
#define CMD_SET_VOLUME_FIRST    0x81
#define CMD_SET_VOLUME_SECOND   0
#define CMD_SET_STATIC_OFF      0xAC
#define CMD_SET_STATIC_ON       0xAD
#define CMD_SET_STATIC_REG      0x0
#define CMD_SET_BOOSTER_FIRST   0xF8
#define CMD_SET_BOOSTER_234     0
#define CMD_SET_BOOSTER_5       1
#define CMD_SET_BOOSTER_6       3
#define CMD_NOP                 0xE3
#define CMD_TEST                0xF0

#define LCDWIDTH  128
#define LCDHEIGHT 64

#define ST7565_STARTBYTES 0

#define DELAY_US 2

typedef struct {
  uint32_t rd_pin;
  uint32_t wr_pin;
  uint32_t a0_pin;
  uint32_t reset_pin;
  uint32_t cs1_pin;
  GPIO_TypeDef* lcd_port;
  uint32_t data_pins[8];
  uint8_t buffer[1024];
  uint8_t is_inversed;

} st7565_lcd_dev_t;

void st7565_init(st7565_lcd_dev_t* lcd);
void st7565_set_brightness(st7565_lcd_dev_t* lcd, uint8_t val);
void st7565_set_pixel(st7565_lcd_dev_t* lcd, uint8_t x_pos, uint8_t y_pos,uint8_t color);
void st7565_refresh(st7565_lcd_dev_t* lcd);
void st7565_set_brightness(st7565_lcd_dev_t* lcd, uint8_t val);
