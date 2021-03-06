#include "stm32f0xx.h"
#include "flash_stm32.h"
//#include "usart_stm32_console.h"
//#include "oled_stm32_ssd1306.h"

// A self-reset feature of the electronic would be nice to allow the device to reboot after changing the maximum ampere setting in the flash.

void FLASH_STM32_setNewMaximumAmpere(uint8_t newValue) {
	//OLED_STM32_clearDisplay();
	FLASH_Unlock();
	FLASH_Status eraseResponse = FLASH_ErasePage(MAXIMUM_AMPERE_ADDRESS);
	if (eraseResponse != FLASH_COMPLETE) {
		//USART_STM32_sendStringToUSART("DEBUG: Could not erase memory page from flash memory for MAXIMUM_AMPERE.");
		//OLED_STM32_drawMonospaceString(0,0,"ERASE FAIL");
		//OLED_STM32_updateDisplay();
	}
	FLASH_Status flashResponse = FLASH_ProgramWord(MAXIMUM_AMPERE_ADDRESS, newValue);
	if (flashResponse != FLASH_COMPLETE) {
		//USART_STM32_sendStringToUSART("DEBUG: Could not write new MAXIMUM_AMPERE value to flash memory.");
		//OLED_STM32_drawMonospaceString(0,10,"FLASH FAIL");
		//OLED_STM32_updateDisplay();
	}
	FLASH_Lock();
	//USART_STM32_sendStringToUSART("A new MAXIMUM_AMPERE value has been flashed. Please restart the device to take effect.");
	//OLED_STM32_drawMonospaceString(0,20,"FLASH SUCCESS");
	//OLED_STM32_updateDisplay();
}

uint8_t FLASH_STM32_getMaximumAmpere(void) {

	return (uint8_t)(*MAXIMUM_AMPERE_ADDRPTR);

}