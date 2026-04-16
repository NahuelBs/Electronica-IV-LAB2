#include <stdio.h>
#include "alumno.h"

#define BUFFER_SIZE 100

int main (void){

    alumno_t alumno = {.apellido = "Blanco Suarez", .nombre = "Nahuel Ernesto", .documento = 42365688
    };

    char resultado [BUFFER_SIZE];
    int retorno = Serializar(&alumno, resultado, BUFFER_SIZE);
        
    if (retorno == -1) {

        printf("Error: espacio insuficiente\n");

    } 
    else 
    {
        printf("%s\n", resultado);
    }

    return 0;
}

