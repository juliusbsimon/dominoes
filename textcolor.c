
#include "textcolor.h"
#include <string.h>

///////////////////////////////////////////////
///TODO: make color argument case insensitive
///////////////////////////////////////////////

void txtcolor(char color[ 13 ])
{
     if(!(strcmp(color, "BLACK")))
        textcolor(BLACK);
     else if(!(strcmp(color, "BLUE")))
        textcolor(BLUE);
     else if(!(strcmp(color, "GREEN")))
        textcolor(GREEN);
     else if(!(strcmp(color, "CYAN")))
        textcolor(CYAN);
     else if(!(strcmp(color, "RED")))
        textcolor(RED);
     else if(!(strcmp(color, "MAGENTA")))
        textcolor(MAGENTA);      
     else if(!(strcmp(color, "BROWN")))
        textcolor(BROWN);
     else if(!(strcmp(color, "LIGHTGRAY")))
        textcolor(LIGHTGRAY);
     else if(!(strcmp(color, "DARKGRAY")))
        textcolor(DARKGRAY);
     else if(!(strcmp(color, "LIGHTBLUE")))
        textcolor(LIGHTBLUE);
     else if(!(strcmp(color, "LIGHTGREEN")))
        textcolor(LIGHTGREEN);
     else if(!(strcmp(color, "LIGHTCYAN")))
        textcolor(LIGHTCYAN);
     else if(!(strcmp(color, "LIGHTRED")))
        textcolor(LIGHTRED);
     else if(!(strcmp(color, "LIGHTMAGENTA")))
        textcolor(LIGHTMAGENTA);
     else if(!(strcmp(color, "YELLOW")))
        textcolor(YELLOW);
     else if(!(strcmp(color, "WHITE")))
        textcolor(WHITE);
     else
     {
         textcolor(WHITE);
         printf("Invalid Color Selected. Default to white.\n");
         printf("Press any key to continue . . . ");
         getch();
     }
            
}/* end txtcolor */

void bgcolor(char color[ 13 ])
{
     if(!(strcmp(color, "BLACK")))
        textbackground(BLACK);
     else if(!(strcmp(color, "BLUE")))
        textbackground(BLUE);
     else if(!(strcmp(color, "GREEN")))
        textbackground(GREEN);
     else if(!(strcmp(color, "CYAN")))
        textbackground(CYAN);
     else if(!(strcmp(color, "RED")))
        textbackground(RED);
     else if(!(strcmp(color, "MAGENTA")))
        textbackground(MAGENTA);      
     else if(!(strcmp(color, "BROWN")))
        textbackground(BROWN);
     else if(!(strcmp(color, "LIGHTGRAY")))
        textbackground(LIGHTGRAY);
     else if(!(strcmp(color, "DARKGRAY")))
        textbackground(DARKGRAY);
     else if(!(strcmp(color, "LIGHTBLUE")))
        textbackground(LIGHTBLUE);
     else if(!(strcmp(color, "LIGHTGREEN")))
        textbackground(LIGHTGREEN);
     else if(!(strcmp(color, "LIGHTCYAN")))
        textbackground(LIGHTCYAN);
     else if(!(strcmp(color, "LIGHTRED")))
        textbackground(LIGHTRED);
     else if(!(strcmp(color, "LIGHTMAGENTA")))
        textbackground(LIGHTMAGENTA);
     else if(!(strcmp(color, "YELLOW")))
        textbackground(YELLOW);
     else if(!(strcmp(color, "WHITE")))
        textbackground(WHITE);
     else
     {
         textbackground(BLACK);
         printf("Invalid Color Selected. Default to black.\n");
         printf("Press any key to continue . . . ");
         getch();
     }
}/* end bgcolor */

/*
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
*/

