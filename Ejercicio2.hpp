#ifndef Ejercicio2_hpp
#define Ejercicio2_hpp

#include <stdio.h>
#include "structs.hpp"

int generarNumeroAleatorio();
void cargarBolilleros(FILE *f, Equipos vec[], Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[]);
void sortearFaseGrupos(Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[], Grupo g1[], Grupo g2[],Grupo g3[], Grupo g4[], Grupo g5[], Grupo g6[], Grupo g7[], Grupo g8[], int lenBol, int lenGr);

#endif /* Ejercicio2_hpp */
