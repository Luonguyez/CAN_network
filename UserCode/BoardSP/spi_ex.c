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
#include "stdint.h"
#include "stdbool.h"

/* Private defines ---------------------------------------------------- */
#define SPI1_USED	(1)
#define SPI2_USED	(0)
/* Private macros ----------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private variables -------------------------------------------------- */
static fp_spi1_hal_cb sfp_txcplt_cb = NULL;
static fp_spi1_hal_cb sfp_rxcplt_cb = NULL;

/* Private function prototypes ---------------------------------------- */
static void x_spi1_txcpltcb( SPI_HandleTypeDef* );
static void x_spi1_rxcpltcb( SPI_HandleTypeDef* );

/* Public variables --------------------------------------------------- */
/* Private function definitions --------------------------------------- */
static void x_spi1_txcpltcb( SPI_HandleTypeDef *hspi )
{
	if ( !sfp_txcplt_cb )
	{
		// Log the error
		return;
	}
	sfp_txcplt_cb();
}

static void x_spi1_rxcpltcb( SPI_HandleTypeDef *hspi )
{
	if ( !sfp_rxcplt_cb )
	{
		// Log the error
		return;
	}
	sfp_rxcplt_cb();
}
/* Function definitions ----------------------------------------------- */
/**
 * @brief Initialize all spi peripheral 
 * @param None
 * @return None
 */ 
void x_spi_init( void )
{
	/* This function is generated from CubeMX, thus, keep its naming for convenience */
	MX_SPI1_Init();	
}

/**
 * @brief Register a callback which is called when Tx transmission is completed
 * @param[in] fp_registered_function pointer to the function to be called
 * @return None
 * @brief  Transmit and Receive an amount of data in blocking mode
 * @param  data: byte to be sent
 * @retval received byte
 */
void x_spi1_register_txcpltcb( const fp_spi1_hal_cb fp_registered_function )
{
	HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_TX_COMPLETE_CB_ID, x_spi1_txcpltcb);
	sfp_txcplt_cb = fp_registered_function;
}

/**
 * @brief Register a callback which is called when Rx reception is completed
 * @param[in] fp_registered_function pointer to the function to be called
 * @return None
 * @brief  Transmit an amount of data in blocking mode
 * @param  data: byte to be sent
 * @retval None
 */
void x_spi1_register_rxcpltcb( const fp_spi1_hal_cb fp_registered_function )
{
	HAL_SPI_RegisterCallback(&hspi1, HAL_SPI_TX_COMPLETE_CB_ID, x_spi1_txcpltcb);
	sfp_rxcplt_cb = fp_registered_function;
}

/**
 * @brief Register a callback which is called when Tx transmission is completed
 * @param[in] p_tx_data pointer to a struct of the Tx data 
 * @return None
 * @brief  Receive an amount of data in blocking mode
 * @param  None
 * @retval received byte
 */
bool b_spi1_send_data( const spi_txdata_t* p_tx_data )
{
	HAL_StatusTypeDef em_result = HAL_ERROR;
	bool b_ret_val = false;
	em_result = HAL_SPI_Transmit_IT(&hspi1, p_tx_data->p_data, p_tx_data->size_in_bytes);
	if ( em_result != HAL_OK )
	{
		b_ret_val = false;
	}
	return b_ret_val;
}

/**
 * @brief Register a callback which is called when Tx transmission is completed
 * @param[in] p_tx_data pointer to a struct holding the pointer of Rx  
 * @return None
 * @brief  Transmit an amount of data in blocking mode
 * @param  buf: pointer to data buffer
 * @param  len: amount of data to be sent
 * @retval None
 */
bool b_spi1_receive_data( spi_rxdata_t* p_rx_data )
{
	HAL_StatusTypeDef em_result = HAL_ERROR;
	bool b_ret_val = false;
	em_result = HAL_SPI_Receive_IT(&hspi1, p_rx_data->p_data, p_rx_data->size_in_bytes);
	if ( em_result == HAL_OK )
	{
		b_ret_val = true;
	}
	return b_ret_val;
}

/* End of file -------------------------------------------------------- */