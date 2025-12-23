/**
* @file       app.c
* @version    1.0.0
* @date       2025-12-09
* @author     LuongNV
* @brief      
*/

/* Includes ----------------------------------------------------------- */
#include "app.h"
#include "spi_ex.h"
#include "gpio_ex.h"
#include "uart_ex.h"
#include <stdio.h>

/* Private defines ---------------------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private function definitions --------------------------------------- */
/* Function definitions ----------------------------------------------- */

void APP_Init(void)
{
    SPI_EX_Init();
    LED_Init();
    UART_EX_Init();
}

void APP_SPI_Loopback_Test(void)
{
    uint8_t tx = 0x55;
    uint8_t rx;
    char msg[32];

    rx = SPI_EX_Transfer(tx);

    sprintf(msg, "TX=0x%02X  RX=0x%02X\r\n", tx, rx);
    UART_EX_Transmit((uint8_t*)msg, strlen(msg));

    if (rx == tx)
        LED_On();
    else
        LED_Off();

    HAL_Delay(500);
    
}
/* End of file -------------------------------------------------------- */