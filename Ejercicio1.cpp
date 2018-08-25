#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio1.hpp"

void cargarBolilleros(Bolilla bolillero1[], Bolilla bolillero2[], Bolilla bolillero3[], Bolilla bolillero4[])
{
    // ************ BOLILLERO 1 ***************
    
    strcpy(bolillero1[0].equipo.nombre, "Rusia");
    strcpy(bolillero1[0].equipo.federacion, "UEFA");
    
    strcpy(bolillero1[1].equipo.nombre, "Alemania");
    strcpy(bolillero1[1].equipo.federacion, "UEFA");
    
    strcpy(bolillero1[2].equipo.nombre, "Brasil");
    strcpy(bolillero1[2].equipo.federacion, "CONMEBOL");
    
    strcpy(bolillero1[3].equipo.nombre, "Portugal");
    strcpy(bolillero1[3].equipo.federacion, "UEFA");
    
    strcpy(bolillero1[4].equipo.nombre, "Argentina");
    strcpy(bolillero1[4].equipo.federacion, "CONMEBOL");
    
    strcpy(bolillero1[5].equipo.nombre, "Belgica");
    strcpy(bolillero1[5].equipo.federacion, "UEFA");
    
    strcpy(bolillero1[6].equipo.nombre, "Polonia");
    strcpy(bolillero1[6].equipo.federacion, "UEFA");
    
    strcpy(bolillero1[7].equipo.nombre, "Francia");
    strcpy(bolillero1[7].equipo.federacion, "UEFA");
    
    // ************ BOLILLERO 2 ***************
    
    strcpy(bolillero2[0].equipo.nombre, "Espana");
    strcpy(bolillero2[0].equipo.federacion, "UEFA");
    
    strcpy(bolillero2[1].equipo.nombre, "Peru");
    strcpy(bolillero2[1].equipo.federacion, "CONMEBOL");
    
    strcpy(bolillero2[2].equipo.nombre, "Suiza");
    strcpy(bolillero2[2].equipo.federacion, "UEFA");
    
    strcpy(bolillero2[3].equipo.nombre, "Inglaterra");
    strcpy(bolillero2[3].equipo.federacion, "UEFA");
    
    strcpy(bolillero2[4].equipo.nombre, "Colombia");
    strcpy(bolillero2[4].equipo.federacion, "CONMEBOL");
    
    strcpy(bolillero2[5].equipo.nombre, "Mexico");
    strcpy(bolillero2[5].equipo.federacion, "Concacaf");
    
    strcpy(bolillero2[6].equipo.nombre, "Uruguay");
    strcpy(bolillero2[6].equipo.federacion, "CONMEBOL");
    
    strcpy(bolillero2[7].equipo.nombre, "Croacia");
    strcpy(bolillero2[7].equipo.federacion, "UEFA");
    
    
    // ************ BOLILLERO 3 ***************
    
    strcpy(bolillero3[0].equipo.nombre, "Dinamarca");
    strcpy(bolillero3[0].equipo.federacion, "UEFA");
    
    strcpy(bolillero3[1].equipo.nombre, "Islandia");
    strcpy(bolillero3[1].equipo.federacion, "UEFA");
    
    strcpy(bolillero3[2].equipo.nombre, "Costa Rica");
    strcpy(bolillero3[2].equipo.federacion, "Concacaf");
    
    strcpy(bolillero3[3].equipo.nombre, "Suecia");
    strcpy(bolillero3[3].equipo.federacion, "UEFA");
    
    strcpy(bolillero3[4].equipo.nombre, "Tunez");
    strcpy(bolillero3[4].equipo.federacion, "CAF");
    
    strcpy(bolillero3[5].equipo.nombre, "Egipto");
    strcpy(bolillero3[5].equipo.federacion, "CAF");
    
    strcpy(bolillero3[6].equipo.nombre, "Senegal");
    strcpy(bolillero3[6].equipo.federacion, "CAF");
    
    strcpy(bolillero3[7].equipo.nombre, "Iran");
    strcpy(bolillero3[7].equipo.federacion, "AFC");
    
    
    // ************ BOLILLERO 4 ***************
    
    strcpy(bolillero4[0].equipo.nombre, "Serbia");
    strcpy(bolillero4[0].equipo.federacion, "UEFA");
    
    strcpy(bolillero4[1].equipo.nombre, "Nigeria");
    strcpy(bolillero4[1].equipo.federacion, "CAF");
    
    strcpy(bolillero4[2].equipo.nombre, "Australia");
    strcpy(bolillero4[2].equipo.federacion, "AFC");
    
    strcpy(bolillero4[3].equipo.nombre, "Japon");
    strcpy(bolillero4[3].equipo.federacion, "AFC");
    
    strcpy(bolillero4[4].equipo.nombre, "Marruecos");
    strcpy(bolillero4[4].equipo.federacion, "CAF");
    
    strcpy(bolillero4[5].equipo.nombre, "Panama");
    strcpy(bolillero4[5].equipo.federacion, "Concacaf");
    
    strcpy(bolillero4[6].equipo.nombre, "Corea del Sur");
    strcpy(bolillero4[6].equipo.federacion, "AFC");
    
    strcpy(bolillero4[7].equipo.nombre, "Arabia Saudita");
    strcpy(bolillero4[7].equipo.federacion, "AFC");
    
    return;
}
void consolidarEquiposEnArchivo(Bolilla bolillero1[], Bolilla bolillero2[], Bolilla bolillero3[], Bolilla bolillero4[], int lenBol)
{
    FILE * fileBolilleros;
    fileBolilleros = fopen("Bolilleros.dat", "wb");
    Bolilla regBolillero;
    
    for (int i = 0; i < lenBol; i++) {
        regBolillero.numBol = 1;
        strcpy(regBolillero.equipo.nombre, bolillero1[i].equipo.nombre);
        strcpy(regBolillero.equipo.federacion, bolillero1[i].equipo.federacion);
        fwrite(&regBolillero, sizeof(Bolilla), 1, fileBolilleros);
    }
    for (int i = 0; i < lenBol; i++) {
        regBolillero.numBol = 2;
        strcpy(regBolillero.equipo.nombre, bolillero2[i].equipo.nombre);
        strcpy(regBolillero.equipo.federacion, bolillero2[i].equipo.federacion);
        fwrite(&regBolillero, sizeof(Bolilla), 1, fileBolilleros);
    }
    for (int i = 0; i < lenBol; i++) {
        regBolillero.numBol = 3;
        strcpy(regBolillero.equipo.nombre, bolillero3[i].equipo.nombre);
        strcpy(regBolillero.equipo.federacion, bolillero3[i].equipo.federacion);
        fwrite(&regBolillero, sizeof(Bolilla), 1, fileBolilleros);
    }
    for (int i = 0; i < lenBol; i++) {
        regBolillero.numBol = 4;
        strcpy(regBolillero.equipo.nombre, bolillero4[i].equipo.nombre);
        strcpy(regBolillero.equipo.federacion, bolillero4[i].equipo.federacion);
        fwrite(&regBolillero, sizeof(Bolilla), 1, fileBolilleros);
    }
    fclose(fileBolilleros);
    return;
}

void mostrarBolilleros()
{
    FILE * fileBolilleros = fopen("Bolilleros.dat", "rb");
    Bolilla regBolillero;
    fread(&regBolillero, sizeof(Bolilla), 1, fileBolilleros);
    
    while (!feof(fileBolilleros))
    {
        cout << "Bolillero " << regBolillero.numBol << " -> ";
        cout << regBolillero.equipo.nombre;
        cout << " (" << regBolillero.equipo.federacion << ")" << endl;
        fread(&regBolillero,sizeof(Bolilla),1,fileBolilleros);
    }
    
    fclose(fileBolilleros);
    return;
}
