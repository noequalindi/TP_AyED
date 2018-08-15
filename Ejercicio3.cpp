#include <iostream>
#include <string>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio1.hpp"
#include "Ejercicio2.hpp"
#include "Ejercicio3.hpp"


void cargarGruposEnVector(Consolidado vecGrupos[], GenerarArchivo regGrupo, Consolidado gruposConsolidado)
{

	FILE * grupoA = fopen("GrupoA.dat", "rb");
	FILE * grupoB = fopen("GrupoB.dat", "rb");
	FILE * grupoC = fopen("GrupoC.dat", "rb");
	FILE * grupoD = fopen("GrupoD.dat", "rb");
	FILE * grupoE = fopen("GrupoE.dat", "rb");
	FILE * grupoF = fopen("GrupoF.dat", "rb");
	FILE * grupoG = fopen("GrupoG.dat", "rb");
	FILE * grupoH = fopen("GrupoH.dat", "rb");
	
    int lenGrupos=0;
    
    fread(&regGrupo, sizeof(Grupo), 1, grupoA);	
	while (!feof(grupoA))
	{
		gruposConsolidado.numGrupo = regGrupo.numGrupo;
		strcpy(gruposConsolidado.equipo.nombre, regGrupo.equipo.nombre);
		strcpy(gruposConsolidado.equipo.federacion, regGrupo.equipo.federacion);
		insertarOrdenado(vecGrupos,lenGrupos,gruposConsolidado);
  		fread(&regGrupo,sizeof(GenerarArchivo),1, grupoA);
	}

	
	fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoB);	
	while (!feof(grupoB))
	{
		gruposConsolidado.numGrupo = regGrupo.numGrupo;
		strcpy(gruposConsolidado.equipo.nombre, regGrupo.equipo.nombre);
		strcpy(gruposConsolidado.equipo.federacion, regGrupo.equipo.federacion);
		insertarOrdenado(vecGrupos,lenGrupos,gruposConsolidado);
  		fread(&regGrupo,sizeof(GenerarArchivo),1, grupoB);
	}
	
	fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoB);	
	while (!feof(grupoB))
	{
		gruposConsolidado.numGrupo = regGrupo.numGrupo;
		strcpy(gruposConsolidado.equipo.nombre, regGrupo.equipo.nombre);
		strcpy(gruposConsolidado.equipo.federacion, regGrupo.equipo.federacion);
		insertarOrdenado(vecGrupos,lenGrupos,gruposConsolidado);
  		fread(&regGrupo,sizeof(GenerarArchivo),1, grupoB);
	}
	
	fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoC);	
	while (!feof(grupoC))
	{
		gruposConsolidado.numGrupo = regGrupo.numGrupo;
		strcpy(gruposConsolidado.equipo.nombre, regGrupo.equipo.nombre);
		strcpy(gruposConsolidado.equipo.federacion, regGrupo.equipo.federacion);
		insertarOrdenado(vecGrupos,lenGrupos,gruposConsolidado);
  		fread(&regGrupo,sizeof(GenerarArchivo),1, grupoC);
	}
	
	fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoD);	
	while (!feof(grupoD))
	{
		gruposConsolidado.numGrupo = regGrupo.numGrupo;
		strcpy(gruposConsolidado.equipo.nombre, regGrupo.equipo.nombre);
		strcpy(gruposConsolidado.equipo.federacion, regGrupo.equipo.federacion);
		insertarOrdenado(vecGrupos,lenGrupos,gruposConsolidado);
  		fread(&regGrupo,sizeof(GenerarArchivo),1, grupoD);
	}
	
		fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoE);	
	while (!feof(grupoE))
	{
		gruposConsolidado.numGrupo = regGrupo.numGrupo;
		strcpy(gruposConsolidado.equipo.nombre, regGrupo.equipo.nombre);
		strcpy(gruposConsolidado.equipo.federacion, regGrupo.equipo.federacion);
		insertarOrdenado(vecGrupos,lenGrupos,gruposConsolidado);
  		fread(&regGrupo,sizeof(GenerarArchivo),1, grupoE);
	}
	
		fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoF);	
	while (!feof(grupoF))
	{
		gruposConsolidado.numGrupo = regGrupo.numGrupo;
		strcpy(gruposConsolidado.equipo.nombre, regGrupo.equipo.nombre);
		strcpy(gruposConsolidado.equipo.federacion, regGrupo.equipo.federacion);
		insertarOrdenado(vecGrupos,lenGrupos,gruposConsolidado);
  		fread(&regGrupo,sizeof(GenerarArchivo),1, grupoF);
	}
	fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoG);	
	while (!feof(grupoG))
	{
		gruposConsolidado.numGrupo = regGrupo.numGrupo;
		strcpy(gruposConsolidado.equipo.nombre, regGrupo.equipo.nombre);
		strcpy(gruposConsolidado.equipo.federacion, regGrupo.equipo.federacion);
		insertarOrdenado(vecGrupos,lenGrupos,gruposConsolidado);
  		fread(&regGrupo,sizeof(GenerarArchivo),1, grupoG);
	}
	
	fread(&regGrupo, sizeof(GenerarArchivo), 1, grupoH);	
	while (!feof(grupoH))
	{
		gruposConsolidado.numGrupo = regGrupo.numGrupo;
		strcpy(gruposConsolidado.equipo.nombre, regGrupo.equipo.nombre);
		strcpy(gruposConsolidado.equipo.federacion, regGrupo.equipo.federacion);
		insertarOrdenado(vecGrupos,lenGrupos,gruposConsolidado);
  		fread(&regGrupo,sizeof(GenerarArchivo),1, grupoH);
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

void mostrarVectorGruposConsolidado(Consolidado vecGrupos[], int &lenConsolidado)
{

	for (int i = 0; i< lenConsolidado; i++)
    {
    	cout << vecGrupos[i].numGrupo << "//" << " Grupo: "<< vecGrupos[i].letra;
    	cout<< "____________________"<<endl;
		cout << vecGrupos[i].equipo.nombre << "--> " << vecGrupos[i].equipo.federacion <<endl;
	}
	
	return;
}
void insertar(Consolidado vecGrupos[], int &lenGrupos, Consolidado gruposConsolidado, int pos)
{

	for (int i=lenGrupos-1; i>=pos; i--)
	{
		vecGrupos[i+1]=vecGrupos[i];
	}
	
	vecGrupos[pos] = gruposConsolidado;
	lenGrupos ++;
	return;
}

int insertarOrdenado(Consolidado vecGrupos[], int &lenGrupos, Consolidado gruposConsolidado)
{
	int i=0;

	while(i < lenGrupos && vecGrupos[i].numGrupo <= gruposConsolidado.numGrupo) {
		i++;
	}	
	
	insertar(vecGrupos, lenGrupos, gruposConsolidado, i);
	return i;
	
}
