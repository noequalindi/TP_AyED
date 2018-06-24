#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio1.hpp"

void cargarVectorEquipos(Equipos vecEquipos[])
{
	// ************ BOLILLERO 1 ***************

	vecEquipos[0].numEq = 1;
	vecEquipos[0].numBol = 1;
	strcpy(vecEquipos[0].nombre, "Rusia");
	strcpy(vecEquipos[0].federacion, "AFC");
	
	vecEquipos[1].numEq = 2;
	vecEquipos[1].numBol = 1;
	strcpy(vecEquipos[1].nombre, "Alemania");
	strcpy(vecEquipos[1].federacion, "UEFA");
	
	vecEquipos[2].numEq = 3;
	vecEquipos[2].numBol = 1;
	strcpy(vecEquipos[2].nombre, "Brasil");
	strcpy(vecEquipos[2].federacion, "Comebol");

	vecEquipos[3].numEq = 4;
	vecEquipos[3].numBol = 1;
	strcpy(vecEquipos[3].nombre, "Portugal");
	strcpy(vecEquipos[3].federacion, "UEFA");

	vecEquipos[4].numEq = 5;
	vecEquipos[4].numBol = 1;
	strcpy(vecEquipos[4].nombre, "Argentina");
	strcpy(vecEquipos[4].federacion, "Comebol");

	vecEquipos[5].numEq = 6;
	vecEquipos[5].numBol = 1;
	strcpy(vecEquipos[5].nombre, "Belgica");
	strcpy(vecEquipos[5].federacion, "UEFA");

	vecEquipos[6].numEq = 7;
	vecEquipos[6].numBol = 1;
	strcpy(vecEquipos[6].nombre, "Polonia");
	strcpy(vecEquipos[6].federacion, "UEFA");

	vecEquipos[7].numEq = 8;
	vecEquipos[7].numBol = 1;
	strcpy(vecEquipos[7].nombre, "Francia");
	strcpy(vecEquipos[7].federacion, "UEFA");

	// ************ BOLILLERO 2 ***************

	
	vecEquipos[8].numEq = 9;
	vecEquipos[8].numBol = 2;
	strcpy(vecEquipos[8].nombre, "Espana");
	strcpy(vecEquipos[8].federacion, "UEFA");
	
	vecEquipos[9].numEq = 10;
	vecEquipos[9].numBol = 2;
	strcpy(vecEquipos[9].nombre, "Peru");
	strcpy(vecEquipos[9].federacion, "Comebol");
	
	vecEquipos[10].numEq = 11;
	vecEquipos[10].numBol = 2;
	strcpy(vecEquipos[10].nombre, "Suiza");
	strcpy(vecEquipos[10].federacion, "UEFA");
	
	vecEquipos[11].numEq = 12;
	vecEquipos[11].numBol = 2;
	strcpy(vecEquipos[11].nombre, "Inglaterra");
	strcpy(vecEquipos[11].federacion, "UEFA");
	
	vecEquipos[12].numEq = 13;
	vecEquipos[12].numBol = 2;
	strcpy(vecEquipos[12].nombre, "Colombia");
	strcpy(vecEquipos[12].federacion, "Concacaf");
	
	vecEquipos[13].numEq = 14;
	vecEquipos[13].numBol = 2;
	strcpy(vecEquipos[13].nombre, "Mexico");
	strcpy(vecEquipos[13].federacion, "Concacaf");
	
	vecEquipos[14].numEq = 15;
	vecEquipos[14].numBol = 2;
	strcpy(vecEquipos[14].nombre, "Uruguay");
	strcpy(vecEquipos[14].federacion, "Comebol");
	
	vecEquipos[15].numEq = 16;
	vecEquipos[15].numBol = 2;
	strcpy(vecEquipos[15].nombre, "Croacia");
	strcpy(vecEquipos[15].federacion, "UEFA");
	
	
	// ************ BOLILLERO 3 ***************

	vecEquipos[16].numEq = 17;
	vecEquipos[16].numBol = 3;
	strcpy(vecEquipos[16].nombre, "Dinamarca");
	strcpy(vecEquipos[16].federacion, "UEFA");
	
	vecEquipos[17].numEq = 18;
	vecEquipos[17].numBol = 3;
	strcpy(vecEquipos[17].nombre, "Islandia");
	strcpy(vecEquipos[17].federacion, "UEFA");
	
	vecEquipos[18].numEq = 19;
	vecEquipos[18].numBol = 3;
	strcpy(vecEquipos[18].nombre, "Costa Rica");
	strcpy(vecEquipos[18].federacion, "Concacaf");
	
	vecEquipos[19].numEq = 20;
	vecEquipos[19].numBol = 3;
	strcpy(vecEquipos[19].nombre, "Suecia");
	strcpy(vecEquipos[19].federacion, "UEFA");
	
	vecEquipos[20].numEq = 21;
	vecEquipos[20].numBol = 3;
	strcpy(vecEquipos[20].nombre, "Tunez");
	strcpy(vecEquipos[20].federacion, "AFC");
	
	vecEquipos[21].numEq = 22;
	vecEquipos[21].numBol = 3;
	strcpy(vecEquipos[21].nombre, "Egipto");
	strcpy(vecEquipos[21].federacion, "AFC");
	
	vecEquipos[22].numEq = 23;
	vecEquipos[22].numBol = 3;
	strcpy(vecEquipos[22].nombre, "Senegal");
	strcpy(vecEquipos[22].federacion, "AFC");
	
	vecEquipos[23].numEq = 24;
	vecEquipos[23].numBol = 3;
	strcpy(vecEquipos[23].nombre, "Iran");
	strcpy(vecEquipos[23].federacion, "AFC");

	
	// ************ BOLILLERO 4 ***************

	
	vecEquipos[24].numEq = 25;
	vecEquipos[24].numBol = 4;
	strcpy(vecEquipos[24].nombre, "Serbia");
	strcpy(vecEquipos[24].federacion, "AFC");
	
	vecEquipos[25].numEq = 26;
	vecEquipos[25].numBol = 4;
	strcpy(vecEquipos[25].nombre, "Nigeria");
	strcpy(vecEquipos[25].federacion, "CAF");
	
	vecEquipos[26].numEq = 27;
	vecEquipos[26].numBol = 4;
	strcpy(vecEquipos[26].nombre, "Australia");
	strcpy(vecEquipos[26].federacion, "AFC");
	
	vecEquipos[27].numEq = 28;
	vecEquipos[27].numBol = 4;
	strcpy(vecEquipos[27].nombre, "Japon");
	strcpy(vecEquipos[27].federacion, "AFC");
	
	vecEquipos[28].numEq = 29;
	vecEquipos[28].numBol = 4;
	strcpy(vecEquipos[28].nombre, "Marruecos");
	strcpy(vecEquipos[28].federacion, "CAF");
	
	vecEquipos[29].numEq = 30;
	vecEquipos[29].numBol = 4;
	strcpy(vecEquipos[29].nombre, "Panama");
	strcpy(vecEquipos[29].federacion, "Concacaf");
	
	vecEquipos[30].numEq = 31;
	vecEquipos[30].numBol = 4;
	strcpy(vecEquipos[30].nombre, "Corea del Sur");
	strcpy(vecEquipos[30].federacion, "AFC");
	
	vecEquipos[31].numEq = 32;
	vecEquipos[31].numBol = 4;
	strcpy(vecEquipos[31].nombre, "Arabia Saudita");
	strcpy(vecEquipos[31].federacion, "CAF");
	
	return;
	
}

