#ifndef GPIO_245_IF_H__
#define GPIO_245_IF_H__

#include "gpio.hpp"

/**
 * Class GPIO_245_IF provides an interface between GPIO pins and a TTL series 
 * '245 chip.
 */

class GPIO_245_IF
{
    public:
        GPIO_245_IF();
        ~GPIO_245_IF();
        void output(uint8_t value);
        uint8_t input();
        void disable245();
        void enable245();
        void dirGPIOTo245();
        void dir245ToGPIO();
    private:
        GPIO* to_245_A1;  //P1.29 is A1
        GPIO* to_245_A2;  //P1.28 is A2
        GPIO* to_245_A3;  //P1.23 is A3
        GPIO* to_245_A4;  //P1.22 is A4
        GPIO* to_245_A5;  //P1.20 is A5
        GPIO* to_245_A6;  //P1.19 is A6
        GPIO* to_245_A7;  //P0.30 is A7
        GPIO* to_245_A8;  //P0.29 is A8
        GPIO* to_245_DIR;  //P0.0  is DIR
        GPIO* to_245_nOE;  //P0.1  is nOE
};

#endif//GPIO_245_IF_H__
