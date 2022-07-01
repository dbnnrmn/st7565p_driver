#include "st7565.h"

#include "stm32g0xx_ll_gpio.h"
#include "stm32g0xx_ll_tim.h"
#include "stm32g0xx_ll_utils.h"
#include "string.h"
#include "us_delay.h"


static void st7565_write(st7565_lcd_dev_t *lcd, uint8_t data) {
  LL_GPIO_ResetOutputPin(lcd->lcd_port, lcd->cs1_pin);
  delay_us(DELAY_US);

  LL_GPIO_ResetOutputPin(lcd->lcd_port, lcd->wr_pin);
  delay_us(DELAY_US);

  for (uint8_t i = 0; i < 8; i++) {
    if ((data >> i) & 0x01)
      LL_GPIO_SetOutputPin(lcd->lcd_port, lcd->data_pins[i]);
    else
      LL_GPIO_ResetOutputPin(lcd->lcd_port, lcd->data_pins[i]);
  }
  delay_us(DELAY_US);

  LL_GPIO_SetOutputPin(lcd->lcd_port, lcd->wr_pin);
  delay_us(DELAY_US);
  LL_GPIO_SetOutputPin(lcd->lcd_port, lcd->cs1_pin);
  delay_us(DELAY_US);
}

static void st7565_send_command(st7565_lcd_dev_t *lcd, uint8_t command) {
  LL_GPIO_ResetOutputPin(lcd->lcd_port, lcd->a0_pin);
  delay_us(DELAY_US);
  st7565_write(lcd, command);
}

static void st7565_send_data(st7565_lcd_dev_t *lcd, uint8_t data) {
  LL_GPIO_SetOutputPin(lcd->lcd_port, lcd->a0_pin);
  delay_us(DELAY_US);
  st7565_write(lcd, data);
}

void st7565_init(st7565_lcd_dev_t *lcd) {
  switch ((uint32_t)lcd->lcd_port) {
    case GPIOA_BASE:
      LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
      break;
    case GPIOB_BASE:
      LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOB);
      break;
    case GPIOC_BASE:
      LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOC);
      break;
    case GPIOD_BASE:
      LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOD);
    default:
      break;
  }

  LL_GPIO_InitTypeDef tmp = {
      .Pin = lcd->rd_pin | lcd->wr_pin | lcd->a0_pin | lcd->reset_pin |
             lcd->cs1_pin | lcd->data_pins[0] | lcd->data_pins[1] |
             lcd->data_pins[2] | lcd->data_pins[3] | lcd->data_pins[4] |
             lcd->data_pins[5] | lcd->data_pins[6] | lcd->data_pins[7],
      .Mode = LL_GPIO_MODE_OUTPUT,
      .Speed = LL_GPIO_SPEED_FAST,
      .OutputType = LL_GPIO_OUTPUT_PUSHPULL,
      .Pull = LL_GPIO_PULL_NO,
      .Alternate = 0};

  LL_GPIO_Init(lcd->lcd_port, &tmp);

  delay_us_init();

  LL_GPIO_SetOutputPin(lcd->lcd_port, lcd->cs1_pin);

  LL_GPIO_ResetOutputPin(lcd->lcd_port, lcd->reset_pin);
  LL_mDelay(100);

  LL_GPIO_SetOutputPin(lcd->lcd_port, lcd->reset_pin);
  LL_GPIO_SetOutputPin(lcd->lcd_port, lcd->rd_pin);

  LL_GPIO_ResetOutputPin(lcd->lcd_port, lcd->wr_pin);

  st7565_send_command(lcd, CMD_SET_BIAS_7);
  st7565_send_command(lcd, CMD_SET_ADC_NORMAL);
  st7565_send_command(lcd, CMD_SET_COM_NORMAL);
  st7565_send_command(lcd, CMD_SET_DISP_START_LINE);
  st7565_send_command(lcd, CMD_SET_BOOSTER_FIRST | CMD_SET_BOOSTER_234);

  st7565_send_command(lcd, CMD_SET_POWER_CONTROL | 0x4);
  LL_mDelay(5);
  st7565_send_command(lcd, CMD_SET_POWER_CONTROL | 0x6);
  LL_mDelay(5);
  st7565_send_command(lcd, CMD_SET_POWER_CONTROL | 0x7);
  LL_mDelay(5);
  st7565_send_command(lcd, CMD_SET_RESISTOR_RATIO | 0x3);

  LL_mDelay(1);

  if (lcd->is_inversed) st7565_send_command(lcd, CMD_SET_DISP_REVERSE);

  memset(lcd->buffer, 0, sizeof(lcd->buffer));

  st7565_set_brightness(lcd, 35);

  st7565_send_command(lcd, CMD_DISPLAY_ON);
};

void st7565_set_brightness(st7565_lcd_dev_t *lcd, uint8_t val) {
  st7565_send_command(lcd, CMD_SET_VOLUME_FIRST);
  st7565_send_command(lcd, CMD_SET_VOLUME_SECOND | (val & 0x3f));
};

void st7565_set_pixel(st7565_lcd_dev_t *lcd, uint8_t x, uint8_t y,
                      uint8_t color) {
  if ((x >= LCDWIDTH) || (y >= LCDHEIGHT)) return;
  if (color)
    lcd->buffer[x + (y / 8) * 128] |= 1 << (7 - (y % 8));
  else
    lcd->buffer[x + (y / 8) * 128] &= ~(1 << (7 - (y % 8)));
};

void st7565_refresh(st7565_lcd_dev_t *lcd) {
  uint8_t col, maxcol, p;

  for (p = 0; p < 8; p++) {
    st7565_send_command(lcd, CMD_SET_PAGE | (7 - p));
    col = 0;
    maxcol = LCDWIDTH - 1;
    st7565_send_command(
        lcd, CMD_SET_COLUMN_LOWER | ((col + ST7565_STARTBYTES) & 0x0F));
    st7565_send_command(
        lcd, CMD_SET_COLUMN_UPPER | (((col + ST7565_STARTBYTES) >> 4) & 0x0F));
    st7565_send_command(lcd, CMD_RMW);
    for (; col <= maxcol; col++)
      st7565_send_data(lcd, lcd->buffer[(128 * p) + col]);
  }
}
