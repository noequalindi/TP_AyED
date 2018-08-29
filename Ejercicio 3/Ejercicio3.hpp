#ifndef Ejercicio3_hpp
#define Ejercicio3_hpp

#include <stdio.h>
#include "../structs.hpp"


void cargarGruposEnVector(Consolidado vec[], GenerarArchivo regGrupo, Consolidado gruposConsolidado, int &lenConsolidado);
int insertarOrdenado(Consolidado vecGrupos[], int &lenGrupos, Consolidado gruposConsolidado);
void insertar(Consolidado vecGrupos[], int &lenGrupos, GenerarArchivo regGrupo, int pos);
void mostrarVectorGruposConsolidado(Consolidado vec[], int len);
void ordenaVectorPorFederacion(Consolidado vec[], int len);
void ordenaVectorPorNombre(Consolidado vec[], int len);
void ordenaVectorPorGrupo(Consolidado vec[], int len);
void mostrarOrdenamientos(Consolidado vecGrupos[], int lenConsolidado);

#endif /* Ejercicio2_hpp */
