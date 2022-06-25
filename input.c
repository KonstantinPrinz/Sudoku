#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

 // gets next input:
 // returns 1 for UP, 2 for DOWN, 3 for RIGHT and 4 for LEFT, 5 for ENTER, 6 for ESC, 7 for ENTF, 0 for invalid entries
 //
 int getInput ()
 {
     // getch() has to be called twice.
     // Source: https://social.msdn.microsoft.com/Forums/vstudio/en-US/a1759ad8-56d9-487d-84c9-3020300c87a3/cc-how-get-arrow-keyscorrectly-using-getch?forum=vcgeneral
     int input = getch();
     if( input == 0 || input == 224)
     {
        input = getch();
     }

       switch(input)
       {
        // UP
        case 72:
           return 1;
        // DOWN
        case 80:
           return 2;
        // RIGHT
        case 77:
           return 3;
        // LEFT
        case 75:
           return 4;
        // ENTER
        case 13:
            return 5;
        // ESC
        case 27:
            return 6;
        // ENTF
        case 83:
            return 7;
       default:
        return 0;
       }
 }

