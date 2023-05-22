/** 
cobbled by LSA232 05_2023
*/
#include "FlashIAPBlockDevice.h"
#include "lfs.h" //light filesystem oder sowas?
// #include "pico-sdk/rp2_common/hardware_flash/include/hardware/flash.h"
// #include "hardware/flash.h"
//FlashIAPBlockDevice fb;
// not sure why to include like that? 
extern "C" {
  #include <hardware/flash.h>
}

// BEWARE:
// Make sure second core is not accessing flash while edits!
// Prevent interrupts while hacking flash!



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  
  Serial.print(F("Pico Flash Size: "));
  Serial.println(PICO_FLASH_SIZE_BYTES);
  Serial.print(F("Flash Sector Size: "));
  Serial.println(FLASH_SECTOR_SIZE);
  Serial.print(F("Pico Page Size: "));
  Serial.println("FLASH_PAGE_SIZE");
  /** 
  Pico Flash Size: 16777216 ~ 1,7 mb
  Flash Sector Size: 4096 - 4K
  Pico Page Size: 256 - bytes
  */

}

void loop() {
  // put your main code here, to run repeatedly:

}
