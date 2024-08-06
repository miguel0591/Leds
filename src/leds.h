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
 * @brief Funcion pra "apagar" un led
 *
 * @param led: nuevo de led que se quiere encender
 */
void leds_turn_off(int led);

#endif
