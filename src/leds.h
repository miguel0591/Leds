#ifndef LEDS_H
#define LEDS_H

#include "stdint.h"

/**
 * @brief Inicializacion de los led
 *
 *
 * @param puerto : direccion de memoria donde se encuentan los Leds
 */
void leds_init(uint16_t * puerto);

/**
 * @brief Funcion para "encender" un led
 *
 * @param led : nuevo de led que se quiere encender
 */
void leds_turn_on(int led);

/**
 * @brief Funcion para "apagar" un led
 *
 * @param led: nuevo de led que se quiere encender
 */
void leds_turn_off(int led);

/**
 * @brief Funcion para "encender" todos los leds juntos.
 *
 * @note La funcion no necesita ningun pararametro.
 *
 */
void leds_turn_on_all(void);

/**
 * @brief Funcion para "apagar" todos los leds juntos.
 *
 * @note La funcion no necesita ningun pararametro.
 */
void leds_turn_off_all(void);

#endif