void cargarArchivo(Equipos vecEquipos[], int n)
{
	FILE *regEquipos = fopen ("Equipos.dat", "wb+");
	cout << "*** SE CARGAN LOS EQUIPOS EN EL ARCHIVO... *** " <<endl;
	n = 32;
	// ESCRIBE EL ARCHIVO CON EL VECTOR 
	for (int i=0; i < n; i++)
	{
        fwrite(&vecEquipos[i],sizeof(Equipos),1, regEquipos);
	}
	fclose(regEquipos);
	return;
}	

/*bool estaRepetido(int vecRepetidos[])
{
	int arreglo[8];
	vecRepetidos[8];
	bool estaRepetido = false;
	//int len = 0;
	for (int k=0; k < 8; k++)
	{
		int pos = generarNumeroAleatorio();
		if (vecRepetidos[k] == pos)
		{
			estaRepetido = true;
		} 
		
	}
	return estaRepetido;
}
*/

void mostrar(FILE *regEquipos, int numBol)
{
	Equipos lineaEquipo; //struct para leer y guardar los datos del archivo
	int n = 32;
	fread(&lineaEquipo, sizeof(Equipos), 1, regEquipos);
	while(!feof(regEquipos) && lineaEquipo.numEq <= n)
	{
		if (numBol == lineaEquipo.numBol)
		{
		
            cout << "NOMBRE: " << lineaEquipo.nombre << endl;
            cout << "FEDERACION: "<< lineaEquipo.federacion << endl;
            cout << "_______________" << endl;
		
        }
		fread(&lineaEquipo, sizeof(Equipos), 1, regEquipos);

    }



    return;
}
void insertar(Grupo vec[], int &len, Bolillero bol[], int pos){
	
	for(int i = len-1; i >= pos; i--){
		vec[i+1] = vec[i];
	}
	
	vec[pos].numBol = bol[pos].numBol;
	len ++;
	return;
}
