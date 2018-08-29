#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio2.hpp"
#include "../Ejercicio 1/Ejercicio1.hpp"

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
    cout << "___________________________________________________" << endl;
    cout << " ***** PROCESAMIENTO DE CADA BOLILLERO *****" << endl;
    cout << "_________________________________________________" << endl;
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
    GenerarArchivo regGrupo;
    mostrarGrupos(grupos);
    // Se generan los archivos en base a los grupos sorteados.
    generarArchivos(regGrupo, grupos);
    // Se muestran los archivos generados.
    mostrarGruposConformados(regGrupo);
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
	cout << "_______________________________________________" << endl;
	cout << " ****** RESULTADO DEL SORTEO: ****** " << endl;
	cout << "_______________________________________________" << endl;
    for (int i = 0; i < 8; i++) {
        cout << " ****** GRUPO " << grupos[i].letra << " ******"<< endl;
        for (int j = 0; j < 4; j++) {
                cout << "EQUIPO: " << grupos[i].bolilla[j].equipo.nombre << endl;
        }
    cout << "_______________________________________________" << endl;
    }
}


void generarArchivos(GenerarArchivo regGrupo, Grupo grupos[])
{
    
	
	FILE * grupoA = fopen("GrupoA.dat", "wb");
	FILE * grupoB = fopen("GrupoB.dat", "wb");
	FILE * grupoC = fopen("GrupoC.dat", "wb");
	FILE * grupoD = fopen("GrupoD.dat", "wb");
	FILE * grupoE = fopen("GrupoE.dat", "wb");
	FILE * grupoF = fopen("GrupoF.dat", "wb");
	FILE * grupoG = fopen("GrupoG.dat", "wb");
	FILE * grupoH = fopen("GrupoH.dat", "wb");

    int cantGrupos = 8;
    int lenGrupo = 4;
    
    for (int i= 0; i < cantGrupos; i++)
    {
    	for (int j = 0; j < lenGrupo; j++) 
		{
			
        	strcpy(regGrupo.equipo.nombre, grupos[i].bolilla[j].equipo.nombre);
        	strcpy(regGrupo.equipo.federacion, grupos[i].bolilla[j].equipo.federacion);
        
       		switch (grupos[i].letra)
        	{	
        		case 'A':
        			strcpy(regGrupo.letra, "A");
        			regGrupo.numGrupo = 1;
        			fwrite(&regGrupo, sizeof(GenerarArchivo), 1, grupoA);
        		break;
        		case 'B':
        			strcpy(regGrupo.letra, "B");
        			regGrupo.numGrupo = 2;
	        		fwrite(&regGrupo, sizeof(GenerarArchivo), 1, grupoB);
	        	break;
	        	case 'C':
	        		strcpy(regGrupo.letra, "C");
	        		regGrupo.numGrupo = 3;
	        		fwrite(&regGrupo, sizeof(GenerarArchivo), 1, grupoC);
	        	break;
	        	case 'D':
	        		regGrupo.numGrupo = 4;
	        		strcpy(regGrupo.letra, "D");
	        		fwrite(&regGrupo, sizeof(GenerarArchivo), 1, grupoD);
	        	break;
	        	case 'E':
	        		regGrupo.numGrupo = 5;
	        		strcpy(regGrupo.letra, "E");
	        		fwrite(&regGrupo, sizeof(GenerarArchivo), 1, grupoE);
	        	break;
	        	case 'F':
	        		regGrupo.numGrupo = 6;
	        		strcpy(regGrupo.letra, "F");
	        		fwrite(&regGrupo, sizeof(GenerarArchivo), 1, grupoF);
	        	break;
	        	case 'G':
	        		regGrupo.numGrupo = 7;
	        		strcpy(regGrupo.letra, "G");
	        		fwrite(&regGrupo, sizeof(GenerarArchivo), 1, grupoG);
	        	break;
	        	case 'H':
	        		strcpy(regGrupo.letra, "H");
	        		regGrupo.numGrupo = 8;
	        		fwrite(&regGrupo, sizeof(GenerarArchivo), 1, grupoH);
	        	break;
	        	default: 
	        		cout << "No hay equipos" << endl;
	        		break;

		}
        
    }
    
    
	}
 fclose(grupoA);
 fclose(grupoB);
 fclose(grupoC);
 fclose(grupoD);
 fclose(grupoE);
 fclose(grupoF);
 fclose(grupoG);
 fclose(grupoH);



return;
    
    
}

void mostrarGruposConformados(GenerarArchivo regGrupo)
{
    FILE * grupoA = fopen("GrupoA.dat", "rb");
	FILE * grupoB = fopen("GrupoB.dat", "rb");
	FILE * grupoC = fopen("GrupoC.dat", "rb");
	FILE * grupoD = fopen("GrupoD.dat", "rb");
	FILE * grupoE = fopen("GrupoE.dat", "rb");
	FILE * grupoF = fopen("GrupoF.dat", "rb");
	FILE * grupoG = fopen("GrupoG.dat", "rb");
	FILE * grupoH = fopen("GrupoH.dat", "rb");
    
    fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoA);
    
    cout << "_______________________________________________" << endl;
    cout << " **** GENERACION DE ARCHIVOS POR GRUPO **** " << endl;
	cout << "_______________________________________________" << endl;
	
    while (!feof(grupoA))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(GenerarArchivo),1, grupoA);
    }
    
    fclose(grupoA);
    cout << "_______________________________________________" << endl;
    fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoB);
    
    while (!feof(grupoB))
    {
      	cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(GenerarArchivo),1, grupoB);
    }
    
    fclose(grupoB);
    cout << "_______________________________________________" << endl;
	fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoC);
    
    while (!feof(grupoC))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(GenerarArchivo),1, grupoC);
    }
    
    fclose(grupoC);
    cout << "_______________________________________________" << endl;
    fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoD);
    
    while (!feof(grupoD))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(GenerarArchivo),1, grupoD);
    }
    
    fclose(grupoD);
    cout << "_______________________________________________" << endl;
    fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoE);
    
    while (!feof(grupoE))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(GenerarArchivo),1, grupoE);
    }
    
    fclose(grupoE);
    cout << "_______________________________________________" << endl;
    fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoF);
    
    while (!feof(grupoF))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(GenerarArchivo),1, grupoF);
    }
    
    fclose(grupoF);
    cout << "_______________________________________________" << endl;
    fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoG);
    
    while (!feof(grupoG))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(GenerarArchivo),1, grupoG);
    }
    
    fclose(grupoG);
    cout << "_______________________________________________" << endl;
    fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoH);
    
    while (!feof(grupoH))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(GenerarArchivo),1, grupoH);
    }
    
    fclose(grupoH);
    cout << "_______________________________________________________________" << endl;
    cout << "_______________________________________________________________" << endl;
    cout << "_______________________________________________________________" << endl;
    return;
}
