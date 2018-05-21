/*
 *     SocialLedge.com - Copyright (C) 2013
 *
 *     This file is part of free software framework for embedded processors.
 *     You can use it and/or distribute it as long as this copyright header
 *     remains unmodified.  The code is free for personal use and requires
 *     permission to use in a commercial product.
 *
 *      THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 *      OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 *      MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 *      I SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 *      CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 *     You can reach the author of this software at :
 *          p r e e t . w i k i @ g m a i l . c o m
 */

/**
 * @file
 * @brief This is the application entry point.
 */

#include <stdio.h>
#include "utilities.h"
#include "io.hpp"
#include "gpio.hpp"

const bool CHECK_BIT(int var, int pos)
{
    return (bool)(var & (1 << pos));
}

void ctoba(char * arr, char num)
{
    arr[4] = 0;
    for(int i = 3; i >= 0; i--)
    {
        if(num & (8 >> i))
        {
            arr[i] = '1';
        }
        else
        {
            arr[i] = '0';
        }
    }
}

int main (void)
{
    GPIO io244_A1(P1_29);  //P1.29 is A1
    io244_A1.setAsOutput();
    io244_A1.setHigh();
    GPIO io244_A2(P1_28);  //P1.28 is A2
    io244_A2.setAsOutput();
    io244_A2.setHigh();
    GPIO io244_A3(P1_23);  //P1.23 is A3
    io244_A3.setAsOutput();
    io244_A3.setHigh();
    GPIO io244_A4(P1_22);  //P1.22 is A4
    io244_A4.setAsOutput();
    io244_A4.setHigh();
    GPIO io244_A5(P1_20);  //P1.20 is A5
    io244_A5.setAsOutput();
    io244_A5.setHigh();
    GPIO io244_A6(P1_19);  //P1.19 is A6
    io244_A6.setAsOutput();
    io244_A6.setHigh();
    GPIO io244_A7(P0_30);  //P0.30 is A7
    io244_A7.setAsOutput();
    io244_A7.setHigh();
    GPIO io244_A8(P0_29);  //P0.29 is A8
    io244_A8.setAsOutput();
    io244_A8.setHigh();
    GPIO io244_DIR(P0_0);  //P0.0  is DIR
    io244_DIR.setAsOutput();
    io244_DIR.setHigh();
    GPIO io244_nOE(P0_1);  //P0.1  is nOE
    io244_nOE.setAsOutput();
    io244_nOE.setLow();
    char buff[5] = {0};
    while(1)
    {
/*        for(int i = 0; i < 16; i++)
        {
            ctoba(buff, (char)i);
            for(int j = 1; j < 5; j++)
            {
                LE.set((5-j), CHECK_BIT(i,j-1));
            }
            LD.setNumber(i);
            printf("Hello Preet 0x%X\n", i);
*/            
        for(int i = 0; i < 32; i++)
        {    
            switch(i) 
            {
                case 0:
                    io244_A1.setHigh();
                    io244_A2.setHigh();
                    io244_A3.setHigh();
                    io244_A4.setHigh();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 1:
                    io244_A1.setLow();
                    io244_A2.setHigh();
                    io244_A3.setHigh();
                    io244_A4.setHigh();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 2:
                    io244_A1.setHigh();
                    io244_A2.setLow();
                    io244_A3.setHigh();
                    io244_A4.setHigh();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 3:
                    io244_A1.setLow();
                    io244_A2.setLow();
                    io244_A3.setHigh();
                    io244_A4.setHigh();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 4:
                    io244_A1.setHigh();
                    io244_A2.setHigh();
                    io244_A3.setLow();
                    io244_A4.setHigh();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 5:
                    io244_A1.setLow();
                    io244_A2.setHigh();
                    io244_A3.setLow();
                    io244_A4.setHigh();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 6:
                    io244_A1.setHigh();
                    io244_A2.setLow();
                    io244_A3.setLow();
                    io244_A4.setHigh();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 7:
                    io244_A1.setLow();
                    io244_A2.setLow();
                    io244_A3.setLow();
                    io244_A4.setHigh();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 8:
                    io244_A1.setHigh();
                    io244_A2.setHigh();
                    io244_A3.setHigh();
                    io244_A4.setLow();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 9:
                    io244_A1.setLow();
                    io244_A2.setHigh();
                    io244_A3.setHigh();
                    io244_A4.setLow();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 10:
                    io244_A1.setHigh();
                    io244_A2.setLow();
                    io244_A3.setHigh();
                    io244_A4.setLow();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 11:
                    io244_A1.setLow();
                    io244_A2.setLow();
                    io244_A3.setHigh();
                    io244_A4.setLow();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 12:
                    io244_A1.setHigh();
                    io244_A2.setHigh();
                    io244_A3.setLow();
                    io244_A4.setLow();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 13:
                    io244_A1.setLow();
                    io244_A2.setHigh();
                    io244_A3.setLow();
                    io244_A4.setLow();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 14:
                    io244_A1.setHigh();
                    io244_A2.setLow();
                    io244_A3.setLow();
                    io244_A4.setLow();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 15:
                    io244_A1.setLow();
                    io244_A2.setLow();
                    io244_A3.setLow();
                    io244_A4.setLow();
                    io244_A5.setHigh();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 16:
                    io244_A1.setHigh();
                    io244_A2.setHigh();
                    io244_A3.setHigh();
                    io244_A4.setHigh();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 17:
                    io244_A1.setLow();
                    io244_A2.setHigh();
                    io244_A3.setHigh();
                    io244_A4.setHigh();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 18:
                    io244_A1.setHigh();
                    io244_A2.setLow();
                    io244_A3.setHigh();
                    io244_A4.setHigh();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 19:
                    io244_A1.setLow();
                    io244_A2.setLow();
                    io244_A3.setHigh();
                    io244_A4.setHigh();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 20:
                    io244_A1.setHigh();
                    io244_A2.setHigh();
                    io244_A3.setLow();
                    io244_A4.setHigh();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 21:
                    io244_A1.setLow();
                    io244_A2.setHigh();
                    io244_A3.setLow();
                    io244_A4.setHigh();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 22:
                    io244_A1.setHigh();
                    io244_A2.setLow();
                    io244_A3.setLow();
                    io244_A4.setHigh();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 23:
                    io244_A1.setLow();
                    io244_A2.setLow();
                    io244_A3.setLow();
                    io244_A4.setHigh();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 24:
                    io244_A1.setHigh();
                    io244_A2.setHigh();
                    io244_A3.setHigh();
                    io244_A4.setLow();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 25:
                    io244_A1.setLow();
                    io244_A2.setHigh();
                    io244_A3.setHigh();
                    io244_A4.setLow();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 26:
                    io244_A1.setHigh();
                    io244_A2.setLow();
                    io244_A3.setHigh();
                    io244_A4.setLow();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 27:
                    io244_A1.setLow();
                    io244_A2.setLow();
                    io244_A3.setHigh();
                    io244_A4.setLow();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 28:
                    io244_A1.setHigh();
                    io244_A2.setHigh();
                    io244_A3.setLow();
                    io244_A4.setLow();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 29:
                    io244_A1.setLow();
                    io244_A2.setHigh();
                    io244_A3.setLow();
                    io244_A4.setLow();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 30:
                    io244_A1.setHigh();
                    io244_A2.setLow();
                    io244_A3.setLow();
                    io244_A4.setLow();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                case 31:
                    io244_A1.setLow();
                    io244_A2.setLow();
                    io244_A3.setLow();
                    io244_A4.setLow();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;
                default:
                    io244_A1.setHigh();
                    io244_A2.setHigh();
                    io244_A3.setHigh();
                    io244_A4.setHigh();
                    io244_A5.setLow();
                    io244_A6.setHigh();
                    io244_A7.setHigh();
                    io244_A8.setHigh();
                    break;                
            }
            delay_ms(1000);
        }
    }
    return 0;
}
