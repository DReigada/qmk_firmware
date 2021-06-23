# MCU name
MCU = MK20DX256

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
SRC += trackball.c
QUANTUM_LIB_SRC += i2c_master.c
