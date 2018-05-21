#define SJONE_LCD_IF_H__

#include "SJONE_PERIPHERALS_IF.hpp"

#define LCD_SET     0x14
#define LCD_WRITE   0x54
#define LCD_READ    0x64

#define DISP_CLR    0x01 // Clear display
#define RET_HOME    0x02 // Return home
#define ENTRY_SET   0x07 // Entry mode set: increment and shift
#define DISP_ON     0x0F // Display on: cursor on and blinking
#define DISP_SFT    0x1F // Display shift to the right
#define FUNC_SET    0x38 // Function set: 8 bit, 2 lines, 5x8 dots
#define LINE_2      0xC0

// Note: binary value of printable characters match ASCII up to 0x7F,
//       with the exception of tilde

class SJONE_LCD_IF
{
    public:
        reset()
        {
            iface.set_cmd(CMD_CLR);
            iface.set_cmd(LCD_SET);
            iface.set_dataOut(DISP_CLR);
            toggle_clock(5);
            iface.set_cmd(CMD_CLR);
            iface.set_cmd(LCD_SET);
            iface.set_dataOut(FUNC_SET);
            toggle_clock(5);
            iface.set_cmd(CMD_CLR);
            iface.set_cmd(LCD_SET);
            iface.set_dataOut(DISP_ON);
            toggle_clock(5);
            iface.set_cmd(CMD_CLR);
            iface.set_cmd(LCD_SET);
            iface.set_dataOut(ENTRY_SET);
            toggle_clock(5);
        }

        clear()
        {
            iface.set_cmd(CMD_CLR);
            iface.set_cmd(LCD_SET);
            iface.set_dataOut(DISP_CLR);
            toggle_clock(5);
        }

        ret_home()
        {
            iface.set_cmd(CMD_CLR);
            iface.set_cmd(LCD_SET);
            iface.set_dataOut(RET_HOME);
            toggle_clock(5);
        }

        line_2()
        {
            iface.set_cmd(CMD_CLR);
            iface.set_cmd(LCD_SET);
            iface.set_dataOut(LINE_2);
            toggle_clock(5);
        }
        
        write(char data)
        {   
            iface.set_cmd(CMD_CLR);
            iface.set_cmd(SRAM_WRITE);
            iface.set_dataOut(((uint8_t)data);
            toggle_clock(5);
        }

        write(char[] str, uint8_t len)
        {
            for(uint8_t i; i < len, i++)
                write(str[i]);
        }

        read(char& data)
        {
            iface.set_cmd(CMD_CLR);
            iface.set_cmd(LCD_READ);
            toggle_clock(5);
            data = iface.get_dataIn();
        }

        read(char[] str, uint8_t len)
        {
            for(uint8_t i; i < len, i++)
                read(str[i]);
        }
    private:
        SJONE_PERIPHERALS_IF iface;
}

#endif //SJONE_LCD_IF_H__