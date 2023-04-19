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

/** \brief Segundo trabajo practico
 **
 ** \addtogroup tp2 TPN2 main
 ** \brief Genera una estructura con el nombre, el apellido y el dni del alumno, ademas llama a la funcion serializar.
 ** @see main()
 ** @{ */

/* === Headers files inclusions =============================================================== */

#include "alumno.h"
#include <stdio.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */
/**
 * @brief Crea una estructura estatic con valores de tipo alumno_s y llama a la fucion serializar.
 * 
 * Muestra por el termina los datos del alumno en formato .json o un aviso de error si no se pudo ejecutar la funcion correctamente.
 * @return int
 */
int main(void){
// pone los datos en flash
   static struct alumno_s yo = {
      .apellido = "Rivas",
      .nombre = "Pablo",
      .dni = 35933178,
   };
   //pone los datos en ram -> pila
   // strncpy(yo.apellido, "Rivas", sizeof(yo.apellido)); 
   // strncpy(yo.nombre, "Pablo", sizeof(yo.nombre));
   char cadena[128];

   if (Serializar(&yo, cadena, sizeof(cadena)) >= 0) {
      printf("%s\n", cadena);
   }
   else {
      printf("Error al serializar\n");
   }

   return 0;
}
/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
