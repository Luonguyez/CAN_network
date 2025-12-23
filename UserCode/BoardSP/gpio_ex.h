/**
* @file       gpio_ex.h
* @version    1.0.0
* @date       2025-12-09
* @author     LuongNV
* 
* @brief      
*/

/* Define to prevent recursive inclusion ------------------------------ */
#ifndef __GPIO_EX_H
#define __GPIO_EX_H

/* Includes ----------------------------------------------------------- */
#include "main.h"

/* Public defines ----------------------------------------------------- */
/* Public macros ------------------------------------------------------ */
/* Public enumerate/structure ----------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
void LED_Init(void);
void LED_On(void);
void LED_Off(void);
void LED_Toggle(void);

#endif // __GPIO_EX_H
/* End of file -------------------------------------------------------- */