
#include "gfx.h"

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#define SWAP(a, b) \
  {                \
    uint8_t t = a; \
    a = b;         \
    b = t;         \
  }

static int16_t bmap_width = 0;
static int16_t bmap_height = 0;
static uint8_t *bmap;
static int16_t bmap_size;

extern uint8_t font[];
extern uint8_t my_font[];
extern uint8_t my_font_ru[];

void gfx_init(int16_t width, int16_t height, uint8_t *_bmap) {
  bmap_width = width;
  bmap_height = height;
  bmap = _bmap;
  bmap_size = width * height / 8;

  gfx_fill(0);
}

void gfx_fill(uint8_t fill_value) { memset(bmap, fill_value, bmap_size); }

void gfx_pixel(int16_t x, int16_t y, uint8_t color) {
  int16_t byte_idx;
  uint8_t bit_mask;

  if (x < 0 || x >= bmap_width) return;
  if (y < 0 || y >= bmap_height) return;

  byte_idx = y / 8 * bmap_width + x;
  bit_mask = 0x80 >> (y & 7);

  if (color)
    bmap[byte_idx] |= bit_mask;
  else
    bmap[byte_idx] &= ~bit_mask;
}

void gfx_char(int16_t x, int16_t line, char c) {
  int16_t i, bmap_idx, font_idx;

  bmap_idx = (int16_t)line * bmap_width + x;

  if ((int16_t)c >= 192) {
    font_idx = (int16_t)c * 6 - 192 * 6;
    for (i = 0; i < 6; i++) { bmap[bmap_idx++] = my_font_ru[font_idx++]; }
  } else {
    font_idx = (int16_t)c * 6 - 32 * 6;
    for (i = 0; i < 6; i++) { bmap[bmap_idx++] = my_font[font_idx++]; }
  }
}

void gfx_string(int16_t x, int16_t line, char *c) {
  while (*c) {
    gfx_char(x, line, *c++);
    x += 6;
    if (x + 6 >= bmap_width) {
      x = 0;
      line++;
    }
    if (line >= (bmap_height / 8)) return;
  }
}

void gfx_line(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color) {
  int16_t dx, dy;
  char steep;

  steep = abs(y1 - y0) > abs(x1 - x0);

  if (steep) {
    SWAP(x0, y0);
    SWAP(x1, y1);
  }

  if (x0 > x1) {
    SWAP(x0, x1);
    SWAP(y0, y1);
  }

  dx = x1 - x0;
  dy = abs(y1 - y0);

  int16_t err = dx / 2;
  int8_t ystep;

  if (y0 < y1) {
    ystep = 1;
  } else {
    ystep = -1;
  }

  while (x0 < x1) {
    if (steep) {
      gfx_pixel(y0, x0, color);
    } else {
      gfx_pixel(x0, y0, color);
    }
    err -= dy;
    if (err < 0) {
      y0 += ystep;
      err += dx;
    }
    x0++;
  }
}

void gfx_rect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color) {
  gfx_line(x0, y0, x1, y0, color);
  gfx_line(x0, y1, x1, y1, color);
  gfx_line(x0, y0, x0, y1, color);

  gfx_line(x1, y0, x1, y1 + 1, color);
}

void gfx_f_rect(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint8_t color) {
  int16_t i, j;

  for (i = x0; i <= x1; i++) {
    for (j = y0; j <= y1; j++) { gfx_pixel(i, j, color); }
  }
}

void gfx_circle(int16_t x0, int16_t y0, int16_t r, uint8_t color) {
  int8_t f = 1 - r;
  int8_t dd_f_x = 1;
  int8_t dd_f_y = -2 * r;
  int8_t x = 0;
  int8_t y = r;

  gfx_pixel(x0, y0 + r, color);
  gfx_pixel(x0, y0 - r, color);
  gfx_pixel(x0 + r, y0, color);
  gfx_pixel(x0 - r, y0, color);

  while (x < y) {
    if (f >= 0) {
      y--;
      dd_f_y += 2;
      f += dd_f_y;
    }
    x++;
    dd_f_x += 2;
    f += dd_f_x;

    gfx_pixel(x0 + x, y0 + y, color);
    gfx_pixel(x0 - x, y0 + y, color);
    gfx_pixel(x0 + x, y0 - y, color);
    gfx_pixel(x0 - x, y0 - y, color);

    gfx_pixel(x0 + y, y0 + x, color);
    gfx_pixel(x0 - y, y0 + x, color);
    gfx_pixel(x0 + y, y0 - x, color);
    gfx_pixel(x0 - y, y0 - x, color);
  }
}

void gfx_f_circle(int16_t x0, int16_t y0, int16_t r, uint8_t color) {
  uint8_t i;

  int8_t f = 1 - r;
  int8_t dd_f_x = 1;
  int8_t dd_f_y = -2 * r;
  int8_t x = 0;
  int8_t y = r;

  for (i = y0 - r; i <= y0 + r; i++) { gfx_pixel(x0, i, color); }

  while (x < y) {
    if (f >= 0) {
      y--;
      dd_f_y += 2;
      f += dd_f_y;
    }
    x++;
    dd_f_x += 2;
    f += dd_f_x;

    for (i = y0 - y; i <= y0 + y; i++) {
      gfx_pixel(x0 + x, i, color);
      gfx_pixel(x0 - x, i, color);
    }
    for (i = y0 - x; i <= y0 + x; i++) {
      gfx_pixel(x0 + y, i, color);
      gfx_pixel(x0 - y, i, color);
    }
  }
}
