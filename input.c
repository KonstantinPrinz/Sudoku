#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "header.h"

 // gets next input:
 // returns 1 for UP, 2 for DOWN, 3 for RIGHT and 4 for LEFT, 0 for invalid entries
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
       case 72:
           return 1;
       case 80:
           return 2;
       case 77:
           return 3;
       case 75:
           return 4;
       default:
        return 0;
       }
 }
