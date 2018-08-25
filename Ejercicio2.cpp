#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio2.hpp"

void realizarSorteo(Bolilla bolillero1[], Bolilla bolillero2[], Bolilla bolillero3[], Bolilla bolillero4[], int lenBol) {
    
    // seed para el random
    srand (time(NULL));

    // Cada grupo es una letra + los asignados + un array de bolillas
    Grupo grupos[8];
    
    // A, B, C, D, E, F, G, H
    asignarLetras(grupos);
    // uso un auxiliar para el random
    int aleatorioAux = 0;
    
    // mantengo un nivel para que se llenen parejos
    int nivel = 0;
    
    // asigno Rusia de una
    grupos[0].bolilla[0] = bolillero1[0];
    grupos[0].asignados += 1;
    
    // primer bolillero
    cout << "procesando primer bolillero" << endl;
    for(int i = 1; i < lenBol; i++) {
        // grupos puede ser cualquiera entre 0 y 7
        aleatorioAux = rand() % lenBol;
        cout << i << ") buscando equipo para: " << bolillero1[i].equipo.nombre << " (" << bolillero1[i].equipo.federacion << ") -> ";
        
        while (grupos[aleatorioAux].asignados > nivel && !validacion(bolillero1[i], grupos[aleatorioAux])) {
            aleatorioAux = rand() % lenBol;
        }
        
        cout << "encontrado grupo: " << grupos[aleatorioAux].letra;
        cout << " (queda con " << grupos[aleatorioAux].asignados + 1 << " integrantes)" << endl;
        grupos[aleatorioAux].bolilla[grupos[aleatorioAux].asignados] = bolillero1[i];
        grupos[aleatorioAux].asignados++;
    }
    nivel++;
    
    cout << "procesando segundo bolillero" << endl;
    // segundo bolillero
    for(int i = 0; i < lenBol; i++) {
        aleatorioAux = rand() % lenBol;
        cout << i << ") buscando equipo para: " << bolillero2[i].equipo.nombre << " (" << bolillero2[i].equipo.federacion << ") -> ";
        
        while (grupos[aleatorioAux].asignados > nivel && !validacion(bolillero2[i], grupos[aleatorioAux])) {
            aleatorioAux = rand() % lenBol;
        }
        
        cout << "encontrado grupo: " << grupos[aleatorioAux].letra;
        cout << " (queda con " << grupos[aleatorioAux].asignados + 1 << " integrantes)" << endl;
        
        grupos[aleatorioAux].bolilla[grupos[aleatorioAux].asignados] = bolillero2[i];
        grupos[aleatorioAux].asignados++;
    }
    nivel++;
    
    cout << "procesando tercer bolillero" << endl;
    // tercer bolillero
    for(int i = 0; i < lenBol; i++) {
        aleatorioAux = rand() % lenBol;
        cout << i << ") buscando equipo para: " << bolillero3[i].equipo.nombre << " (" << bolillero3[i].equipo.federacion << ") -> ";
        
        while (grupos[aleatorioAux].asignados > nivel && !validacion(bolillero3[i], grupos[aleatorioAux])) {
            aleatorioAux = rand() % lenBol;
        }
        
        cout << "encontrado grupo: " << grupos[aleatorioAux].letra;
        cout << " (queda con " << grupos[aleatorioAux].asignados + 1 << " integrantes)" << endl;
        
        grupos[aleatorioAux].bolilla[grupos[aleatorioAux].asignados] = bolillero3[i];
        grupos[aleatorioAux].asignados++;
    }
    nivel++;
    
    cout << "procesando cuarto bolillero" << endl;
    // cuarto bolillero
    for(int i = 0; i < lenBol; i++) {
        aleatorioAux = rand() % lenBol;
        cout << i << ") buscando equipo para: " << bolillero4[i].equipo.nombre << " (" << bolillero4[i].equipo.federacion << ") -> ";
        
        while (grupos[aleatorioAux].asignados > nivel && !validacion(bolillero4[i], grupos[aleatorioAux])) {
            aleatorioAux = rand() % lenBol;
        }
        
        cout << "encontrado grupo: " << grupos[aleatorioAux].letra;
        cout << " (queda con " << grupos[aleatorioAux].asignados + 1 << " integrantes)" << endl;
        
        grupos[aleatorioAux].bolilla[grupos[aleatorioAux].asignados] = bolillero4[i];
        grupos[aleatorioAux].asignados++;
    }
    
    mostrarGrupos(grupos);
}

void asignarLetras(Grupo grupos[]) {
    grupos[0].letra = 'A';
    grupos[1].letra = 'B';
    grupos[2].letra = 'C';
    grupos[3].letra = 'D';
    grupos[4].letra = 'E';
    grupos[5].letra = 'F';
    grupos[6].letra = 'G';
    grupos[7].letra = 'H';
    
    for (int i = 0; i < 8; i++) {
        grupos[i].asignados = 0;
    }
}

bool validacion(Bolilla bolilla, Grupo grupo) {
    bool uefaFlag = false;
    
    if(grupo.asignados >= 4) {
        return false;
    }
    
    for (int i = 0; i < grupo.asignados; i++) {
        
        // si es UEFA
        if (strncmp(bolilla.equipo.federacion, "UEFA", 3) == 0) {
            if (strncmp(bolilla.equipo.federacion, grupo.bolilla[i].equipo.federacion, 3) == 0) {
                // si es UEFA y ya había encontrado otro en el grupo (bandera)
                if (uefaFlag) {
                    return false;
                // si no, levanto la bandera porque encontré uno de UEFA
                } else {
                    uefaFlag = true;
                }
            }
        // es cualquier otra federación, comparo que no haya otro de la misma federación
        } else if (strncmp(bolilla.equipo.federacion, grupo.bolilla[i].equipo.federacion, 3) == 0) {
            return false;
        }
    }
    
    return true;
}

void mostrarGrupos(Grupo grupos[])
{
    for (int i = 0; i < 8; i++) {
        cout << "GRUPO " << grupos[i].letra << endl;
        for (int j = 0; j < 4; j++) {
                cout << "EQUIPO " << grupos[i].bolilla[j].equipo.nombre << endl;
        }
    }
}
