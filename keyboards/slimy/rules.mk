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

DEFAULT_FOLDER = slimy/teensy_32
LAYOUTS = ortho_1x1

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE -D__MK20DX256__ -DF_CPU=96000000 -DLAYOUT_US_ENGLISH -DTEENSYDUINO=200 -DUSB_SERIAL

SRC += slimy.cpp
SRC += Adafruit_GFX.cpp pins_teensy.c Print.cpp usb_inst.cpp yield.cpp
SRC += $(wildcard  keyboards/slimy/lib/Arduino-teensy/teensy3/*.cpp) $(wildcard  keyboards/slimy/lib/Arduino-teensy/teensy3/*.c)
SRC += $(wildcard  keyboards/slimy/lib/SPI/*.cpp)
SRC += $(wildcard  keyboards/slimy/lib/Adafruit-ST7735/*.cpp)
SRC += Adafruit_GFX.cpp Adafruit_SPITFT.cpp
VPATH += keyboards/slimy/lib/Arduino-teensy/teensy3
VPATH += keyboards/slimy/lib/Adafruit-GFX
VPATH += keyboards/slimy/lib/Adafruit-ST7735
VPATH += keyboards/slimy/lib/SPI
# LIB_SRC += Adafruit_GFX.cpp
