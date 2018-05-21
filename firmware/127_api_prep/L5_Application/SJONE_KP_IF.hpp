#define SJONE_KP_IF_H__

#include "SJONE_PERIPHERALS_IF.hpp"

#define KP_ENABLE  0x02

class SJONE_KP_IF
{
    public:
        // move from addr to data
        mov(uint8_t& dataIn, uint8_t& dataOut)
        {
            iface.set_cmd(CMD_CLR);
            iface.set_dataOut(dataOut);
            iface.set_cmd(KP_ENABLE);
            toggle_clock(8);
            dataIn = iface.get_dataIn();
        }
    private:
        SJONE_PERIPHERALS_IF iface;
}

#endif //SJONE_KP_IF_H__