/**
* @file       spi_ex.c
* @version    1.0.0
* @date       2025-12-09
* @author     LuongNV
* @brief      
*/

/* Includes ----------------------------------------------------------- */
#include "spi_ex.h"
#include "stm32f1xx_hal.h"

/* Private defines ---------------------------------------------------- */
/* Private macros ----------------------------------------------------- */
/* Private enumerate/structure ---------------------------------------- */
/* Private variables -------------------------------------------------- */
/* Private function prototypes ---------------------------------------- */
/* Public variables --------------------------------------------------- */
/* Private function definitions --------------------------------------- */


/* SPI handler */
SPI_HandleTypeDef hspi1;

/* Init SPI1 in Full Duplex Master */
void SPI_EX_Init(void)
{
    __HAL_RCC_SPI1_CLK_ENABLE();
    __HAL_RCC_GPIOA_CLK_ENABLE();

    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // PA5 = SCK, PA7 = MOSI (AF Push Pull)
    GPIO_InitStruct.Pin   = GPIO_PIN_5 | GPIO_PIN_7;
    GPIO_InitStruct.Mode  = GPIO_MODE_AF_PP;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_HIGH;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // PA6 = MISO (Input floating)
    GPIO_InitStruct.Pin  = GPIO_PIN_6;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

    // SPI config
    hspi1.Instance               = SPI1;
    hspi1.Init.Mode              = SPI_MODE_MASTER;
    hspi1.Init.Direction         = SPI_DIRECTION_2LINES;
    hspi1.Init.DataSize          = SPI_DATASIZE_8BIT;
    hspi1.Init.CLKPolarity       = SPI_POLARITY_LOW;
    hspi1.Init.CLKPhase          = SPI_PHASE_1EDGE;
    hspi1.Init.NSS               = SPI_NSS_SOFT;
    hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_16;
    hspi1.Init.FirstBit          = SPI_FIRSTBIT_MSB;

    HAL_SPI_Init(&hspi1);
}

/* --- Core Transfer (full duplex): send 1 byte, receive 1 byte --- */
uint8_t SPI_EX_Transfer(uint8_t data)
{
    uint8_t rx;
    HAL_SPI_TransmitReceive(&hspi1, &data, &rx, 1, 100);
    return rx;
}

/* --- Write only --- */
void SPI_EX_WriteByte(uint8_t data)
{
    uint8_t dump;
    HAL_SPI_TransmitReceive(&hspi1, &data, &dump, 1, 100);
}

/* --- Read only --- */
uint8_t SPI_EX_ReadByte(void)
{
    uint8_t dummy = 0xFF;
    uint8_t rx;
    HAL_SPI_TransmitReceive(&hspi1, &dummy, &rx, 1, 100);
    return rx;
}

/* --- Write buffer --- */
void SPI_EX_WriteBuffer(uint8_t *buf, uint16_t len)
{
    uint8_t dump;
    for(uint16_t i=0; i<len; i++)
        HAL_SPI_TransmitReceive(&hspi1, &buf[i], &dump, 1, 100);
}

/* --- Read buffer --- */
void SPI_EX_ReadBuffer(uint8_t *buf, uint16_t len)
{
    uint8_t dummy = 0xFF;
    for(uint16_t i=0; i<len; i++)
        HAL_SPI_TransmitReceive(&hspi1, &dummy, &buf[i], 1, 100);
}

/* Function definitions ----------------------------------------------- */

/* End of file -------------------------------------------------------- */