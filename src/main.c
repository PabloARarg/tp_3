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
#include <stdlib.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

/* === Public variable definitions ============================================================= */

/* === Private variable definitions ============================================================ */

/* === Private function implementation ========================================================= */

/* === Public function implementation ========================================================== */
/**
 * @brief Crea un menu ppara ingresar datos del alumno  y llama a la fucion CrearAlumno y serializar.
 * 
 * Muestra por el termina los datos del alumno en formato .json o un aviso de error si no se pudo ejecutar la funcion correctamente. 
 *
 * @return int
 */
int main(void){
   alumno_t alumno_num = 0; //!<almacena la direccion de memoria del primer elemento del arreglo de estructuras
   char apellido_temp[20];
   char nombre_temp[20];
   char cadena[128]; //!<almacena provisoriamente el los datos en .json
   int i = 0;
   int estado = 0;
   //ingresa al menu
   while (1)
   {
      int opcion;
      printf("\n1-> Crear un alumno\n2-> Mostrar alumnos\n3-> Eliminar alumno\n4-> Salir\n<- ");
      scanf("%d",&opcion);
      switch (opcion)
      {
      case 1:
// llena datos de alumnos y crea un alumno
         printf("Escribe el apellido:\n");
         scanf("%s", apellido_temp);
         printf("Escribe el nombre:\n");
         scanf("%s", nombre_temp);
         printf("Escribe el DNI:\n");
         scanf("%d", &i);
         alumno_num = CrearAlumno(apellido_temp, nombre_temp, i); //pasa parametros para crear un un alumno
         break;
// muestra los datos del alumno
      case 2:
         i = 0;
         while (i < CANTIDAD_PERSONAS)
         {
            GetEstructura(alumno_num, i, &estado);
            if (estado > 0)
            {
               printf("slot %d -> ", i);
               if (Serializar(GetEstructura(alumno_num, i, &estado), cadena, sizeof(cadena)) >= 0) {
                  printf("%s\n", cadena);
               }
               else {
                  printf("Error al serializar\n");
               }
            }            
            i++;
         }        
         break;
// elimana a un alumno
      case 3:
      i = 0;
      GetEstructura(alumno_num, i, &estado);
      if (estado != 2)
      {
         printf("Cual es el slot que ocupa?\n<- ");
         scanf("%d", &i);
         EliminarAlumno(alumno_num, i);
      }
         break;
// sale del programa
      case 4:
         exit (0);
         break;
// muestra un mensaje para una opcion no valida
      default:
         printf("\n Intenta otra vez mostro!!! \n");
         break;
      }

   }

   return 0;
}
/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
