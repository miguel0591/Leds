/**
 * @file test_led.c
 * @author Blanco Miguel Manuel (miguelmanuelblanco@gmail.com)
 * @brief Archivo fuente de los Test para "Driver leds usando TDD".
 * @version 0.1
 * @date 2024-07-04
 *
 * @copyright Copyright (c) 2024
 */
/* === Including header files  ================================================================= */
#include "unity.h"
#include "leds.h"

uint16_t puerto_virtual;

/**
 * @brief Configuracion Inicial para las pruebas.
 *
 * Este codigo de ejecuta antes de cada prueba, en este caso solo inicializamos el puerto con todos
 * los leds apagados.
 *
 */
void setUp(void) {
    leds_init(&puerto_virtual);
}

/**
 * @brief Primer Test: Todos los Leds arrancan apagados
 *
 * <ul>
 *   <li>Paso 1: Inicializamos el puerto entrada salida en 0xFFFF (todos encendidos).</li>
 *   <li>Paso 2: Llamo a led_init y le paso por referencia ya que no conozco la direccion de
 * memoria.</li>
 *   <li>Paso 3: Checkeo que la funcion probadada de el resultado esperado, es decir
 * pasar puerto virtual de 0xFFFF a 0x0000.</li>
 * </ul>
 *
 */
void test_todos_los_leds_deben_arrancar_apagados(void) {
    uint16_t puerto_virtual = 0xffff;
    leds_init(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual); //
}

/**
 * @brief Segundo Test: Despues de arrancar el sistema, con todos los leds apagados, voy a prender
 * un led cualquiera.
 *
 * <ul>
 *   <li>Paso 1: Usamos la funcion leds_turn_on para endender el tercer led.</li>
 *   <li>Paso 2: Chequemos el resultado esperado sobre le puerto.</li>
 * </ul>
 */
void test_prender_un_solo_led(void) {
    leds_turn_on(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 2, puerto_virtual);
}

/**
 * @brief Tercer Test: Voy a prender un led y volver a apagarlo para ver si se apaga correctamente.
 *
 * <ul>
 *   <li>Paso 1: Enciendo el led (3), usando la funcion de encendido (ya probada en la prueba
 * 2).</li>
 *   <li>Paso 2: Apago el led (3), usando la funcion de apagado que queremos probar.</li>
 *   <li>Paso 3: Chequemos el resultado esperado sobre le puerto.</li>
 * </ul>
 */
void test_apagar_un_solo_led(void) {
    leds_turn_on(3);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Cuarto Test: Prender dos leds, apagar uno, y ver que solo se apaga el que corresponde y
 * que el otro sigue prendido
 *
 * <ul>
 *   <li>Paso 1: Enciendo el led (3), usando la funcion de encendido (ya probada en la prueba
 * 2).</li>
 *   <li>Paso 2: Enciendo el led (7), usando la funcion de encendido (ya probada en la prueba
 * 2).</li>
 *   <li>Paso 3: Apago el led (3), usando la funcion de apagado.</li>
 *   <li>Paso 4: Chequemos el resultado esperado sobre le puerto (es decir, que solo este prendido
 * el led 7).</li>
 * </ul>
 */
void test_prender_dos_leds_y_apagar_un_solo_led(void) {
    leds_turn_on(3);
    leds_turn_on(7);
    leds_turn_off(3);
    TEST_ASSERT_EQUAL_HEX16(1 << 6, puerto_virtual);
}

/**
 * @brief Quinto Test: Encender todos los leds a la vez.
 *
 * <ul>
 *   <li>Paso 1: Se uso la funcion para encender todos los leds.</li>
 *   <li>Paso 2: Chequeo si el valor del puerto virtual, tiene el valor correcto.</li>
 * </ul>
 */
void test_prender_todos_los_leds_juntos(void) {
    leds_turn_on_all();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

/**
 * @brief Sexto Test: Prender y apagar todos los leds juntos
 *
 * <ul>
 *   <li>Paso 1: Se uso la funcion para "encender" todos los leds(ya probada en el test 5).</li>
 *   <li>Paso 2: Se uso la funcion para "apagar" todos los leds.</li>
 *   <li>Paso 3: Se chequeo si el puerto virtual tiene el valor correcto.</li>
 * </ul>
 */
void test_prender_y_apagar_todos_los_leds_juntos(void) {
    leds_turn_on_all();
    leds_turn_off_all();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

/**
 * @brief Septimo Test: Prender un led, voy a consultar el estado y tiene que figurar como prendido.
 *
 * <ul>
 *   <li>Paso 1: Se uso la funcion para "encender" todos los leds(ya probada en el test 5).</li>
 *   <li>Paso 2: Se uso la funcion para "apagar" todos los leds.</li>
 *   <li>Paso 3: Se chequeo el valor de retorno es correcto.</li>
 *   <li>Paso 4: Se chequeo si el puerto virtual tenga el valor correcto.</li>
 * </ul>
 */
void test_preder_un_led_y_consultar_su_estado(void) {
    uint8_t status = 3;
    leds_turn_on(4);
    status = leds_status(&puerto_virtual, 4);
    TEST_ASSERT_EQUAL_HEX16(0x0001, status);
    TEST_ASSERT_EQUAL_HEX16(1 << 3, puerto_virtual);
}

/**
 * @brief Octavo Test: Consultar el estado de un led apagado y tiene que figurar como apagado.
 * <ul>
 *   <li>Paso 1: Enciendo todos los leds.</li>
 *   <li>Paso 2: Apago un led determinado.</li>
 *   <li>Paso 3: Se chequeo el valor de retorno es correcto.</li>
 *   <li>Paso 4: Se chequeo si el puerto virtual tenga el valor correcto.</li>
 * </ul>
 */
void test_consultar_estado_de_led_apagado_y_tiene_que_estar_apagado(void) {
    uint8_t status = 3;
    leds_turn_on_all();
    leds_turn_off(4);
    status = leds_status(&puerto_virtual, 4);
    TEST_ASSERT_EQUAL_HEX16(0x0000, status);
    TEST_ASSERT_EQUAL_HEX16(0xFFF7, puerto_virtual);
}
