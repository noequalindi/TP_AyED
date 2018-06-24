#include <iostream>
#include <string.h>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio1.hpp"

int main() {
    
    int lenEq = 32;
    int n = 32;
    Equipos vecEquipos[n];
    int arreglo[8];
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
    
    int vecRepetidos[8];
    
    int lenGr = 0;
    int lenBol=0;
    // Se crea el archivo
    
    
    FILE *regEquipos = fopen("Equipos.dat", "rb");
    cargarVectorEquipos(vecEquipos);
    
    // se graban los datos en el archivo en esta funcion
    cargarArchivo(vecEquipos, n);
    
    // Se posiciona al principio de todo
    rewind(regEquipos);
    
    // lee y muestra el contenido del archivo
    for(int i=1; i<5; i++)
    {
        cout << "_______________ " << endl;
        cout << "****** BOLILLERO " << i << " ****** "<< endl;
        cout << "_______________ " << endl;
        
        mostrar(regEquipos, i);
        rewind(regEquipos);
        
        
    }
    
    cargarBolilleros(regEquipos, vecEquipos, bol1,bol2,bol3,bol4);
    cout << "Bolillero 1 "<< endl;
    for (int j=0; j < 8; j++)
    {
        
        cout << "_______________ " << endl;
        cout << bol1[j].nombre << endl;
        cout << bol1[j].federacion << endl;
        
    }
    cout << "Bolillero 2"<< endl;
    for (int j=0; j < 8; j++)
    {
        
        cout << "_______________ " << endl;
        cout << bol2[j].nombre << endl;
        cout << bol2[j].federacion << endl;
        
    }
    cout << "Bolillero 3 "<< endl;
    for (int j=0; j < 8; j++)
    {
        
        cout << "_______________ " << endl;
        cout << bol3[j].nombre << endl;
        cout << bol3[j].federacion << endl;
        
    }
    cout << "Bolillero 4 "<< endl;
    for (int j=0; j < 8; j++)
    {
        
        cout << "_______________ " << endl;
        cout << bol4[j].nombre << endl;
        cout << bol4[j].federacion << endl;
        
    }
    
    fclose(regEquipos);
    sortearFaseGrupos(bol1,bol2,bol3,bol4, g1,  g2, g3,  g4,  g5,  g6,     g7, g8, lenBol, lenGr);
    
    system("PAUSE");
    return 0;
}