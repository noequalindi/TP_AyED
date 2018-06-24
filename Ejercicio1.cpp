#include <iostream>
#include <string.h>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;
	
struct Equipos
{
	int numEq;
	int numBol;
	char nombre[30];
	char federacion[30];
};
struct Bolillero
{
	int numBol;
	int numEq;
	char nombre[30];
	char federacion[30];
	
};
struct Grupo
{
	char nombreGrupo[10];
	int numBol;
	int numEq;
	char nombre[30];
	char federacion[30];
};

//prototipos de funcion
void cargarVectorEquipos(Equipos vec[]);

void cargarArchivo(Equipos vec[], int n);

void mostrar(FILE *f, int numBol);

int generarNumeroAleatorio();

void cargarBolilleros(FILE *f,Equipos vec[], Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[]);
void insertar(Grupo arr[], int &len, Bolillero bol[], int pos);
void sortearFaseGrupos(Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[], Grupo g1[], Grupo g2[],Grupo g3[], Grupo g4[], Grupo g5[], 
Grupo g6[],	Grupo g7[],	Grupo g8[], int lenBol, int lenGr);


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
	sortearFaseGrupos(bol1,bol2,bol3,bol4, g1,  g2, g3,  g4,  g5,  g6,	 g7, g8, lenBol, lenGr);

	system("PAUSE");
	return 0;
}
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

