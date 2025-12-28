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
#include "stdint.h"
#include "usart.h"
#include <stdbool.h>

/* Public defines ----------------------------------------------------- */
typedef void (*fp_uart_hal_cb)( void );
/* Public macros ------------------------------------------------------ */
/* Public enumerate/structure ----------------------------------------- */
typedef struct 
{
    const uint8_t* p_txdata;
    const uint16_t  size_of_txdata;
    const uint16_t  timeout_ms;
}uart_txdata_t;

typedef struct 
{
    uint8_t* p_rxdata;
    uint16_t  size_of_rxdata;
    uint16_t  timeout_ms;
}uart_rxdata_t;

/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
void x_uart_init( void );
void x_uart_register_txcpltcb( const fp_uart_hal_cb );
void x_uart_register_rxcpltcb( const fp_uart_hal_cb );
bool b_uart_receive_data( uart_rxdata_t* p_rx_data );
bool b_uart_send_data( const uart_txdata_t* p_tx_data );


#endif // __UART_EX_H
/* End of file -------------------------------------------------------- */