#define _245_373_IF_H__

#include "gpio.hpp"

/**
 * Class 245_373_IF is a software driver for
 * action between the 245 bus transceiver and
 * the 373 latch registers
 */

class _245_373_IF
{
    public:
        setAsOutput();
        setAsInput();
        disable();
        _245_373_IF();
        ~_245_373_IF();
        latch_addr();
        latch_dataOut();
        latch_cmd();
        enable_output_dataIn();
        disable_output_dataIn();
    private:
        GPIO* addr_LE;      // this is P2_1
        GPIO* dataOut_LE;   // this is P2_2
        GPIO* dataIn_nOE;   // this is P2_3
        GPIO* cmd_LE;       // this is P2_4
}

#endif//_245_373_IF_H__