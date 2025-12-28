/**
* @file       uart_ex.c
* @version    1.0.0
* @date       2025-12-10
* @author     LuongNV
* @brief      
*/

/* Includes ----------------------------------------------------------- */
#include "uart_ex.h"

/* Private defines ---------------------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private variables -------------------------------------------------- */
static fp_uart_hal_cb sfp_txcplt_cb = NULL;
static fp_uart_hal_cb sfp_rxcplt_cb = NULL;
/* Private function prototypes ---------------------------------------- */
static void x_uart_txcpltcb( UART_HandleTypeDef* );
static void x_uart_rxcpltcb( UART_HandleTypeDef* ); 
/* Public variables --------------------------------------------------- */
/* Private function definitions --------------------------------------- */
static void x_uart_txcpltcb( UART_HandleTypeDef *huart )
{
    if ( !sfp_txcplt_cb )
    {
        // Log the error
        return;
    }
    sfp_txcplt_cb();
}
static void x_uart_rxcpltcb( UART_HandleTypeDef *huart )
{
    if ( !sfp_rxcplt_cb )
    {
        // Log the error
        return;
    }
    sfp_rxcplt_cb();
}

/* Function definitions ----------------------------------------------- */
void x_uart_init( void )
{
    MX_USART1_UART_Init(); 
}

void x_uart_register_txcpltcb( const fp_uart_hal_cb fp_reg_function )
{
    HAL_UART_RegisterCallback( &huart1, HAL_UART_TX_COMPLETE_CB_ID, x_uart_txcpltcb );
    sfp_txcplt_cb = fp_reg_function;
}

void x_uart_register_rxcpltcb( const fp_uart_hal_cb fp_reg_function )
{
    HAL_UART_RegisterCallback( &huart1, HAL_UART_RX_COMPLETE_CB_ID, x_uart_rxcpltcb );
    sfp_rxcplt_cb = fp_reg_function;
}

bool b_uart_receive_data( uart_rxdata_t* p_rx_data )
{
    HAL_StatusTypeDef em_result = HAL_ERROR;
    bool b_status = false;
    em_result = HAL_UART_Receive( &huart1, p_rx_data->p_rxdata, p_rx_data->size_of_rxdata, p_rx_data->timeout_ms );
    if ( em_result == HAL_OK )
    {
        b_status = true;
    }
    return b_status;;
}

bool b_uart_send_data( const uart_txdata_t* p_tx_data )
{
    HAL_StatusTypeDef em_result = HAL_ERROR;
    bool b_status = false;
    em_result = HAL_UART_Transmit( &huart1, (uint8_t*)p_tx_data->p_txdata, p_tx_data->size_of_txdata, p_tx_data->timeout_ms );
    if ( em_result == HAL_OK )
    {
        b_status = true;
    }
    return b_status;
}

/* End of file -------------------------------------------------------- */