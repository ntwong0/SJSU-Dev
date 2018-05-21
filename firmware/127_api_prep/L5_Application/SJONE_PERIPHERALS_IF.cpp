#include "SJONE_PERIPHERALS_IF.hpp"


SJONE_PERIPHERALS_IF::SJONE_PERIPHERALS_IF();
{
    clk = new GPIO(P2_6);
    clk->setAsOutput();
    clk->setLow();
    GPIO_245 = new GPIO_245_IF();
    _245_373 = new _245_373_IF();
}

SJONE_PERIPHERALS_IF::~SJONE_PERIPHERALS_IF();
{
    delete _245_373;
    _245_373 = 0;
    delete GPIO_245;
    GPIO_245 = 0;
    clk->setLow();
    clk->setAsInput();
    delete clk; 
    clk = 0;
}

void SJONE_PERIPHERALS_IF::set_addr(uint8_t addr)
{
    GPIO_245->output(addr);
    _245_373->latch_addr();
    GPIO_245->disable245();
}

void SJONE_PERIPHERALS_IF::set_dataOut(uint8_t data)
{
    GPIO_245->output(data);
    _245_373->latch_dataOut();
    GPIO_245->disable245();
}

uint8_t SJONE_PERIPHERALS_IF::get_dataIn()
{
    _245_373->enable_output_dataIn();
    uint8_t data = _245_373->input();
    GPIO_245->disable245();
    _245_373->disable_output_dataIn();
    return data;
}

void SJONE_PERIPHERALS_IF::set_cmd(uint8_t cmd)
{
    GPIO_245->output(cmd);
    _245_373->latch_cmd();
    GPIO_245->disable245();
}

void SJONE_PERIPHERALS_IF::toggle_clock(uint8_t cycles)
{
    for(uint8_t i = 0; i < cycles; i++)
    {
        clk->setHigh();
        clk->setLow();
    }
}
