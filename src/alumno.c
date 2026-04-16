#include <stdio.h>
#include "alumno.h"

static int serializar_texto(const char * texto, char * buffer, size_t bytes){

    int n = snprintf(buffer, bytes, "\"%s\"", texto);

        if (n < 0 || (size_t )n >= bytes)
            return -1;

    return n;
}

static int serializar_numero(int numero, char * buffer, size_t bytes){

    int n = snprintf(buffer, bytes,"%d", numero);

        if (n < 0 || (size_t)n >= bytes)
            return -1;

    return n;
}

int Serializar(const alumno_t * alumno, char * buffer, size_t bytes) {

    int offset = 0;
    int restantes = (int)bytes;
    int n;

    
    n = snprintf(buffer + offset, (size_t)restantes, "{ \"nombre\": ");

    if (n < 0 || n >= restantes) 
        return -1;

    offset += n; restantes -= n;

    n = serializar_texto(alumno->nombre, buffer + offset, restantes);

        if (n == -1) 
            return -1;
    
    offset += n; restantes -= n;

    n = snprintf(buffer + offset, (size_t)restantes, ", \"apellido\": ");

        if (n < 0 || n >= restantes) 
            return -1;

    offset += n; restantes -= n;

    
    n = serializar_texto(alumno->apellido, buffer + offset, restantes);
        
        if (n == -1) 
            return -1;
    
    offset += n; restantes -= n;

    n = snprintf(buffer + offset, (size_t)restantes, ", \"documento\": ");

        if (n < 0 || n >= restantes) 
            return -1;

    offset += n; restantes -= n;

   
    n = serializar_numero(alumno->documento, buffer + offset, restantes);

        if (n == -1) 
            return -1;

    offset += n; restantes -= n;

    
    n = snprintf(buffer + offset, (size_t)restantes, " }");

        if (n < 0 || n >= restantes) 
            return -1;
    offset += n;

    return offset;

}


