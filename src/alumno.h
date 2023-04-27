/************************************************************************************************
Copyright (c) 2023, Pablo Rivas

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
associated documentation files (the "Software"), to deal in the Software without restriction,
including without limitation the rights to use, copy, modify, merge, publish, distribute,
sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial
portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

SPDX-License-Identifier: MIT
*************************************************************************************************/
/**
 * @file alumno.h
 * @version 1.0.0
 * @date 14/4/2023
 * @author Pablo Rivas 
 * @brief Contiene la declaracion de la funcion serializar y un tipo de dato estructura del alumno
 * \see Serializar()
*/
#ifndef TEMPLATE_H
#define TEMPLATE_H

/** \brief Declaraciones publicas del modulo de alumnos
 **
 ** \addtogroup alumno Alumno
 ** \brief Modulo para gestion de aulumno
 ** @{ */

/* === Headers files inclusions ================================================================ */

/* === Cabecera C++ ============================================================================ */

#ifdef __cplusplus
extern "C" {
#endif

/* === Public macros definitions =============================================================== */

#include <stdint.h>
/**
 * @brief Define el tamaño de los parametros de los campos de texto
 * 
 * Este parametro define el tamaño de los campos de texto de la estrucctura alumno_t
*/
#define FIELD_SIZE 50//!<parametro para cadenas
#define CANTIDAD_PERSONAS 5//!<parametro para determinar el numero de personas
#define MODO_CREACION 1 //! 1 para estatica o cualquier otra cosa para que sea dinamica
/* === Public data type declarations =========================================================== */
/**
 * @brief Define un tipo de estuctura utilizada.
 * 
 */
typedef struct alumno_s * alumno_t;

/* === Public variable declarations ============================================================ */

/* === Public function declarations ============================================================ */
/**
 * @brief Crea un alumno
 * 
 * @param apellido envia un puntero de la cadena apellido
 * @param nombre  envia un puntero de la cadena del nombre
 * @param documento envia un entero
 * @return alumno_t regresa un puntero a la estructura creada
 */
alumno_t CrearAlumno(char * apellido, char * nombre, int documento); //pasa parametros para crear un un alumno
/**
 * @brief Encadena el nombre, el apellido y el dni  en un formato tipo .json
 * 
 * @param alumno Envia un puntero al incio de la estructura
 * @param cadena Evia un puntero para almacenar la salida
 * @param espacio Envia el tamaño que puede ocupar la cadena
 * @return int
 * 
*/
int Serializar(alumno_t alumno, char cadena[], uint32_t espacio);// serializa los datos obtenidos
/**
 * @brief Get the Estructura object
 * 
 * Debuelve el puntero del alumno generado en forma estatica
 *  
 * @param alumno envia el puntero del primer alumno
 * @param alumno_posicion envia la posicion del alumno que se quiere obtener
 * @param estado envia un puntero a un entero para usar determinar si la estructura tiene algun alumno
 * @return alumno_t debuelve el puntero solicitado al alumno(estructura)
 */
alumno_t GetEstructura(alumno_t alumno, int alumno_posicion, int *estado);
/**
 * @brief elimina un alumno 
 * 
 * @param alumno envia un puntero a la estuctura a eliminar
 * @param alumno_posicion envia la posicion del alumno a eliminar
 * @return int retorna un entero sin importancia
 */
int  EliminarAlumno(alumno_t alumno, int alumno_posicion);

 /* === End of documentation ==================================================================== */

#ifdef __cplusplus
}
#endif

/** @} End of module definition for doxygen */

#endif /* TEMPLATE_H */