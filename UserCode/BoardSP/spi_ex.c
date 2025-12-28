/**
* @file       spi_ex.c
* @version    1.0.0
* @date       2025-12-09
* @author     LuongNV
* @brief      
*/

/* Includes ----------------------------------------------------------- */

#include "spi_ex.h"
#include "spi.h"


/* Private defines ---------------------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private variables -------------------------------------------------- */
static fp_spi_hal_cb sfp_txcplt_cb = NULL;
static fp_spi_hal_cb sfp_rxcplt_cb = NULL;
/* Private function prototypes ---------------------------------------- */
static void x_spi_txcpltcb( SPI_HandleTypeDef* );
static void x_spi_rxcpltcb( SPI_HandleTypeDef* );

/* Public variables --------------------------------------------------- */
/* Private function definitions --------------------------------------- */
static void x_spi_txcpltcb( SPI_HandleTypeDef *hspi )
{
	if ( !sfp_txcplt_cb )
	{
		// Log the error
		return;
	}
	sfp_txcplt_cb();
}

static void x_spi_rxcpltcb( SPI_HandleTypeDef *hspi )
{
	if ( !sfp_rxcplt_cb )
	{
		// Log the error
		return;
	}
	sfp_rxcplt_cb();
}
/* Function definitions ----------------------------------------------- */

void x_spi_init( void )
{
    MX_SPI1_Init(); 
}

void x_spi_register_txcpltcb( const  fp_spi_hal_cb fp_reg_function )
{
    HAL_SPI_RegisterCallback( &hspi1, HAL_SPI_TX_COMPLETE_CB_ID, x_spi_txcpltcb );
    sfp_txcplt_cb = fp_reg_function;
}

void x_spi_register_rxcpltcb( const fp_spi_hal_cb fp_reg_function )
{
    HAL_SPI_RegisterCallback( &hspi1, HAL_SPI_RX_COMPLETE_CB_ID, x_spi_rxcpltcb );
    sfp_rxcplt_cb = fp_reg_function;
}

bool b_spi_receive_data( spi_rxdata_t* p_rx_data )
{
    HAL_StatusTypeDef em_result = HAL_ERROR;
    bool b_ret_val = false;
    em_result = HAL_SPI_Receive_IT(&hspi1, p_rx_data->p_rxdata, p_rx_data->size_of_rxdata);
    if ( em_result == HAL_OK )
    {
        b_ret_val = true;
    }
    return b_ret_val;
}    

bool b_spi_send_data( const spi_txdata_t* p_tx_data )
{
    HAL_StatusTypeDef em_result = HAL_ERROR;
    bool b_ret_val = false;
    em_result = HAL_SPI_Transmit_IT(&hspi1, (uint8_t*)p_tx_data->p_txdata, p_tx_data->size_of_txdata);
    if ( em_result == HAL_OK )
    {
        b_ret_val = true;
    }
    return b_ret_val;
}

/* End of file -------------------------------------------------------- */