int generarNumeroAleatorio()
{
 
 /*   int aux = 0;

    srand(time(0));
 
    for(int i = 0; i < 8; i++){
        aux =  (rand() % 8);
 
        int aux2 = 0;
 
        while(aux2 < i){
 
            if (aux != arreglo[aux2])
                aux2++;
 
            else{
                    aux = (rand() % 8);
                    aux2 = 0;
 
                }
        }
 
        arreglo[i] = aux;
 
        cout << arreglo[i] << "\n";
    }
 
    return arreglo; */
    
	int numeroAleatorio = (rand() % 8); // para el sorteo de la fase de grupos se genera un numero aleatorio entre 0 y 7
	int numEquipoSorteado = numeroAleatorio;

	return numEquipoSorteado;
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
void sortearFaseGrupos(Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[],Grupo g1[], Grupo g2[],Grupo g3[], Grupo g4[], Grupo g5[], 
Grupo g6[],	Grupo g7[],	Grupo g8[], int lenBol, int lenGr)
{
	
	int pos, i=0, j=1;

	srand( time( NULL ) );
	// sorteo del bolillero 1, solo se saca rusia y se inserta en el grupo A y el resto 7 equipos en el resto de los grupos
	cout << "************** SORTEO **************"<<endl;
	if ( i == 0)
	{
	
		g1[i].numEq = bol1[i].numEq;
		strcpy(g1[i].nombre, bol1[i].nombre);
		strcpy(g1[i].federacion, bol1[i].federacion);
		strcpy(g1[i].nombreGrupo, "Grupo A");
		
		cout << g1[i].nombreGrupo<<endl;
		cout << g1[i].nombre<<"-"<<" ";
		cout << g1[i].federacion<<endl;
		cout << "_______________________"<<endl;
	}

	 for(i = 1; i <= 8; i++)
	 {
        
		pos = generarNumeroAleatorio();
 
        int aux2 = 0;
 
        while(aux2 < i){
 
            if(pos != bol1[aux2].numEq)
                aux2++;
 
            else{
                    pos = generarNumeroAleatorio();
                    aux2 = 0;
 
                }
        }
 
        bol1[i].numEq = pos;
        cout << bol1[i].numEq <<endl;
    
		//pos = generarNumeroAleatorio(); 
	if (bol1[i].numEq == 0)
	{
		pos=1;
	}

	switch (pos)
	{
	case 1:
	strcpy(g2[j].nombreGrupo , "Grupo B");
	g2[j].numEq = bol1[pos].numEq;
	strcpy(g2[j].nombre, bol1[pos].nombre);
	strcpy(g2[j].federacion, bol1[pos].federacion);
	
	cout << g2[j].nombreGrupo <<endl;
	cout << g2[j].nombre<<"-"<<" ";
	cout << g2[j].federacion << endl;
	cout << "_______________________"<<endl;

	
	break;
	
	case 2:
	
	strcpy(g3[j].nombreGrupo , "Grupo C");
	g3[j].numEq = bol1[pos].numEq;
	strcpy(g3[j].nombre, bol1[pos].nombre);
	strcpy(g3[j].federacion, bol1[pos].federacion);
	
	cout << g3[j].nombreGrupo <<endl;
	cout << g3[j].nombre<<"-"<<" ";
	cout << g3[j].federacion<<endl;
	cout << "_______________________"<<endl;

	break;

	case 3:
	
	strcpy(g4[j].nombreGrupo , "Grupo D");
	g4[j].numEq = bol1[pos].numEq;
	strcpy(g4[j].nombre, bol1[pos].nombre);
	strcpy(g4[j].federacion, bol1[pos].federacion);
		
	cout << g4[j].nombreGrupo <<endl;
	cout << g4[j].nombre<<"-"<<" ";
	cout << g4[j].federacion<<endl;
	cout << "_______________________"<<endl;
	
		
	break;
	
	case 4:		
	strcpy(g5[j].nombreGrupo , "Grupo E");
	g5[j].numEq = bol1[pos].numEq;
	strcpy(g5[j].nombre, bol1[pos].nombre);
	strcpy(g5[j].federacion, bol1[pos].federacion);
	
	cout << g5[j].nombreGrupo <<endl;
	cout << g5[j].nombre<<"-"<<" ";
	cout << g5[j].federacion<<endl;
	cout << "_______________________"<<endl;
	
	break;
	
	case 5:
	
	strcpy(g6[j].nombreGrupo , "Grupo F");
	g6[j].numEq = bol1[pos].numEq;
	strcpy(g6[j].nombre, bol1[pos].nombre);
	strcpy(g6[j].federacion, bol1[pos].federacion);
	
	cout << g6[j].nombreGrupo <<endl;
	cout << g6[j].nombre<<"-"<<" ";
	cout << g6[j].federacion<<endl;
	cout << "_______________________"<<endl;


	break;
	
	case 6:	
	
	strcpy(g7[j].nombreGrupo , "Grupo G");
	g7[j].numEq = bol1[pos].numEq;
	strcpy(g7[j].nombre, bol1[pos].nombre);
	strcpy(g7[j].federacion, bol1[pos].federacion);
	
	cout << g7[j].nombreGrupo <<endl;
	cout << g7[j].nombre<<"-"<<" ";
	cout << g7[j].federacion<<endl;
	cout << "_______________________"<<endl;

	break;
	
	case 7:
	
	strcpy(g8[j].nombreGrupo , "Grupo H");
	g8[j].numEq = bol1[pos].numEq;
	strcpy(g8[j].nombre, bol1[pos].nombre);
	strcpy(g8[j].federacion, bol1[pos].federacion);

	
	cout << g8[j].nombreGrupo <<endl;
	cout << g8[j].nombre<<"-"<<" ";
	cout << g8[j].federacion<<endl;
	cout << "_______________________"<<endl;

	break;

}


}
	
return;
}
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
void cargarBolilleros (FILE *regEquipos, Equipos vecEquipos[], Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[])
{
	Equipos lineaEquipo; //struct para leer y guardar los datos del archivo
	
	fread(&vecEquipos[32], sizeof(Equipos), 1, regEquipos);
	
	int i=0, j=0, k=0, m=0;
	
	while(!feof(regEquipos))
	{
		int numBol = vecEquipos[32].numBol;	
		
		if (numBol == 1)
		{
			while ( i < 8 )
			{
			bol1[i].numBol = vecEquipos[i].numBol;
			bol1[i].numEq = vecEquipos[i].numEq;
			strcpy(bol1[i].nombre, vecEquipos[i].nombre);
			strcpy(bol1[i].federacion, vecEquipos[i].federacion);
			i++;
			
			}
		}
		
			if (numBol == 2)
		{
			while ( j < 8 )
			{
				
			bol2[j].numBol = vecEquipos[j+8].numBol;
			bol2[j].numEq = vecEquipos[j+8].numEq;
			strcpy(bol2[j].nombre, vecEquipos[j+8].nombre);
			strcpy(bol2[j].federacion, vecEquipos[j+8].federacion);
			j++;

			}
		}
		
		if (numBol == 3)
		{
			while ( k < 8 )
			{
			bol3[k].numBol = vecEquipos[k+16].numBol;
			bol3[k].numEq = vecEquipos[k+16].numEq;
			strcpy(bol3[k].nombre, vecEquipos[k+16].nombre);
			strcpy(bol3[k].federacion, vecEquipos[k+16].federacion);
			k++;

			}
		}
		
			if (numBol == 4)
			{
			while ( m < 8 )
			{
			bol4[m].numBol = vecEquipos[m+24].numBol;
			bol4[m].numEq = vecEquipos[m+24].numEq;
			strcpy(bol4[m].nombre, vecEquipos[m+24].nombre);
			strcpy(bol4[m].federacion, vecEquipos[m+24].federacion);
			m++;

			}
		}
	
		fread(&vecEquipos[32], sizeof(Equipos), 1, regEquipos);

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
