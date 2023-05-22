/**
cobbled by LSA232 05_2023
*/
// #include "lfs.h" //light filesystem oder sowas?
#include "pico-sdk/rp2_common/hardware_flash/include/hardware/flash.h"
#include "pico-sdk/rp2_common//hardware_sync/include/hardware/sync.h"
// #include "hardware/flash.h"
// #include "hardware/sync.h"
// not sure why to include like that?
// extern "C"
// {
// #include <hardware/flash.h>
// #include <hardware/sync.h>
// }

// BEWARE:
// Make sure second core is not accessing flash while edits!
// Prevent interrupts while hacking flash!

// Flash-based address of the last sector - we want to store in the last Sector
#define FLASH_TARGET_OFFSET (PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE)

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  // Comment
  Serial.println("Writing to Flash");
  Serial.println(sizeof(int)); // 4 bit
  Serial.println("*************");
  Serial.print(F("Pico Flash Size: "));
  Serial.println(PICO_FLASH_SIZE_BYTES);
  Serial.print(F("Flash Sector Size: "));
  Serial.println(FLASH_SECTOR_SIZE);
  Serial.print(F("Pico Page Size: "));
  Serial.println("FLASH_PAGE_SIZE");
  // End
  /**
  Pico Flash Size: 16777216 ~ 1,7 mb
  Flash Sector Size: 4096 - 4K
  Pico Page Size: 256 - bytes
  */

  saveData();
}

void saveData()
{
  uint32_t ints = save_and_disable_interrupts(); // Disable Interrupts as a starter
  // There must not be any fidgeting with memory while deleting and writing memory

  int lastSector = PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE; // where to start writing to

  int buf[FLASH_PAGE_SIZE / sizeof(int)]; // One page worth of 32-bit ints
  int mydata = 123456;                    // The data I want to store

  Serial.print("My Data is: ");
  Serial.println(sizeof(mydata));

  buf[0] = mydata; // Put the data into the first four bytes of buf[]

  // Erase the last sector of the flash
  flash_range_erase((lastSector), FLASH_SECTOR_SIZE);

  // Program buf[] into the first page of this sector
  flash_range_program((PICO_FLASH_SIZE_BYTES - FLASH_SECTOR_SIZE), (uint8_t *)buf, FLASH_PAGE_SIZE);
  // (uint8_t *)buf is casting buf in an 1-byte pointer -> increments one byte
  // PR2040 is littleEndian
  restore_interrupts(ints); // activate interrupts
}

void loop()
{
  // put your main code here, to run repeatedly:
}

/**
 *
 * # Reading from memory-mapped flash
 *   The ARM cores have the entire address space of the flash memory-mapped.
 *   What that means is that programatically, you simply create a pointer,
 *   set its address to the desired location in flash, and read the value directly as if it were in RAM.
 *   This makes traversing the flash for reads very simple as you can just increment a pointer in a loop and go.
 *   One minor bookeeping item that you must take into account is that the RAM is included in this address space.
 *   This means that the memory-mapped flash addresses will be offset by the RAM size
 *   as compared to the addresses we used above when erasing and programming the flash.
 *   On the RP2040, there are XIP_BASE bytes of RAM.
 *   So when you compute addresses for reading, use that as an additional offset.
 *   Here I grab an int from the first four bytes of the final sector:
 */

// int readMemory()
// {
//   int *p, addr, value;

//   // Compute the memory-mapped address, remembering to include the offset for RAM
//   addr = XIP_BASE + FLASH_TARGET_OFFSET;
//   p = (int *)addr; // Place an int pointer at our memory-mapped address
//   value = *p;      // Store the value at this address into a variable for later use
//   return value;
// }

// int getEmptyPage()
// {
//   int *p, page, addr;
//   int first_empty_page = -1;
//   int pages = FLASH_SECTOR_SIZE / FLASH_PAGE_SIZE;

//   for (page = 0; page < pages; page++)
//   {
//     addr = XIP_BASE + FLASH_TARGET_OFFSET + (page * FLASH_PAGE_SIZE);
//     p = (int *)addr; // place an int pointer at our memory-mapped address
//     // 0xFFFFFFFF cast as an int is -1 so this is how we detect an empty page
//     if (*p == -1 && first_empty_page < 0)
//     {
//       first_empty_page = page; // we found our first empty page, remember it
//     }
//   }
//   return first_empty_page;
// }