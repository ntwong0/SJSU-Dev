#include <stdio.h>
#include "utilities.h"
#include "io.hpp"
#include "127API_SPI_v0.3.hpp"

/**********************************************
 * The following methods are similar to       *
 * the Intel IN, OUT, and MOV instructions.   *
 **********************************************/

/**
 * Transfers byte in register to the specified IO mapped hardware port address.
 *
 * +----------------------+
 * | Control Signal Table |
 * +----+------+----+-----+
 * | IO | MEM  | WR |  RD |
 * |----|------|----|-----|
 * |  1 |  0   |  1 |   0 |
 * +----------------------+
 *
 * @param { uint8_t } port     - 8-bit port address
 * @param { uint8_t } register - 8-bit value to be put onto the data bus to be transfered to device at port address
 */
void IO_OUT(uint8_t port, uint8_t register);
/**
 * Transfers byte in register to the specified IO mapped hardware port address.
 *
 * +----------------------+
 * | Control Signal Table |
 * +----+------+----+-----+
 * | IO | MEM  | WR |  RD |
 * |----|------|----|-----|
 * |  1 |  0   |  0 |   1 |
 * +----------------------+
 *
 * @param  {uint8_t} port - 8-bit port address
 * @return {uint8_t} returns valued placed onto the data bus by device on port address
 */
uint8_t IO_IN (uint8_t port);
/**
 * Write byte in register to the specified memory location address.
 *
 * +----------------------+
 * | Control Signal Table |
 * +----+------+----+-----+
 * | IO | MEM  | WR |  RD |
 * |----|------|----|-----|
 * |  1 |  0   |  1 |   0 |
 * +----------------------+
 *
 * @param  {uint8_t} address  - 8-bit memory location address
 * @param  {uint8_t} register - 8-bit value to be stored in memory
 */
void MEM_WR(uint8_t address, uint8_t register);
/**
 * Read byte from specified memory location address.
 *
 * +----------------------+
 * | Control Signal Table |
 * +----+------+----+-----+
 * | IO | MEM  | WR |  RD |
 * |----|------|----|-----|
 * |  1 |  0   |  0 |   1 |
 * +----------------------+
 *
 * @param  {uint8_t} address - 8-bit memory location address
 * @return {uint8_t} returns valued at memory location
 */
uint8_t MEM_RD(uint8_t address);

/**
 * General purpose registers to be used in system software.
 * Each is 32-bits in length.
 */
uint32_t R[8] = { 0 };

/**
 * RULES For software design:
 *
 * Prohibited from:
 *      - Creating mutable variables
 *
 * Allowed to:
 *      - Use #defines
 *      - Use enumerations
 *      - Create functions
 *         + can only accept register or void parameters
 *         + may only return 32-bit integers or smaller integers.
 *      - Create "const" variables (compiler will optimize them out)
 *      - Use printf
 *      - Use internal devices for debugging
 */

/**
 *** Example Code ***
int main (void)
{
    R[0] = 0b000'0000;
    //// Address bus = 0xFD and Data bus = R[0]
    IO_OUT(0xFD, R[0]);
    R[0] = 0b000'0001;
    //// Address bus = 0xFE and Data bus = R[0]
    IO_OUT(0xFE, R[0]);
    //// Read Data bus from port address bus = 0xFF
    R[1] = IO_IN(0xFF);
    //// Print returned value to STDOUT
    printf("Value @ 0xFF = %d\n", R[1]);
    while(1);
    return 0;
}
*/