// FLASH_STM32 library: This library shall enable interfacing with the builtin flash memory of the STM32 chip.

// To Do: Clearly define the maximum size of the Linker File Settings:
/*
MEMORY
{
	ROM (rx) : ORIGIN = 0x08000000, LENGTH = 0x00003C00
	ROD (rx) : ORIGIN = 0x08003C00, LENGTH = 0x00000400 <-- For Storage
}

SECTIONS
{
	//Custom Data in ROD memory
	.mydata :
	{
		*(.mydata)
	} >ROD
}
*/

//Variable Definitions
#define    MAXIMUM_AMPERE_ADDRESS  0x08003C00
#define    MAXIMUM_AMPERE_ADDRPTR  ((uint16_t*) ((uint32_t) MAXIMUM_AMPERE_ADDRESS))

// Function Declarations
void FLASH_STM32_setNewMaximumAmpere(uint8_t newValue);