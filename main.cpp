#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio1.hpp"
#include "Ejercicio2.hpp"

int main() {
	
    int lenBol = 8;
    Bolilla bolillero1[lenBol];
    Bolilla bolillero2[lenBol];
    Bolilla bolillero3[lenBol];
    Bolilla bolillero4[lenBol];
    
    // ****************************************************** //
    // ******************** EJERCICIO 1 ********************* //
    // ****************************************************** //
    cargarBolilleros(bolillero1, bolillero2, bolillero3, bolillero4);
    consolidarEquiposEnArchivo(bolillero1, bolillero2, bolillero3, bolillero4, lenBol);
    // este es para validar
    mostrarBolilleros();
    
    // ****************************************************** //
    // ******************** EJERCICIO 2 ********************* //
    // ****************************************************** //
    realizarSorteo(bolillero1, bolillero2, bolillero3, bolillero4, lenBol);
    
    return 0;
}
