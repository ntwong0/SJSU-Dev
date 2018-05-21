#include "GPIO_245_IF.hpp"
#include <stdio.h>

// Initialize GPIO_245_IF
GPIO_245_IF::GPIO_245_IF()
{
    to_245_nOE = new GPIO(P0_1);  //P0.1  is nOE
    disable245();
    to_245_A1 = new GPIO(P1_29);  //P1.29 is A1
    to_245_A2 = new GPIO(P1_28);  //P1.28 is A2
    to_245_A3 = new GPIO(P1_23);  //P1.23 is A3
    to_245_A4 = new GPIO(P1_22);  //P1.22 is A4
    to_245_A5 = new GPIO(P1_20);  //P1.20 is A5
    to_245_A6 = new GPIO(P1_19);  //P1.19 is A6
    to_245_A7 = new GPIO(P0_30);  //P0.30 is A7
    to_245_A8 = new GPIO(P0_29);  //P0.29 is A8
    to_245_DIR = new GPIO(P0_0);  //P0.0  is DIR
    dir245toGPIO();
}

// Destroy GPIO_245_IF
GPIO_245_IF::~GPIO_245_IF()
{
    disable245();
    dir245toGPIO();
    delete to_245_A1;  //P1.29 is A1
    to_245_A1 = 0;
    delete to_245_A2;  //P1.28 is A2
    to_245_A2 = 0;
    delete to_245_A3;  //P1.23 is A3
    to_245_A3 = 0;
    delete to_245_A4;  //P1.22 is A4
    to_245_A4 = 0;
    delete to_245_A5;  //P1.20 is A5
    to_245_A5 = 0;
    delete to_245_A6;  //P1.19 is A6
    to_245_A6 = 0;
    delete to_245_A7;  //P0.30 is A7
    to_245_A7 = 0;
    delete to_245_A8;  //P0.29 is A8
    to_245_A8 = 0;
    delete to_245_DIR;  //P0.0  is DIR
    to_245_DIR = 0;
    delete to_245_nOE;  //P0.1  is nOE
    to_245_nOE = 0;
}

// Disable '245 device
void GPIO_245_IF::disable245()   
{ to_245_nOE->setHigh(); }

// Enable '245 device
void GPIO_245_IF::enable245()    
{ to_245_nOE->setLow(); }

// Change the direction of GPIO and 245 pins to send data from GPIO to '245
void GPIO_245_IF::dirGPIOTo245() 
{ 
    to_245_A1->setAsOutput();
    to_245_A2->setAsOutput();
    to_245_A3->setAsOutput();
    to_245_A4->setAsOutput();
    to_245_A5->setAsOutput();
    to_245_A6->setAsOutput();
    to_245_A7->setAsOutput();
    to_245_A8->setAsOutput();
    to_245_DIR->setHigh(); 
}

// Change the direction of GPIO and 245 pins to send data from '245 to GPIO
void GPIO_245_IF::dir245ToGPIO() 
{ 
    to_245_A1->setAsInput();
    to_245_A2->setAsInput();
    to_245_A3->setAsInput();
    to_245_A4->setAsInput();
    to_245_A5->setAsInput();
    to_245_A6->setAsInput();
    to_245_A7->setAsInput();
    to_245_A8->setAsInput();
    to_245_DIR->setLow(); 
}

/*
 * Write a value to GPIO and send to '245
 * @param value The byte to write out to '245
 */
void GPIO_245_IF::output(uint8_t value)
{
    dirGPIOTo245();
    value & 0x01 ? to_245_A1->setHigh() : to_245_A1->setLow();
    value & 0x02 ? to_245_A2->setHigh() : to_245_A2->setLow();
    value & 0x04 ? to_245_A3->setHigh() : to_245_A3->setLow();
    value & 0x08 ? to_245_A4->setHigh() : to_245_A4->setLow();
    value & 0x10 ? to_245_A5->setHigh() : to_245_A5->setLow();
    value & 0x20 ? to_245_A6->setHigh() : to_245_A6->setLow();
    value & 0x40 ? to_245_A7->setHigh() : to_245_A7->setLow();
    value & 0x80 ? to_245_A8->setHigh() : to_245_A8->setLow();
    enable245();
}

/* 
 * Read from GPIO incoming data from '245
 * @returns The value read from '245
 */
uint8_t GPIO_245_IF::input()
{
    uint8_t value = 0x00;
    dir245ToGPIO();
    enable245();
    if(to_245_A1->read()) value = value | 0x01;
    if(to_245_A2->read()) value = value | 0x02;
    if(to_245_A3->read()) value = value | 0x04;
    if(to_245_A4->read()) value = value | 0x08;
    if(to_245_A5->read()) value = value | 0x10;
    if(to_245_A6->read()) value = value | 0x20;
    if(to_245_A7->read()) value = value | 0x40;
    if(to_245_A8->read()) value = value | 0x80;
    return value;
}
