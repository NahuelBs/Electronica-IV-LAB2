#ifndef ALUMNO_H_
#define ALUMNO_H_

#define MAX_STR 30

typedef struct alumno_s{

    char nombre [MAX_STR];
    char apellido [MAX_STR];
    int documento;

} alumno_t;

int Serializar(const alumno_t * alumno, char * buffer, size_t bytes);

#endif