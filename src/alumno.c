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

/** \brief Implementacion del modulo de alumnos
 **
 ** \addtogroup alumno Alumno
 ** \brief Modulo para gestion de aulumno
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "alumno.h"
#include <stdio.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

static int SerializarCadena();

static int SerializarNumero();

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */
/**
 * @brief Puncion privada que encadena el nombre y el apellido.
 * 
 * @param campo Puntero a una cadena que teiene el nombre del campo [in].
 * @param valor Puntero al comienzo de la cadena con el valor en la estructura [in].
 * @param cadena Puntero de la cadena [out].
 * @param espacio Valor que determina cuanto espacio queda para almacenar [out].
 * @return int Retorna un valor -1 si no se pudo ejecutar correctamente [out].
 */

static int SerializarCadena(const char * campo, const char * valor, char * cadena, int espacio) {

   return snprintf(cadena, espacio, "\"%s\":\"%s\",", campo, valor);
}
/**
 * @brief Puncion privada que encadena el numero de documento.
 * 
 * @param campo Puntero a una cadena que teiene el nombre del campo [in].
 * @param valor Valor del campo en la estructura [in].
 * @param cadena Puntero de la cadena [out].
 * @param espacio Valor que determina cuanto espacio queda para almacenar [out].
 * @return int Retorna un valor -1 si no se pudo ejecutar correctamente [out].
 */
static int SerializarNumero(const char * campo, int valor, char * cadena, int espacio) {

   return snprintf(cadena, espacio, "\"%s\":\"%d\",", campo, valor);
}

/* === Public function implementation ========================================================== */
/**
 * @brief Llama a sub-funciones 
 * @see SerializarCadena() 
 * @see SerializarNumero()
 * 
 * Maneja la implementacion de los corchete y el espacio disponible en la cadena de salida.
 * 
 * @param alumno Estructura con los datos del alumno.
 * @param cadena Puntero a la caden de salida por terminal.
 * @param espacio Pamaño maximo de la cadena.
 * @return int Retorna un valor -1 si no se pudo ejecutar correctamente.
 */

int Serializar(alumno_t alumno, char cadena[], uint32_t espacio){
   int resultado;
   int disponible = espacio;

   cadena[0] = '{';
   cadena++;
   disponible--;

   resultado = SerializarCadena("apellido", alumno->apellido, cadena, disponible);
   if(resultado > 0) {
      disponible -= resultado;
      cadena += resultado;
      resultado = SerializarCadena("nombre", alumno->nombre, cadena, disponible);
   }
   if(resultado > 0) {
      disponible -= resultado;
      cadena += resultado;
      resultado = SerializarNumero("dni", alumno->dni, cadena, disponible);
   }
   if (resultado > 0) {
      cadena += resultado;
      *(cadena - 1) = '}';
      resultado = espacio - disponible;
   }

   return resultado;
}

/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
