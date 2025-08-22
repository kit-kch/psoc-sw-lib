#include <neorv32.h>

#include "psoc_board.h"

bool psoc_board_setup(bool force)
{
    neorv32_rte_setup();
    neorv32_uart0_setup(115200, 0);

    uint32_t info = PSOC_REG_INFO;
    if (PSOC_INFO_CHIPID(info) == PSOC_CHIPID)
    {
        // Need to initialize IO Mux on PSOC Chip
        IOMUX_REG_FUNC = FUNC_UART0;

        neorv32_uart0_printf("\n\n\n");
        neorv32_uart0_printf("#===========================================================================#\n");
        neorv32_uart0_printf("                                                                             \n");
        neorv32_uart0_printf("PPPPPPPPPPPPPPPPP      SSSSSSSSSSSSSSS                          CCCCCCCCCCCCC\n");
        neorv32_uart0_printf("P::::::::::::::::P   SS:::::::::::::::S                      CCC::::::::::::C\n");
        neorv32_uart0_printf("P::::::PPPPPP:::::P S:::::SSSSSS::::::S                    CC:::::::::::::::C\n");
        neorv32_uart0_printf("PP:::::P     P:::::PS:::::S     SSSSSSS                   C:::::CCCCCCCC::::C\n");
        neorv32_uart0_printf("  P::::P     P:::::PS:::::S               ooooooooooo    C:::::C       CCCCCC\n");
        neorv32_uart0_printf("  P::::P     P:::::PS:::::S             oo:::::::::::oo C:::::C              \n");
        neorv32_uart0_printf("  P::::PPPPPP:::::P  S::::SSSS         o:::::::::::::::oC:::::C              \n");
        neorv32_uart0_printf("  P:::::::::::::PP    SS::::::SSSSS    o:::::ooooo:::::oC:::::C              \n");
        neorv32_uart0_printf("  P::::PPPPPPPPP        SSS::::::::SS  o::::o     o::::oC:::::C              \n");
        neorv32_uart0_printf("  P::::P                   SSSSSS::::S o::::o     o::::oC:::::C              \n");
        neorv32_uart0_printf("  P::::P                        S:::::So::::o     o::::oC:::::C              \n");
        neorv32_uart0_printf("  P::::P                        S:::::So::::o     o::::o C:::::C       CCCCCC\n");
        neorv32_uart0_printf("PP::::::PP          SSSSSSS     S:::::So:::::ooooo:::::o  C:::::CCCCCCCC::::C\n");
        neorv32_uart0_printf("P::::::::P          S::::::SSSSSS:::::So:::::::::::::::o   CC:::::::::::::::C\n");
        neorv32_uart0_printf("P::::::::P          S:::::::::::::::SS  oo:::::::::::oo      CCC::::::::::::C\n");
        neorv32_uart0_printf("PPPPPPPPPP           SSSSSSSSSSSSSSS      ooooooooooo           CCCCCCCCCCCCC\n");
        neorv32_uart0_printf("                                                                             \n");
        neorv32_uart0_printf("ASIC LAB                                                         kch.dev/psoc\n");
        neorv32_uart0_printf("#===========================================================================#\n");
        neorv32_uart0_printf("=> Running on PSOC SOC:\n");
    }
    else
    {
        if (force)
        {
            neorv32_uart0_printf("=> Not running on PSOC SOC. Stopping execution\n");
            while (true) {}
        }
        else
        {
            return false;
        }
    }

    if (PSOC_INFO_IS_ASIC(info))
    {
        uint8_t rev = PSOC_INFO_ASIC_REV(info);
        const char* name = "Unknown Revision";
        switch (rev)
        {
            case PSOC_ASIC_REV_SG13G2_FALL25:
                name = "IHP Open PDK SG13G2 180nm SiGe Tapeout 09/25";
                break;
            default:
        }
        neorv32_uart0_printf("    * ASIC Revision %d\n    * %s\n", rev, name);
    }
    else
    {
        neorv32_uart0_printf("    * FPGA Emulation\n");
    }

    // Not using SPI and PWM, use those as GPIOs
    neorv32_uart0_printf("=> Setting up IO multiplexer\n");
    IOMUX_REG_FUNC = (FUNC_I2S | FUNC_DAC | FUNC_I2C | FUNC_UART0 | FUNC_SD_D1);

    neorv32_uart0_printf("=> Setting up GPIOs\n");
    IOMUX_REG_DIR = ((DIR_OUTPUT << PSOC_LED2) | (DIR_OUTPUT << PSOC_LED3));

    neorv32_gpio_pin_set(PSOC_LED2, 1);

    return true;
}