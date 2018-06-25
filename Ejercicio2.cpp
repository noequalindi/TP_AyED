#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio2.hpp"

void realizarSorteo(Bolilla bolillero1[], Bolilla bolillero2[], Bolilla bolillero3[], Bolilla bolillero4[], int lenBol) {
    // Cada grupo es una letra + los asignados + un array de bolillas
    Grupo grupos[8];
    
    // A, B, C, D, E, F, G, H
    asignarLetras(grupos);
    // uso un auxiliar para el random
    int aleatorioAux = 0;
    // voy guardando del bolillero los que todavía no asigné
    
    // asigno Rusia de una
    grupos[0].bolilla[0] = bolillero1[0];
    grupos[0].asignados = grupos[0].asignados + 1;
    
    // primer bolillero
    cout << "procesando primer bolillero" << endl;
    for(int i = 1; i < lenBol; i++) {
        aleatorioAux = rand() % lenBol;
        
        // la validación debería ver si el grupo está completo
        // y si hay 2 UEFA o 1 de cualquier otra federación
        while (!validacion(bolillero1[i], grupos[aleatorioAux])) {
            aleatorioAux = rand() % lenBol;
        }
        
        insertarUltimoEnGrupo(bolillero1[i], grupos[aleatorioAux]);
    }
    
    cout << "procesando segundo bolillero" << endl;
    // segundo bolillero
    for(int i = 0; i < lenBol; i++) {
        aleatorioAux = rand() % lenBol;
        
        // la validación debería ver si el grupo está completo
        // y si hay 2 UEFA o 1 de cualquier otra federación
        while (!validacion(bolillero2[i], grupos[aleatorioAux])) {
            aleatorioAux = rand() % lenBol;
        }
        
        insertarUltimoEnGrupo(bolillero2[i], grupos[aleatorioAux]);
    }
    
    cout << "procesando tercer bolillero" << endl;
    // tercer bolillero
    for(int i = 0; i < lenBol; i++) {
        aleatorioAux = rand() % lenBol;
        
        // la validación debería ver si el grupo está completo
        // y si hay 2 UEFA o 1 de cualquier otra federación
        while (!validacion(bolillero3[i], grupos[aleatorioAux])) {
            aleatorioAux = rand() % lenBol;
        }
        
        insertarUltimoEnGrupo(bolillero3[i], grupos[aleatorioAux]);
    }
    
    cout << "procesando cuarto bolillero" << endl;
    // cuarto bolillero
    for(int i = 0; i < lenBol; i++) {
        aleatorioAux = rand() % lenBol;
        
        // la validación debería ver si el grupo está completo
        // y si hay 2 UEFA o 1 de cualquier otra federación
        while (!validacion(bolillero4[i], grupos[aleatorioAux])) {
            aleatorioAux = rand() % lenBol;
        }
        
        insertarUltimoEnGrupo(bolillero4[i], grupos[aleatorioAux]);
    }
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

bool validacion(Bolilla bolilla, Grupo &grupo) {
    bool uefaFlag = false;
    
    if(grupo.asignados >= 4) {
        return false;
    }
    
    for (int i = 0; i < grupo.asignados; i++) {
        
        // si es UEFA
        if (strncmp(bolilla.equipo.federacion, "UEFA", 3) == 0) {
            if (strncmp(bolilla.equipo.federacion, grupo.bolilla[i].equipo.federacion, 3)) {
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

void insertarUltimoEnGrupo(Bolilla bolilla, Grupo &grupo) {
    grupo.bolilla[grupo.asignados + 1] = bolilla;
    grupo.asignados = grupo.asignados + 1;
    
    // control para ir viendo
    cout << "Asignado el " << grupo.asignados << " equipo: " << bolilla.equipo.nombre << ", al grupo: " << grupo.letra << endl;
}
