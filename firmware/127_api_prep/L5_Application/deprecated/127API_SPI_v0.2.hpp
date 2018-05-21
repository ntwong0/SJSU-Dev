#include <stdio.h>
#include "utilities.h"
#include "io.hpp"
#include "ssp1.h"
#include "gpio.hpp"

/**
 * System architecture is based on three buses, each governed by an MCP23S09 SPI IO Expander.
 * 1. Address
 *    - Out
 * 2. Data
 *    - In
 *    - Out
 * 3. Control
 *    - Out
 */

GPIO addr_ncs(P2_1);
//GPIO data_ncs(P2_2);
GPIO data_ncs(P0_0);
GPIO ctrl_ncs(P2_3);
GPIO nreset(P2_0);

void SPI_INIT()
{
	addr_ncs.setHigh();
	addr_ncs.setAsOutput();
	data_ncs.setHigh();
	data_ncs.setAsOutput();
	ctrl_ncs.setHigh();
	ctrl_ncs.setAsOutput();
	nreset.setLow();
	nreset.setAsOutput();
	nreset.setHigh();
	ssp1_set_max_clock(SYS_CFG_SPI1_CLK_MHZ/4);

	data_ncs.setLow();
	ssp1_exchange_byte((char)0x40); 	  //Device Opcode, Write
	ssp1_exchange_byte((char)0x06); 	  //Register Address, GPPU
	ssp1_exchange_byte((char)0xFF); 	  //Enable internal pullup resistors
	data_ncs.setHigh();
}

void AddrOut(const uint8_t reg)
{
	addr_ncs.setLow();
	ssp1_exchange_byte((char)0x40); 	  //Device Opcode, Write
	ssp1_exchange_byte((char)0x00); 	  //Register Address, IODIR
	ssp1_exchange_byte((char)0x00); 	  //Set direction as output
	addr_ncs.setHigh();

	addr_ncs.setLow();
	ssp1_exchange_byte((char)0x40); 	  //Device Opcode, Write
	ssp1_exchange_byte((char)0x09); 	  //Register Address, GPIO
	ssp1_exchange_byte((char)reg);  	  //Set value on IO Expander
	addr_ncs.setHigh();
}

void DataOut(const uint8_t reg)
{
	data_ncs.setLow();
	ssp1_exchange_byte((char)0x40); 	  //Device Opcode, Write
	ssp1_exchange_byte((char)0x00); 	  //Register Address, IODIR
	ssp1_exchange_byte((char)0x00); 	  //Set direction as output
	data_ncs.setHigh();

	data_ncs.setLow();
	ssp1_exchange_byte((char)0x40); 	  //Device Opcode, Write
	ssp1_exchange_byte((char)0x09); 	  //Register Address, GPIO
	ssp1_exchange_byte((char)reg);  	  //Set value on IO Expander
	data_ncs.setHigh();
}

void DataIn(uint8_t& reg)
{
	data_ncs.setLow();
	ssp1_exchange_byte((char)0x40);   	  //Device Opcode, Write
	ssp1_exchange_byte((char)0x00); 	  //Register Address, IODIR
	ssp1_exchange_byte((char)0xFF);       //Set direction as input
	data_ncs.setHigh();

	data_ncs.setLow();
	ssp1_exchange_byte((char)0x41);       //Device Opcode, Read
	ssp1_exchange_byte((char)0x09);       //Register Address, GPIO
	reg = ssp1_exchange_byte((char)0xFF); //Set value on reg
	data_ncs.setHigh();
}

void CtrlOut(const uint8_t reg)
{
	ctrl_ncs.setLow();
	ssp1_exchange_byte((char)0x40); 	  //Device Opcode, Write
	ssp1_exchange_byte((char)0x00); 	  //Register Address, IODIR
	ssp1_exchange_byte((char)0x00); 	  //Set direction as output
	ctrl_ncs.setHigh();

	ctrl_ncs.setLow();
	ssp1_exchange_byte((char)0x40); 	  //Device Opcode, Write
	ssp1_exchange_byte((char)0x09); 	  //Register Address, GPIO
	ssp1_exchange_byte((char)reg);  	  //Set value on IO Expander
	ctrl_ncs.setHigh();
}
