#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio1.hpp"
#include "Ejercicio2.hpp"
#include "Ejercicio3.hpp"

void realizarSorteo(Bolilla bolillero1[], Bolilla bolillero2[], Bolilla bolillero3[], Bolilla bolillero4[], int lenBol) {
    
    // Cada grupo es una letra + los asignados + un array de bolillas
    Grupo grupos[8];
    GenerarArchivo regGrupo;
    
    // A, B, C, D, E, F, G, H
    asignarLetras(grupos);
    
    // uso un auxiliar para el random
    int aleatorioAux = 0;
    srand (time(NULL));
    
    // asigno Rusia de una
    grupos[0].bolilla[0] = bolillero1[0];
    grupos[0].asignados += 1;
    
    // primer bolillero
    cout << "procesando primer bolillero" << endl;
    for(int i = 1; i < lenBol; i++) {
        aleatorioAux = rand() % lenBol;
        cout << i << ") buscando equipo para: " << bolillero1[i].equipo.nombre << " (" << bolillero1[i].equipo.federacion << ") -> ";
        
        while (!validacion(bolillero1[i], grupos[aleatorioAux], grupos)) {
            aleatorioAux = (rand() % lenBol) + 1;
        }
        
        cout << "encontrado grupo: " << grupos[aleatorioAux].letra;
        cout << " (queda con " << grupos[aleatorioAux].asignados + 1 << " integrantes)" << endl;
        grupos[aleatorioAux].bolilla[grupos[aleatorioAux].asignados] = bolillero1[i];
        grupos[aleatorioAux].asignados += 1;
    }
    
    cout << "procesando segundo bolillero" << endl;
    // segundo bolillero
    for(int i = 0; i < lenBol; i++) {
        aleatorioAux = rand() % lenBol;
        cout << i << ") buscando equipo para: " << bolillero2[i].equipo.nombre << " (" << bolillero2[i].equipo.federacion << ") -> ";
        
        while (!validacion(bolillero2[i], grupos[aleatorioAux], grupos)) {
            aleatorioAux = rand() % lenBol;
        }
        
        cout << "encontrado grupo: " << grupos[aleatorioAux].letra;
        cout << " (queda con " << grupos[aleatorioAux].asignados + 1 << " integrantes)" << endl;
        
        grupos[aleatorioAux].bolilla[grupos[aleatorioAux].asignados] = bolillero2[i];
        grupos[aleatorioAux].asignados += 1;
    }
    
    cout << "procesando tercer bolillero" << endl;
    // tercer bolillero
    for(int i = 0; i < lenBol; i++) {
        aleatorioAux = rand() % lenBol;
        cout << i << ") buscando equipo para: " << bolillero3[i].equipo.nombre << " (" << bolillero3[i].equipo.federacion << ") -> ";
        
        while (!validacion(bolillero3[i], grupos[aleatorioAux], grupos)) {
            aleatorioAux = rand() % lenBol;
        }
        
        cout << "encontrado grupo: " << grupos[aleatorioAux].letra;
        cout << " (queda con " << grupos[aleatorioAux].asignados + 1 << " integrantes)" << endl;
        
        grupos[aleatorioAux].bolilla[grupos[aleatorioAux].asignados] = bolillero3[i];
        grupos[aleatorioAux].asignados += 1;
    }
    
    cout << "procesando cuarto bolillero" << endl;
    // cuarto bolillero
   for(int i = 0; i < lenBol; i++) {
    	
    	cout << " ";
    	cout << "ACA ESTA EL FIXTURE" << endl;
    	mostrarGrupos(grupos);
    	cout << " ";
    	
    	
        aleatorioAux = rand() % lenBol;
        cout << i << ") buscando equipo para: " << bolillero4[i].equipo.nombre << " (" << bolillero4[i].equipo.federacion << ") -> ";
        
        while (!validacion(bolillero4[i], grupos[aleatorioAux], grupos)) {
            aleatorioAux = rand() % lenBol;
        }
        
        cout << "encontrado grupo: " << grupos[aleatorioAux].letra;
        cout << " (queda con " << grupos[aleatorioAux].asignados + 1 << " integrantes)" << endl;
        
        grupos[aleatorioAux].bolilla[grupos[aleatorioAux].asignados] = bolillero4[i];
        grupos[aleatorioAux].asignados += 1;
    }
    
    mostrarGrupos(grupos);
  	generarArchivos(regGrupo, grupos);
    mostrarGruposConformados(regGrupo);
    
	return;
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

bool validacion(Bolilla bolilla, Grupo grupo, Grupo grupos[]) {
    bool uefaFlag = false;
    
    if(grupo.asignados >= 4) {
        return false;
    }
    
    // -- Si el grupo que acabo de agarrar ya tiene 3 participantes
    if(grupo.asignados == 3) 
	{    
    	// -- Recorro los ocho grupos
	    for (int i = 0; i < 8; i++) 
		{
			// -- Y si algun grupo todavia tiene uno retorno false, para qeu este grupo no se complete mientras a otros grupos le faltan 3 integrantes
	    	if(grupos[i].asignados == 1)
	    	{
	    		return false;
			}
	    } 
	}
	
	if(grupo.asignados == 3) 
	{    
    	// -- Recorro los ocho grupos
	    for (int i = 0; i < 8; i++) 
		{
			// -- Y si algun grupo todavia tiene uno retorno false, para que este grupo no se complete mientras a otros grupos le faltan 2 integrantes
	    	if(grupos[i].asignados == 2)
	    	{
	    		return false;
			}
	    } 
	}
    
    int j = grupo.asignados;
    int aux=0;
    for (int i = 0; i < grupo.asignados; i++)
	 {
    	
       cout << "ACA ENTRA AL FOR grupo letra: " << grupo.letra <<  "--  ContadorAux: " << aux <<endl;
        
		// si es UEFA
        if (strncmp(bolilla.equipo.federacion, "UEFA", 3) == 0) {
            if (strncmp(bolilla.equipo.federacion, grupo.bolilla[i].equipo.federacion, 3) == 0) {
                // si es UEFA y ya había encontrado otro en el grupo (bandera)
                if (uefaFlag)
				{
					cout << "ACA ENTRA SALE DEL FOR grupo letra: " << grupo.letra <<  "--  POR TENER DOS EUROPEOS" << endl;
                    return false;
                // si no, levanto la bandera porque encontré uno de UEFA
                } 
				else
				{
                    uefaFlag = true;
                }
            }
        // es cualquier otra federación, comparo que no haya otro de la misma federación
        } 
		else
		{
			if (strncmp(bolilla.equipo.federacion, grupo.bolilla[i].equipo.federacion, 3) == 0) 
			{
				cout << "ACA ENTRA SALE DEL FOR grupo letra: " << grupo.letra <<  "--  POR TENER OTRO DE LA MISMA FEDERACION" << endl;
            	return false;
			}
			aux = aux + 1;
			cout << " ";
    		cout << "valida true Asignados en este grupo: "<< grupo.asignados << "  letra: " << grupo.letra <<  "--  ContadorAux: " << aux <<endl;
			if(j==aux)
			{
				return true;
			}
        }
        
    }
    
    return true;
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
        			fwrite(&regGrupo, sizeof(Grupo), 1, grupoA);
        		break;
        		case 'B':
        			strcpy(regGrupo.letra, "B");
        			regGrupo.numGrupo = 2;
	        		fwrite(&regGrupo, sizeof(Grupo), 1, grupoB);
	        	case 'C':
	        		strcpy(regGrupo.letra, "C");
	        		regGrupo.numGrupo = 3;
	        		fwrite(&regGrupo, sizeof(Grupo), 1, grupoC);
	        	break;
	        	case 'D':
	        		regGrupo.numGrupo = 4;
	        		strcpy(regGrupo.letra, "D");
	        		fwrite(&regGrupo, sizeof(Grupo), 1, grupoD);
	        	break;
	        	case 'E':
	        		regGrupo.numGrupo = 5;
	        		strcpy(regGrupo.letra, "E");
	        		fwrite(&regGrupo, sizeof(Grupo), 1, grupoE);
	        	break;
	        	case 'F':
	        		regGrupo.numGrupo = 6;
	        		strcpy(regGrupo.letra, "F");
	        		fwrite(&regGrupo, sizeof(Grupo), 1, grupoF);
	        	break;
	        	case 'G':
	        		regGrupo.numGrupo = 7;
	        		strcpy(regGrupo.letra, "G");
	        		fwrite(&regGrupo, sizeof(Grupo), 1, grupoG);
	        	break;
	        	case 'H':
	        		strcpy(regGrupo.letra, "H");
	        		regGrupo.numGrupo = 8;
	        		fwrite(&regGrupo, sizeof(Grupo), 1, grupoH);
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
void mostrarGrupos(Grupo grupos[])
{
    for (int i = 0; i < 8; i++) {
        cout << "GRUPO " << grupos[i].letra << endl;
        for (int j = 0; j < 4; j++) {
                cout << "EQUIPO " << grupos[i].bolilla[j].equipo.nombre << endl;
        }
    }
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
    
    fread(&regGrupo, sizeof(Grupo), 1, grupoA);
    
    while (!feof(grupoA))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(Grupo),1, grupoA);
    }
    
    fclose(grupoA);
    
     fread(&regGrupo, sizeof(Grupo), 1, grupoB);
    
    while (!feof(grupoB))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(Grupo),1, grupoB);
    }
    
    fclose(grupoB);
    
	fread(&regGrupo, sizeof(Grupo), 1, grupoC);
    
    while (!feof(grupoC))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(Grupo),1, grupoC);
    }
    
    fclose(grupoC);
    
     fread(&regGrupo, sizeof(Grupo), 1, grupoD);
    
    while (!feof(grupoD))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(Grupo),1, grupoD);
    }
    
    fclose(grupoD);
    
     fread(&regGrupo, sizeof(Grupo), 1, grupoE);
    
    while (!feof(grupoE))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(Grupo),1, grupoE);
    }
    
    fclose(grupoE);
    
     fread(&regGrupo, sizeof(Grupo), 1, grupoF);
    
    while (!feof(grupoF))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(Grupo),1, grupoF);
    }
    
    fclose(grupoF);
    
     fread(&regGrupo, sizeof(Grupo), 1, grupoG);
    
    while (!feof(grupoG))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(Grupo),1, grupoG);
    }
    
    fclose(grupoG);
    
     fread(&regGrupo, sizeof(Grupo), 1, grupoH);
    
    while (!feof(grupoH))
    {
        cout << "Grupo " << regGrupo.letra << " -> ";
        cout << regGrupo.equipo.nombre;
        cout << " (" << regGrupo.equipo.federacion << ")" << endl;
        fread(&regGrupo,sizeof(Grupo),1, grupoH);
    }
    
    fclose(grupoH);
    
    return;
}
