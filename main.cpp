#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio 1/Ejercicio1.hpp"
#include "Ejercicio 2/Ejercicio2.hpp"
#include "Ejercicio 3/Ejercicio3.hpp"

int main() {
	
    int lenBol = 8;
    Bolilla bolillero1[lenBol];
    Bolilla bolillero2[lenBol];
    Bolilla bolillero3[lenBol];
    Bolilla bolillero4[lenBol];
    
    Grupo grupos[8];
    GenerarArchivo regGrupo;
    Consolidado vecGrupos[50];
	Consolidado gruposConsolidado;
	char opcion;
	int lenConsolidado=0;
  
    // ****************************************************** //
    // ******************** EJERCICIO 1 ********************* //
    // ****************************************************** //
    cargarBolilleros(bolillero1, bolillero2, bolillero3, bolillero4);
    consolidarEquiposEnArchivo(bolillero1, bolillero2, bolillero3, bolillero4, lenBol);
   
    mostrarBolilleros(); // este es para validar que se vean las cosas del archivo
    
    // ****************************************************** //
    // ******************** EJERCICIO 2 ********************* //
    // ****************************************************** //
    
    do {
        cout << "Presiones s para iniciar el sorteo, 0 para salir."<<endl;
        cin >> opcion;   
        if (opcion=='0') return 0;
        }while(opcion!='s');
    
	realizarSorteo(bolillero1, bolillero2, bolillero3, bolillero4, lenBol);
    
    
  	// ****************************************************** //
    // ******************** EJERCICIO 3 ********************* //
    // ****************************************************** //
    cargarGruposEnVector(vecGrupos, regGrupo, gruposConsolidado, lenConsolidado);
	mostrarOrdenamientos(vecGrupos, lenConsolidado);


	system("PAUSE");

    return 0;
}
