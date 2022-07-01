#ifndef __gfx_h_
#define __gfx_h_

#include <stdint.h>


void gfx_init(int16_t bitmap_width, int16_t bitmap_height,
              uint8_t *bitmap_buffer);
void gfx_fill(uint8_t fill_value);
void gfx_pixel(int16_t x, int16_t y, uint8_t color);
void gfx_line(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color);
void gfx_rect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color);
void gfx_f_rect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color);
void gfx_circle(int16_t x0, int16_t y0, int16_t r, uint8_t color);
void gfx_f_circle(int16_t x0, int16_t y0, int16_t r, uint8_t color);
void gfx_char(int16_t x, int16_t line, char c);
void gfx_string(int16_t x, int16_t line, char *c);

#endif
