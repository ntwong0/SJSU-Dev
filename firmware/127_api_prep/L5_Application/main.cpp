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
#include "GPIO_245_IF.hpp"

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
    GPIO addr_w(P2_1);
    addr_w.setAsOutput();
    addr_w.setHigh();
    
    GPIO dataOut_w(P2_2);
    dataOut_w.setAsOutput();
    dataOut_w.setHigh();

    GPIO cmd_w(P2_4);
    cmd_w.setAsOutput();
    cmd_w.setHigh();

    GPIO clk(P2_0);
    clk.setAsOutput();
    clk.setHigh();

    GPIO_245_IF interface;
    char buff[5] = {0};
    while(1)
    {      
        for(uint8_t i = 0; i < 256; i++)
        {    
            ctoba(buff, (char)i%16);
            for(int j = 1; j < 5; j++)
            {
                LE.set((5-j), CHECK_BIT(i,j-1));
            }
            LD.setNumber(i);
            interface.output(~i);

            delay_ms(500);
            
            
            uint8_t k = interface.input();
            printf("%x\n",k);
            
            delay_ms(500);
        }
    }
    return 0;
}
