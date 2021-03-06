
#include "stdint.h"

const uint8_t my_font[] = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // Code for char  
        0x00, 0x00, 0xFA, 0x00, 0x00, 0x00,      // Code for char !
        0x00, 0xE0, 0x00, 0xE0, 0x00, 0x00,      // Code for char "
        0x2E, 0x38, 0xEE, 0x38, 0xE8, 0x00,      // Code for char #
        0x00, 0x24, 0x54, 0xD6, 0x4C, 0x00,      // Code for char $
        0xE2, 0xAC, 0xFE, 0x6A, 0x8E, 0x00,      // Code for char %
        0x7C, 0x92, 0xAA, 0x4C, 0x12, 0x00,      // Code for char &
        0x00, 0x00, 0xE0, 0x00, 0x00, 0x00,      // Code for char '
        0x00, 0x3C, 0x42, 0x00, 0x00, 0x00,      // Code for char (
        0x00, 0x00, 0x00, 0x42, 0x3C, 0x00,      // Code for char )
        0x00, 0x40, 0x50, 0xE0, 0x50, 0x40,      // Code for char *
        0x00, 0x10, 0x10, 0x7C, 0x10, 0x10,      // Code for char +
        0x00, 0x02, 0x06, 0x00, 0x00, 0x00,      // Code for char ,
        0x00, 0x00, 0x08, 0x08, 0x00, 0x00,      // Code for char -
        0x00, 0x00, 0x02, 0x00, 0x00, 0x00,      // Code for char .
        0x00, 0x00, 0x0E, 0x70, 0x80, 0x00,      // Code for char /
        0x00, 0x7C, 0x92, 0x92, 0x7C, 0x00,      // Code for char 0
        0x00, 0x00, 0x42, 0xFE, 0x02, 0x00,      // Code for char 1
        0x00, 0x46, 0x8A, 0x92, 0x62, 0x00,      // Code for char 2
        0x00, 0x82, 0x92, 0x92, 0x6C, 0x00,      // Code for char 3
        0x18, 0x68, 0xC8, 0xFE, 0x08, 0x00,      // Code for char 4
        0x00, 0xF2, 0x92, 0x92, 0x8C, 0x00,      // Code for char 5
        0x00, 0x3C, 0x52, 0x92, 0x8C, 0x00,      // Code for char 6
        0x00, 0x80, 0x8E, 0xB0, 0xC0, 0x00,      // Code for char 7
        0x00, 0x6C, 0x92, 0x92, 0x6C, 0x00,      // Code for char 8
        0x00, 0x62, 0x92, 0x94, 0x78, 0x00,      // Code for char 9
        0x00, 0x00, 0x22, 0x00, 0x00, 0x00,      // Code for char :
        0x00, 0x02, 0x26, 0x00, 0x00, 0x00,      // Code for char ;
        0x00, 0x08, 0x14, 0x14, 0x22, 0x00,      // Code for char <
        0x00, 0x14, 0x14, 0x14, 0x14, 0x00,      // Code for char =
        0x00, 0x22, 0x14, 0x14, 0x08, 0x00,      // Code for char >
        0x00, 0x80, 0x8A, 0x90, 0x60, 0x00,      // Code for char ?
        0x7C, 0x82, 0x99, 0xA5, 0x7C, 0x00,      // Code for char @
        0x06, 0x78, 0x88, 0x78, 0x06, 0x00,      // Code for char A
        0x00, 0xFE, 0x92, 0x92, 0x6C, 0x00,      // Code for char B
        0x00, 0x7C, 0x82, 0x82, 0x82, 0x00,      // Code for char C
        0x00, 0xFE, 0x82, 0x82, 0x7C, 0x00,      // Code for char D
        0x00, 0xFE, 0x92, 0x92, 0x82, 0x00,      // Code for char E
        0x00, 0xFE, 0x90, 0x90, 0x90, 0x00,      // Code for char F
        0x00, 0x7C, 0x82, 0x82, 0x8E, 0x00,      // Code for char G
        0x00, 0xFE, 0x10, 0x10, 0xFE, 0x00,      // Code for char H
        0x00, 0x00, 0x82, 0xFE, 0x82, 0x00,      // Code for char I
        0x00, 0x04, 0x82, 0x82, 0xFC, 0x00,      // Code for char J
        0x00, 0xFE, 0x10, 0x6C, 0x82, 0x00,      // Code for char K
        0x00, 0xFE, 0x02, 0x02, 0x02, 0x00,      // Code for char L
        0xFE, 0x60, 0x10, 0x60, 0xFE, 0x00,      // Code for char M
        0xFE, 0xC0, 0x70, 0x18, 0xFE, 0x00,      // Code for char N
        0x00, 0x7C, 0x82, 0x82, 0x7C, 0x00,      // Code for char O
        0x00, 0xFE, 0x88, 0x88, 0x70, 0x00,      // Code for char P
        0x78, 0x84, 0x86, 0x84, 0x78, 0x00,      // Code for char Q
        0x00, 0xFE, 0x90, 0x98, 0x66, 0x00,      // Code for char R
        0x00, 0x62, 0x92, 0x92, 0x8C, 0x00,      // Code for char S
        0x80, 0x80, 0xFE, 0x80, 0x80, 0x00,      // Code for char T
        0x00, 0xFC, 0x02, 0x02, 0xFC, 0x00,      // Code for char U
        0xC0, 0x3C, 0x06, 0x3C, 0xC0, 0x00,      // Code for char V
        0xFC, 0x02, 0x1C, 0x02, 0xFC, 0x00,      // Code for char W
        0x82, 0x6C, 0x38, 0x6C, 0x82, 0x00,      // Code for char X
        0x80, 0x60, 0x1E, 0x60, 0x80, 0x00,      // Code for char Y
        0x00, 0x86, 0x9A, 0xA2, 0xC2, 0x00,      // Code for char Z
        0x00, 0x00, 0xFF, 0x80, 0x80, 0x00,      // Code for char [
        0x00, 0x80, 0x70, 0x0E, 0x00, 0x00,      // Code for char BackSlash
        0x00, 0x80, 0x80, 0xFE, 0x00, 0x00,      // Code for char ]
        0x10, 0x60, 0x80, 0x60, 0x10, 0x00,      // Code for char ^
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00,      // Code for char _
        0x00, 0x00, 0x00, 0x80, 0x00, 0x00,      // Code for char `
        0x00, 0x04, 0x2A, 0x2A, 0x1E, 0x00,      // Code for char a
        0x00, 0xFE, 0x22, 0x22, 0x1C, 0x00,      // Code for char b
        0x00, 0x1C, 0x22, 0x22, 0x22, 0x00,      // Code for char c
        0x00, 0x1C, 0x22, 0x22, 0xFE, 0x00,      // Code for char d
        0x00, 0x1C, 0x2A, 0x2A, 0x1A, 0x00,      // Code for char e
        0x00, 0x20, 0xFE, 0x20, 0x20, 0x00,      // Code for char f
        0x18, 0x24, 0x24, 0x24, 0x3E, 0x00,      // Code for char g
        0x00, 0xFE, 0x20, 0x20, 0x1E, 0x00,      // Code for char h
        0x00, 0x20, 0xBC, 0x02, 0x02, 0x00,      // Code for char i
        0x00, 0x20, 0x20, 0xA0, 0x3E, 0x00,      // Code for char j
        0x00, 0xFE, 0x08, 0x14, 0x22, 0x00,      // Code for char k
        0x00, 0x00, 0xFC, 0x02, 0x02, 0x00,      // Code for char l
        0x3E, 0x20, 0x38, 0x20, 0x1E, 0x00,      // Code for char m
        0x00, 0x3E, 0x20, 0x20, 0x1E, 0x00,      // Code for char n
        0x00, 0x1C, 0x22, 0x22, 0x1C, 0x00,      // Code for char o
        0x00, 0x3E, 0x24, 0x24, 0x18, 0x00,      // Code for char p
        0x00, 0x18, 0x24, 0x24, 0x3E, 0x00,      // Code for char q
        0x00, 0x3E, 0x20, 0x20, 0x20, 0x00,      // Code for char r
        0x00, 0x12, 0x2A, 0x2A, 0x24, 0x00,      // Code for char s
        0x00, 0x20, 0xFC, 0x22, 0x22, 0x00,      // Code for char t
        0x00, 0x3C, 0x02, 0x02, 0x3E, 0x00,      // Code for char u
        0x30, 0x0C, 0x02, 0x0C, 0x30, 0x00,      // Code for char v
        0x38, 0x06, 0x18, 0x06, 0x38, 0x00,      // Code for char w
        0x22, 0x14, 0x08, 0x14, 0x22, 0x00,      // Code for char x
        0x30, 0x0C, 0x06, 0x0C, 0x30, 0x00,      // Code for char y
        0x00, 0x22, 0x2E, 0x32, 0x22, 0x00,      // Code for char z
        0x00, 0x10, 0xEE, 0x00, 0x00, 0x00,      // Code for char {
        0x00, 0x00, 0x00, 0xFE, 0x00, 0x00,      // Code for char |
        0x00, 0x00, 0x00, 0xEE, 0x10, 0x00,      // Code for char }
        0x08, 0x10, 0x08, 0x08, 0x10, 0x00,      // Code for char ~
        0xFC, 0x04, 0xFC, 0x00, 0x00, 0x00       // Code for char 
        };
