#include <iostream>
#include <string.h>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio1.hpp"
#include "Ejercicio2.hpp"

int main() {
    
    // int lenEq = 32;
    int n = 32;
    Equipos vecEquipos[n];
    // int arreglo[8];
    Bolillero bol1[8];
    Bolillero bol2[8];
    Bolillero bol3[8];
    Bolillero bol4[8];
    
    Grupo g1[4];
    Grupo g2[4];
    Grupo g3[4];
    Grupo g4[4];
    Grupo g5[4];
    Grupo g6[4];
    Grupo g7[4];
    Grupo g8[4];
    
    // int vecRepetidos[8];
    int lenGr = 0;
    int lenBol = 0;
    
    // ***********************
    // Ejercicio 1
    // ***********************
    // Se crea el archivo
    FILE *regEquipos = fopen("Equipos.dat", "rb");
    
    // se genera el vector con los equipos
    cargarVectorEquipos(vecEquipos);
    
    // se graban los datos en el archivo en esta funcion
    // fopen repetido, el vector se graba en el archivo
    cargarArchivo(vecEquipos, n);
    // termina el ejercicio 1.
    
    // Se posiciona al principio de todo
    rewind(regEquipos);
    // ***********************
    // Ejercicio 2
    // ***********************
    // y carga los bolilleros
    cargarBolilleros(regEquipos, vecEquipos, bol1, bol2, bol3, bol4);
    // lee y muestra el contenido del archivo
//    for(int i=1; i<5; i++)
//    {
//        cout << "----------------" << endl;
//        cout << "****** BOLILLERO " << i << " ****** "<< endl;
//        cout << "----------------" << endl;
//
//        mostrar(regEquipos, i);
//        rewind(regEquipos);
//    }
    cout << "-----------------------" << endl;
    cout << "----- Bolillero 1 -----" << endl;
    cout << "-----------------------" << endl;
    for (int j=0; j < 8; j++) {
        cout << bol1[j].nombre << " ";
        cout << "(" << bol1[j].federacion << ")" << endl;
    }
    cout << "-----------------------" << endl;
    cout << "----- Bolillero 2 -----" << endl;
    cout << "-----------------------" << endl;
    for (int j=0; j < 8; j++) {
        cout << bol2[j].nombre << " ";
        cout << "(" << bol2[j].federacion << ")" << endl;
    }
    cout << "-----------------------" << endl;
    cout << "----- Bolillero 3 -----" << endl;
    cout << "-----------------------" << endl;
    for (int j=0; j < 8; j++) {
        cout << bol3[j].nombre << " ";
        cout << "(" << bol3[j].federacion << ")" << endl;
    }
    cout << "-----------------------" << endl;
    cout << "----- Bolillero 4 -----" << endl;
    cout << "-----------------------" << endl;
    for (int j=0; j < 8; j++) {
        cout << bol4[j].nombre << " ";
        cout << "(" << bol4[j].federacion << ")" << endl;
    }

    fclose(regEquipos);
    sortearFaseGrupos(bol1, bol2, bol3, bol4, g1, g2, g3, g4, g5, g6, g7, g8, lenBol, lenGr);
    
    system("PAUSE");
    return 0;
}
