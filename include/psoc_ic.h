#pragma once

#ifdef __cplusplus
extern "C" {
#endif

#define IOMUX_REG_DIR *(volatile uint32_t*)0xffd10000
#define IOMUX_REG_FUNC *(volatile uint32_t*)0xffd10004
#define PSOC_REG_INFO *(volatile uint32_t*)0xffd10008

#define PSOC_CHIPID 0xB50C
#define PSOC_INFO_CHIPID(x) (x >> 16)
#define PSOC_INFO_SYSINFO(x) (x & 0xFFFF)
#define PSOC_INFO_IS_ASIC(x) (PSOC_INFO_SYSINFO(x) & 0x1000)
#define PSOC_INFO_ASIC_REV(x) (PSOC_INFO_SYSINFO(x) & 0xF)
#define PSOC_ASIC_REV_SG13G2_FALL25 0x1

#define DIR_OUTPUT 1
#define DIR_INPUT 0

#define FUNC_SECONDARY 1
#define FUNC_GPIO 0

#define PAD00 0
#define PAD01 1
#define PAD02 2
#define PAD03 3
#define PAD04 4
#define PAD05 5
#define PAD06 6
#define PAD07 7
#define PAD08 8
#define PAD09 9
#define PAD10 10
#define PAD11 11
#define PAD12 12
#define PAD13 13
#define PAD14 14
#define PAD15 15
#define PAD16 16
#define PAD17 17
#define PAD18 18
#define PAD19 19
#define PAD20 20
#define PAD21 21

#define GPIO00 PAD00
#define GPIO01 PAD01
#define GPIO02 PAD02
#define GPIO03 PAD03
#define GPIO04 PAD04
#define GPIO05 PAD05
#define GPIO06 PAD06
#define GPIO07 PAD07
#define GPIO08 PAD08
#define GPIO09 PAD09
#define GPIO10 PAD10
#define GPIO11 PAD11
#define GPIO12 PAD12
#define GPIO13 PAD13
#define GPIO14 PAD14
#define GPIO15 PAD15
#define GPIO16 PAD16
#define GPIO17 PAD17
#define GPIO18 PAD18
#define GPIO19 PAD19
#define GPIO20 PAD20
#define GPIO21 PAD21
// Internal GPIO, not externally available
#define GPIO_I2S_IRQ   22
#define GPIO_SD_IRQ    23

#define PIN_I2S_MCLK  PAD00
#define PIN_I2S_SDATA PAD01
#define PIN_I2S_SCLK  PAD02
#define PIN_I2S_LRCLK PAD03
#define FUNC_I2S      ((1 << PIN_I2S_MCLK) | (1 << PIN_I2S_SDATA) | (1 << PIN_I2S_SCLK) | (1 << PIN_I2S_LRCLK))

#define PIN_DAC_L     PAD04
#define PIN_DAC_R     PAD05
#define FUNC_DAC      ((1 << PIN_DAC_L) | (1 << PIN_DAC_R))

#define PIN_I2C_SDA   PAD06
#define PIN_I2C_SCL   PAD07
#define FUNC_I2C      ((1 << PIN_I2C_SDA) | (1 << PIN_I2C_SCL))

#define PIN_UART0_TX  PAD08
#define PIN_UART0_RX  PAD09
#define FUNC_UART0    ((1 << PIN_UART0_TX) | (1 << PIN_UART0_RX))

#define PIN_SPI_SCK   PAD10
#define PIN_SPI_MOSI  PAD11
#define PIN_SPI_MISO  PAD12
#define PIN_SPI_CS0   PAD13
#define PIN_SPI_CS1   PAD14
#define PIN_SPI_CS2   PAD15
#define FUNC_SPI      ((1 << PIN_SPI_SCK) | (1 << PIN_SPI_MOSI) | (1 << PIN_SPI_MISO) | (1 << PIN_SPI_CS0) | (1 << PIN_SPI_CS1) | (1 << PIN_SPI_CS2))

#define PIN_SD_CLK    PAD16
#define PIN_SD_CMD    PAD17
#define PIN_SD_DAT    PAD18
#define PIN_SD_CD     PAD19
#define FUNC_SD       ((1 << PIN_SD_CLK) | (1 << PIN_SD_CMD) | (1 << PIN_SD_DAT) | (1 << PIN_SD_CD))

#define PIN_PWM_0     PAD20
#define PIN_PWM_1     PAD21
#define FUNC_PWM      ((1 << PIN_PWM_0) | (1 << PIN_PWM_1))

#ifdef __cplusplus
}
#endif