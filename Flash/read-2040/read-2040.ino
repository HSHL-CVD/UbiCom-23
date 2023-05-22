/** 
 * HINTS
 * and from addresses.h:
 * XIP_BASE - the ARM address of the end of the onboard 256KB RAM.
 * On RP2040 this is 0x10000000 and the first byte of flash is the next address.  
 * 
 * Note that the flash_range_erase() and flash_range_program() functions from flash.h
 * do not use ARM address space, only offsets into flash (i.e. don't count the
 * first 0x10000000 bytes of address space representing the RAM.
 * 
 * But to read, point a pointer directly to a memory-mapped address somewhere in the
 * flash (so, use XIP_BASE to get past RAM) and read directly from it.

  a pointer is a var that has the memory location of another var as register value (rValue); 
  since whitespace doesn't count in c, writing `int* p`, `int * p` or `int *p` is the same
  to get the location value (lValue) from a var, we use the & (Ampersand - remember A for Adress)
  this is also called referencing, since we refer to the memory location
  e.g. `int * p = &var` 

  Nice Pointer Tutorial: https://engineerworkshop.com/blog/variables-pointers-and-indirection-in-arduino-c/
  Array Tutorial: 

  And a Tut how to traverse the memory https://www.logiqbit.com/arduino-pointers-how-to-use-pointers-in-your-sketches
  -> (*my_data_pointer)++; // we need to be careful we aren't incrementing the memory address, hence the brackets.
  so (*my_data_pointer ++) would be memory address???
*/
#include <hardware/flash.h>

void setup() {
  // put your setup code here, to run once:
  // byte stuff = flash_read(flash_t *obj, uint32_t address, uint8_t *data, uint32_t size)
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Reading from flash");
  Serial.println(XIP_BASE, HEX); // in our case e.g. 268435456
  Serial.println("contents: ");
  int * pointer = (int *)XIP_BASE - 10;
  for(int i = 0; i < + 100; i++) {
    Serial.print((char *)&pointer);
    *pointer ++;
  }
  Serial.println("");
  for(int i = 100; i < + 200; i++) {
    Serial.print((char *)&pointer);
    *pointer ++;
  }
  Serial.println("");
  for(int i = 200; i < + 300; i++) {
    Serial.print((char *)&pointer);
    *pointer ++;
  }
  // int addr = XIP_BASE + 4;
  // int *p = (int *)addr;
  // Serial.print("First byte is: ");
  // Serial.println((char)*p);

}

void loop() {
  // put your main code here, to run repeatedly:

}
