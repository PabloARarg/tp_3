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
#include <stdlib.h>
#include <stdbool.h>// Booleanos
#include <string.h>

/* === Macros definitions ====================================================================== */

/* === Private data type declarations ========================================================== */
struct alumno_s 
{
   char apellido[FIELD_SIZE]; //!< Almacena el apellido
   char nombre[FIELD_SIZE]; //!< Almacena el Nombre
   uint32_t dni; //!< Almacena el dni
   int alocado; //!< Determina si esta ocupado en el arreglo de estructuras
} ;

/* === Private variable declarations =========================================================== */

/* === Private function declarations =========================================================== */

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
//llena los campos de la estructura
alumno_t CrearAlumno(char * apellido, char * nombre, int documento){
alumno_t resultado;
#if (MODO_CREACION==1)

   static struct alumno_s alumnos[CANTIDAD_PERSONAS] = {0}; //define un arreglo de estructuras
   int aux = 2;
   while (aux < CANTIDAD_PERSONAS)
      {
         if (alumnos[aux].alocado == false)
         {
            strcpy(alumnos[aux].apellido, apellido);
            strcpy(alumnos[aux].nombre, nombre);
            alumnos[aux].dni = documento;
            alumnos[aux].alocado = true;
            printf("SUPEER!!! se guardo la direccion del slot %d\n", aux-1);
            break;
         }
         aux++;
      }
   resultado = &alumnos[1];

#else
   alumno_t alumnos_p[CANTIDAD_PERSONAS] = {0};
   resultado = malloc(sizeof(struct alumno_s));
   strcpy(resultado->apellido, apellido);
   strcpy(resultado->nombre, nombre);
   resultado->dni = documento;
   resultado->alocado = 2;
   printf("SUPEER!!! se creo un alumno de forma dinamica \n");
   aux

#endif
   return resultado;
}
// implementacion de la fn para obtener el apellido y el nombre del alumno
int GetCompleto(alumno_t alumno, char cadena[], uint32_t espacio){

   snprintf(cadena, espacio, " ", alumno->nombre, alumno->apellido);
   return 0;
}
//implementacion de la fn para obtener el documento del alumno
int GetDocumento(alumno_t alumno){
   int aux;
   aux = alumno->dni;
    //deberia retornar null
   return aux;
}
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
   
   // int i = 0;
   // alumno_t alumno;
   // printf("\napellido es %s\n el nombre es %s\ndni es %d\n", alumno->apellido, alumno->nombre, alumno->dni);
   // printf("%p %p\n", alumno, alumno_root);
   // alumno = &alumno_root[i];

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

// debuelve el puntero del alumno generado en forma estatica en alguna posicion

alumno_t GetEstructura(alumno_t alumno, int alumno_posicion, int *estado){
   alumno_t aux;
      if (alumno[alumno_posicion].alocado == 1)
      {
         aux = &alumno[alumno_posicion];
         *estado = 1;
      }
      else if (alumno[alumno_posicion].alocado == 2)
      {
         aux = alumno;
         *estado = 2;
      }
      
      else
      {
         aux = alumno;
         *estado = 0;
      }      
   return aux;
}

int  EliminarAlumno(alumno_t alumno, int alumno_posicion){
   alumno[alumno_posicion].alocado = false;
   printf("SUPEER!!! se elimino el slot %d\n", alumno_posicion);
   return 0;
}
/* === End of documentation ==================================================================== */

/** @} End of module definition for doxygen */
