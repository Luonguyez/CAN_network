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
#include <stdint.h>
#include <stdbool.h>
/* Public defines ----------------------------------------------------- */
typedef void (*fp_spi1_hal_cb)( void );

/* Public macros ------------------------------------------------------ */
/* Public enumerate/structure ----------------------------------------- */
typedef enum
{
	EM_SPI1, // peripheral spi1
	EM_SPI2, // peripheral spi2
}spi_channel_t;

typedef struct 
{
	const uint8_t* p_data;
	const uint16_t size_in_bytes;
}spi_txdata_t;

typedef struct 
{
	uint8_t* p_data;
	uint16_t size_in_bytes;
	uint16_t timeout_ms;
}spi_rxdata_t;

/* Public variables --------------------------------------------------- */
/* Public function prototypes ----------------------------------------- */

void x_spi_init( void );
void x_spi1_register_txcpltcb( const fp_spi1_hal_cb );
void x_spi1_register_rxcpltcb( const fp_spi1_hal_cb );
bool b_spi1_send_data( const spi_txdata_t* p_tx_data );
bool b_spi1_receive_data( spi_rxdata_t* p_rx_data );

#endif // __SPI_EX_H
/* End of file -------------------------------------------------------- */