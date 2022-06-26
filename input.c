#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

 // gets next input:
 // returns 1 for UP, 2 for DOWN, 3 for LEFT and 4 for RIGHT, 5 for ENTER, 6 for ESC, 7 for ENTF, 0 for invalid entries
 // 10 for 0, 11 for 1, 12 for 2 [...] 19 for 9
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
        // LEFT
        case 75:
           return 3;
        // RIGHT
        case 77:
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
        // 0
        case 48:
            return 10;
        // 1
        case 49:
            return 11;
        // 2
        case 50:
            return 12;
        // 3
        case 51:
            return 13;
        // 4
        case 52:
            return 14;
        // 5
        case 53:
            return 15;
         // 6
        case 54:
            return 16;
        // 7
        case 55:
            return 17;
        // 8
        case 56:
            return 18;
        // 9
        case 57:
            return 19;
       default:
            return 0;
       }
 }

