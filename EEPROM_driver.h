/*
 * EEPROM_driver.h
 *
 * Created: 18/8/2024
 *  Author: Reem Mohamed
 */ 


#ifndef EEPROM_DRIVER_H_
#define EEPROM_DRIVER_H_
/*
Function Name        : EEPROM_write
Function Returns     : void
Function Arguments   : unsigned short address, unsigned char data
Function Description :  write one byte to the given  address.
*/
void EEPROM_write(unsigned short address, unsigned char data );
/*
Function Name        : EEPROM_read
Function Returns     : unsigned char
Function Arguments   :  unsigned short address
Function Description :  read one byte from the given  address.
*/
unsigned char EEPROM_read( unsigned short address );
#endif /* EEPROM_DRIVER_H_ */