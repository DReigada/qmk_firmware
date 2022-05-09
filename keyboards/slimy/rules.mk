# Build Options
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration(+1000)
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality on B7 by default
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no            # MIDI support (+2400 to 4200, depending on config)
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6

# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
MOUSEKEY_ENABLE = yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes       # Audio control and System control(+450)
CONSOLE_ENABLE = yes        # Console for debug(+400)

POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball

QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS = st7789_spi

DEFAULT_FOLDER = slimy
LAYOUTS = ortho_1x1

# MCU name
MCU = MK20DX256
BOARD = IC_TEENSY_3_1
BOOTLOADER = halfkay
# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

BACKLIGHT_ENABLE = yes
BACKLIGHT_DRIVER = custom

KEYBOARD_PATH = keyboards/slimy
SRC += $(wildcard ${KEYBOARD_PATH}/*.c)
VPATH += ${KEYBOARD_PATH}

GENERATED_PATH=${KEYBOARD_PATH}/generated
SRC += $(wildcard ${GENERATED_PATH}/*.c)
VPATH += ${GENERATED_PATH}
