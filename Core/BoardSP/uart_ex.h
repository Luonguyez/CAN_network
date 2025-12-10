/**
* @file       uart_ex.h
* @version    1.0.0
* @date       2025-12-10
* @author     LuongNV
* 
* @brief      
*/

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __UART_EX_H
#define __UART_EX_H

/* Includes ----------------------------------------------------------- */
#include "stm32f1xx_hal.h"

/* Public defines ----------------------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public enumerate/structure ----------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */

void UART_EX_Init(void);
void UART_EX_Transmit(uint8_t *pData, uint16_t size);

#endif // __UART_EX_H
/* End of file -------------------------------------------------------- */