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
void leds_turn_on(uint16_t led);

/**
 * @brief Funcion para "apagar" un led
 *
 * @param led: nuevo de led que se quiere encender
 */
void leds_turn_off(uint16_t led);

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

/**
 * @brief Funcion para chequear el estado de un led determinado
 *
 * @param puerto_vitual Puerto que se quiere chequear
 * @param led Led que se quiere chequear
 * @return uint8_t retorna 1 si esta "encendido" o 0 si esta "apagado"
 */
uint8_t leds_status(uint16_t * puerto_vitual, uint16_t led);

#endif
