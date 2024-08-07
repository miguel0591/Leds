/**
 * @file leds.c
 * @author Blanco Miguel Manuel (miguelmanuelblanco@gmail.com)
 * @brief Archivo fuente de "Driver leds usando TDD".
 * @version 0.1
 * @date 2024-07-04
 *
 * @copyright Copyright (c) 2024
 */
/* === Including header files  ================================================================= */
#include "leds.h"

/* === Public macros definitions =============================================================== */
#define LED_OFFSET   1 ///< @brief Los leds se cuenta de 1-16, pero los bits de 0-15 (offset 1).
#define FIRST_BIT    1 ///< @brief Valor que se luego se desplaza para formar la mascara.
#define ALL_LEDS_OFF 0x0000; ///< @brief Valor del puerto para que todos los leds esten apagados.
#define ALL_LEDS_ON  0xFFFF; ///< @brief Valor del puerto para que todos los leds esten encendidos.

/* === Private variable declarations =========================================================== */
static uint16_t * puerto_vitual; ///< @brief Variable privada puerto virtual.

/* === Private function declarations ============================================================ */
/**
 * @brief Funcion para crear un mascara para los leds.
 *
 * @param led posicion del led que se quiere enmascarar.
 * @return uint16_t mascara conformada.
 */
static uint16_t led_to_mask(int led) {
    return (FIRST_BIT << (led - LED_OFFSET));
}

/* === Public function declarations ============================================================ */
void leds_init(uint16_t * puerto) {
    puerto_vitual = puerto;
    leds_turn_off_all();
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
