# Add include path for library
APP_INC += -I $(PSOC_LIB_HOME)/include

# Compile all the sources
APP_SRC += $(wildcard $(PSOC_LIB_HOME)/source/*.c)

# Set ROM base address for XIP execution
USER_FLAGS += -Wl,--defsym=__neorv32_rom_base=0xE0000000