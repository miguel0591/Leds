#include "leds.h"

#define LED_OFFSET   1
#define FIRST_BIT    1
#define ALL_LEDS_OFF 0x0000;
#define ALL_LEDS_ON  0xFFFF;

static uint16_t * puerto_vitual;

static uint16_t led_to_mask(int led) {
    return (FIRST_BIT << (led - LED_OFFSET));
}

void leds_init(uint16_t * puerto) {
    puerto_vitual = puerto;
    *puerto = ALL_LEDS_OFF;
};

void leds_turn_on(uint16_t led) {
    *puerto_vitual |= led_to_mask(led);
}

void leds_turn_off(uint16_t led) {
    *puerto_vitual &= ~led_to_mask(led);
};

void leds_turn_on_all(void) {
    *puerto_vitual = ALL_LEDS_ON;
};

void leds_turn_off_all(void) {
    *puerto_vitual = ALL_LEDS_OFF;
};

uint8_t leds_status(uint16_t * puerto_vitual, uint16_t led) {
    return (*puerto_vitual & (led_to_mask(led))) ? 1 : 0;
};
