/**
* @file       spi_ex.h
* @version    1.0.0
* @date       2025-12-09
* @author     LuongNV
* 
* @brief      
*/

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __SPI_EX_H
#define __SPI_EX_H

/* Includes ----------------------------------------------------------- */
#include "main.h"
#include "stm32f1xx_hal.h"
/* Public defines ----------------------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public enumerate/structure ----------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */

void    SPI_EX_Init(void);
uint8_t SPI_EX_Transfer(uint8_t data);
void    SPI_EX_WriteByte(uint8_t data);
uint8_t SPI_EX_ReadByte(void);
void    SPI_EX_WriteBuffer(uint8_t *buf, uint16_t len);
void    SPI_EX_ReadBuffer(uint8_t *buf, uint16_t len);

#endif // __SPI_EX_H
/* End of file -------------------------------------------------------- */