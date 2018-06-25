#ifndef Ejercicio2_hpp
#define Ejercicio2_hpp

#include <stdio.h>
#include "structs.hpp"

void realizarSorteo(Bolilla bolillero1[], Bolilla bolillero2[], Bolilla bolillero3[], Bolilla bolillero4[], int lenBol);
void asignarLetras(Grupo grupos[]);
bool validacion(Bolilla bolilla, Grupo &grupo);
void insertarUltimoEnGrupo(Bolilla bolilla, Grupo &grupo);

#endif /* Ejercicio2_hpp */
