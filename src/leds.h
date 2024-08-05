#ifndef LEDS_H
#define LEDS_H

#include "stdint.h"

/**
 * @brief Inicializacion de los led
 *
 * @note Todos los Leds deben iniciar apagados
 *
 * @param puerto : direccion de memoria donde se encuentan los Leds
 */
void leds_init(uint16_t * puerto);
void leds_turn_on(int led);
void leds_turn_off(int led);

#endif
