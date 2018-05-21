#include "_245_373_IF.hpp"

void _245_373_IF::setAsOutput()
{
    addr_LE->setAsOutput();
    dataOut_LE->setAsOutput();
    dataIn_nOE->setAsOutput();
    cmd_LE->setAsOutput();
}

void _245_373_IF::setAsInput()
{
    addr_LE->setAsInput();
    dataOut_LE->setAsInput();
    dataIn_nOE->setAsInput();
    cmd_LE->setAsInput();
}

void _245_373_IF::disable()
{
    addr_LE->setLow();
    dataOut_LE->setLow();
    dataIn_nOE->setHigh();
    cmd_LE->setLow();
}

_245_373_IF::_245_373_IF()
{
    addr_LE    = new GPIO(P2_1);
    dataOut_LE = new GPIO(P2_2);
    dataIn_nOE = new GPIO(P2_3);
    cmd_LE     = new GPIO(P2_4);
    setAsOutput();
    disable();
}

_245_373_IF::~_245_373_IF()
{
    disable();
    setAsInput();
    delete addr_LE;
    addr_LE = 0;
    delete dataOut_LE;
    dataOut_LE = 0;
    delete dataIn_nOE;
    dataIn_nOE = 0;
    delete cmd_LE;
    cmd_LE = 0;
}

void _245_373_IF::latch_addr()
{
    addr_LE->setHigh();
    addr_LE->setLow();
}

void _245_373_IF::latch_dataOut()
{
    dataOut_LE->setHigh();
    dataOut_LE->setLow();
}

void _245_373_IF::latch_cmd()
{
    cmd_LE->setHigh();
    cmd_LE->setLow();
}

void _245_373_IF::enable_output_dataIn()
{ dataIn_nOE->setLow(); }

void _245_373_IF::disable_output_dataIn()
{ dataIn_nOE->setHigh(); }
