/*
 * flash_store_data.c
 *
 *  Created on: Feb 19, 2025
 *      Author: solom
 */

#include "flash_store_data.h"
#include "string.h"
#include <stdio.h>


static uint32_t GetSector(uint32_t Address);

/* Private variables */
uint32_t FirstSector = 0, NbOfSectors = 0;
uint32_t StartingAddress = 0, SECTORError = 0;

/*Variable used for Erase procedure*/
static FLASH_EraseInitTypeDef EraseInitStruct;

static uint32_t GetSector(uint32_t Address);
void Flash_Read_String(uint32_t Address, char *Buffer, uint32_t MaxLen);

void Flash_Erase(uint32_t Address)
{
	/* Unlock the Flash to enable the flash control register access */
	HAL_FLASH_Unlock();

	/* Get the 1st sector to erase */
	FirstSector = GetSector(Address);
	/* Choosing only 1 sector to erase as it sufficient enough to write our data*/
	NbOfSectors = 1;
	/* Fill EraseInit structure*/
	EraseInitStruct.TypeErase     = FLASH_TYPEERASE_SECTORS;
	EraseInitStruct.VoltageRange  = FLASH_VOLTAGE_RANGE_3;
	EraseInitStruct.Sector        = FirstSector;
	EraseInitStruct.NbSectors     = NbOfSectors;

	if (HAL_FLASHEx_Erase(&EraseInitStruct, &SECTORError) != HAL_OK)
	{
		/*
      Error occurred while sector erase.
		 */
		/* Infinite loop */
		while (1)
		{
		}
	}
	HAL_FLASH_Lock();

}


void Flash_Read_String(uint32_t Address, char *Buffer, uint32_t MaxLen) {
    uint32_t i;
    uint8_t *ptr = (uint8_t *)Address;

    for (i = 0; i < MaxLen; i++) {
        Buffer[i] = *ptr++;
        if (Buffer[i] == '\0') break; // Stop if end of string is reached
    }
}


/**
 * @brief  Gets the sector of a given address
 * @param  None
 * @retval The sector of a given address
 */
static uint32_t GetSector(uint32_t Address)
{
	uint32_t sector = 0;

	if((Address < ADDR_FLASH_SECTOR_1) && (Address >= ADDR_FLASH_SECTOR_0))
	{
		sector = FLASH_SECTOR_0;
	}
	else if((Address < ADDR_FLASH_SECTOR_2) && (Address >= ADDR_FLASH_SECTOR_1))
	{
		sector = FLASH_SECTOR_1;
	}
	else if((Address < ADDR_FLASH_SECTOR_3) && (Address >= ADDR_FLASH_SECTOR_2))
	{
		sector = FLASH_SECTOR_2;
	}
	else if((Address < ADDR_FLASH_SECTOR_4) && (Address >= ADDR_FLASH_SECTOR_3))
	{
		sector = FLASH_SECTOR_3;
	}
	else if((Address < ADDR_FLASH_SECTOR_5) && (Address >= ADDR_FLASH_SECTOR_4))
	{
		sector = FLASH_SECTOR_4;
	}
	else if((Address < ADDR_FLASH_SECTOR_6) && (Address >= ADDR_FLASH_SECTOR_5))
	{
		sector = FLASH_SECTOR_5;
	}
	else if((Address < ADDR_FLASH_SECTOR_7) && (Address >= ADDR_FLASH_SECTOR_6))
	{
		sector = FLASH_SECTOR_6;
	}
	else if((Address < ADDR_FLASH_SECTOR_8) && (Address >= ADDR_FLASH_SECTOR_7))
	{
		sector = FLASH_SECTOR_7;
	}
	else if((Address < ADDR_FLASH_SECTOR_9) && (Address >= ADDR_FLASH_SECTOR_8))
	{
		sector = FLASH_SECTOR_8;
	}
	else if((Address < ADDR_FLASH_SECTOR_10) && (Address >= ADDR_FLASH_SECTOR_9))
	{
		sector = FLASH_SECTOR_9;
	}
	else if((Address < ADDR_FLASH_SECTOR_11) && (Address >= ADDR_FLASH_SECTOR_10))
	{
		sector = FLASH_SECTOR_10;
	}
#if defined(DUAL_BANK)
		  else if((Address < ADDR_FLASH_SECTOR_12) && (Address >= ADDR_FLASH_SECTOR_11))
		  {
			  sector = FLASH_SECTOR_11;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_13) && (Address >= ADDR_FLASH_SECTOR_12))
		  {
			  sector = FLASH_SECTOR_12;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_14) && (Address >= ADDR_FLASH_SECTOR_13))
		  {
			  sector = FLASH_SECTOR_13;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_15) && (Address >= ADDR_FLASH_SECTOR_14))
		  {
			  sector = FLASH_SECTOR_14;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_16) && (Address >= ADDR_FLASH_SECTOR_15))
		  {
			  sector = FLASH_SECTOR_15;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_17) && (Address >= ADDR_FLASH_SECTOR_16))
		  {
			  sector = FLASH_SECTOR_16;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_18) && (Address >= ADDR_FLASH_SECTOR_17))
		  {
			  sector = FLASH_SECTOR_17;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_19) && (Address >= ADDR_FLASH_SECTOR_18))
		  {
			  sector = FLASH_SECTOR_18;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_20) && (Address >= ADDR_FLASH_SECTOR_19))
		  {
			  sector = FLASH_SECTOR_19;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_21) && (Address >= ADDR_FLASH_SECTOR_20))
		  {
			  sector = FLASH_SECTOR_20;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_22) && (Address >= ADDR_FLASH_SECTOR_21))
		  {
			  sector = FLASH_SECTOR_21;
		  }
		  else if((Address < ADDR_FLASH_SECTOR_23) && (Address >= ADDR_FLASH_SECTOR_22))
		  {
			  sector = FLASH_SECTOR_22;
		  }
		  else /* (Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_23) */
		  {
			  sector = FLASH_SECTOR_23;
		  }
#else
	else /* (Address < FLASH_END_ADDR) && (Address >= ADDR_FLASH_SECTOR_11) */
	{
		sector = FLASH_SECTOR_11;
	}
#endif /* DUAL_BANK */
	return sector;
}


