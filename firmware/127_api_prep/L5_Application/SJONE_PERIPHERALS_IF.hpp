#define SJONE_PERIPHERALS_IF_H__

#include "GPIO_245_IF.hpp"
#include "_245_373_IF.hpp"

/*
 * upper   | lower
 * 7 6 5 4 | 3 2 1 0
 * x l r w | x s s s
 * x c e r | x e e e
 * x d a i | x l l l
 * x _ d t | x _ _ _
 * x r   e | x l k s
 * x s     | x c p r
 * x       | x d   a
 * x       | x     m
 */

#define CMD_CLR 0x00

class SJONE_PERIPHERALS_IF
{
    public:
        SJONE_PERIPHERALS_IF();
        ~SJONE_PERIPHERALS_IF();
        set_addr(uint8_t addr);
        set_dataOut(uint8_t data);
        uint8_t get_dataIn();
        set_cmd(uint8_t cmd);
        toggle_clock(uint8_t cycles);
    private:
        GPIO_245_IF* GPIO_245;
        _245_373_IF* _245_373;
        GPIO* clk;          // this is P2_6
}

#endif //SJONE_PERIPHERALS_IF_H__