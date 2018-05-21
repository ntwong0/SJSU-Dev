#define SJONE_SRAM_IF_H__

#include "SJONE_PERIPHERALS_IF.hpp"

#define SRAM_WRITE  0x11
#define SRAM_READ   0x21

typedef addr_t uint8_t;
typedef data_t uint8_t;

class SJONE_SRAM_IF
{
    public:
        // move from data to addr
        mov(addr_t& addr, data_t& data)
        {   
            iface.set_cmd(CMD_CLR);
            iface.set_addr(addr);
            iface.set_cmd(SRAM_WRITE);
            iface.set_dataOut(data);
            toggle_clock(5);
        }

        // move from addr to data
        mov(data_t& data, addr_t& addr)
        {
            iface.set_cmd(CMD_CLR);
            iface.set_addr(addr);
            iface.set_cmd(SRAM_READ);
            toggle_clock(5);
            data = iface.get_dataIn();
        }
    private:
        SJONE_PERIPHERALS_IF iface;
}

#endif //SJONE_SRAM_IF_H__