/* Provided by Mark Adams */
/*--------------------------------------*/


/* DO NOT EDIT!!! */
/* textcolor.c */
//This changes the colors of the text and background.

#include <windows.h>

/* textcolor.h beginning */

#ifndef TEXTCOLOR_H
#define TEXTCOLOR_H

void textcolor(int);
void textbackground(int);

typedef enum
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHTGRAY,
    DARKGRAY,
    LIGHTBLUE,
    LIGHTGREEN,
    LIGHTCYAN,
    LIGHTRED,
    LIGHTMAGENTA,
    YELLOW,
    WHITE
} COLORS;

#endif /* TEXTCOLOR_H */

/* End of textcolor.h */


static int __BACKGROUND = BLACK;
static int __FOREGROUND = LIGHTGRAY;

void textcolor(int color)
{
    __FOREGROUND = color;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color + (__BACKGROUND << 5));
    
}

void textbackground(int color)
{
    __BACKGROUND = color;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), __FOREGROUND + (color << 4));
   
}


