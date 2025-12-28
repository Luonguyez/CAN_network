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
#include "spi.h"
#include "stdint.h"
#include <stdbool.h>
/* Public defines ----------------------------------------------------- */
typedef void (*fp_spi_hal_cb)( void );
/* Public macros ------------------------------------------------------ */
/* Public enumerate/structure ----------------------------------------- */
typedef struct 
{
	const uint8_t* p_txdata;
	const uint16_t  size_of_txdata;
}spi_txdata_t;

typedef struct 
{
	uint8_t* p_rxdata;
	uint16_t  size_of_rxdata;
	uint16_t  timeout_ms;
}spi_rxdata_t;

/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */
void x_spi_init( void );
void x_spi_register_txcpltcb( const fp_spi_hal_cb );
void x_spi_register_rxcpltcb( const fp_spi_hal_cb );
bool b_spi_receive_data( spi_rxdata_t* p_rx_data );
bool b_spi_send_data( const spi_txdata_t* p_tx_data );

#endif // __SPI_EX_H
/* End of file -------------------------------------------------------- */