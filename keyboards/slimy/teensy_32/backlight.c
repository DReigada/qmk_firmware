#include "quantum.h"
#include "backlight.h"
#include <hal.h>
#include "debug.h"

#ifndef BACKLIGHT_LIMIT_VAL
#    define BACKLIGHT_LIMIT_VAL 255
#endif


static PWMConfig pwmCFG = {375000, /* PWM clock frequency  */
                           256,    /* PWM period (in ticks)*/
                           NULL,   /* Period Callback */
                           {       /* Default all channels to disabled - Channels will be configured during init */
                            {PWM_OUTPUT_DISABLED, NULL},
                            {PWM_OUTPUT_DISABLED, NULL},
                            {PWM_OUTPUT_DISABLED, NULL},
                            {PWM_OUTPUT_DISABLED, NULL}}};

void backlight_init_ports(void) {
    pwmCFG.channels[BACKLIGHT_PWM_CHANNEL - 1].mode = PWM_OUTPUT_ACTIVE_HIGH;
    pwmStart(&BACKLIGHT_PWM_DRIVER, &pwmCFG);

    backlight_set(get_backlight_level());
}

// See http://jared.geek.nz/2013/feb/linear-led-pwm
static uint16_t cie_lightness(uint16_t v) {
    if (v <= 5243)    // if below 8% of max
        return v / 9; // same as dividing by 900%
    else {
        uint32_t y = (((uint32_t)v + 10486) << 8) / (10486 + 0xFFFFUL); // add 16% of max and compare
        // to get a useful result with integer division, we shift left in the expression above
        // and revert what we've done again after squaring.
        y = y * y * y >> 8;
        if (y > 0xFFFFUL) // prevent overflow
            return 0xFFFFU;
        else
            return (uint16_t)y;
    }
}

static uint32_t rescale_limit_val(uint32_t val) {
    // rescale the supplied backlight value to be in terms of the value limit
    return (val * (BACKLIGHT_LIMIT_VAL + 1)) / 256;
}

void backlight_set(uint8_t level) {
    printf("backlight_set(level: %d)\n", level);
    if (level > BACKLIGHT_LEVELS) level = BACKLIGHT_LEVELS;

    // if min or max level use digital write
    if (level == 0) {
        writePinLow(BACKLIGHT_PIN);
        setPinOutput(BACKLIGHT_PIN);
    } else if (level == BACKLIGHT_LEVELS){
        writePinHigh(BACKLIGHT_PIN);
        setPinOutput(BACKLIGHT_PIN);
    } else {
        uint32_t duty = (uint32_t)(cie_lightness(rescale_limit_val(0xFFFF * (uint32_t)level / BACKLIGHT_LEVELS)));
        pwmEnableChannel(&BACKLIGHT_PWM_DRIVER, BACKLIGHT_PWM_CHANNEL - 1, PWM_FRACTION_TO_WIDTH(&BACKLIGHT_PWM_DRIVER, 0xFFFF, duty));
        PORTC->PCR[3] = PORTx_PCRn_SRE | PORTx_PCRn_DSE | PORTx_PCRn_MUX(4);
    }
}
