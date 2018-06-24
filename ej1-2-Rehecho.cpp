#include <iostream>
#include <string.h>
#include <ctime>
#include <cstdlib>
using namespace std;

struct Bolillero
{
	char nombre[30];
	char federacion[30];
};

struct Equipo
{
	int numBol;
	char nombre[30];
	char federacion[30];
};

struct Grupo
{
	char nombreGrupo[10];
	int numBol;
	char nombre[30];
	char federacion[30];
};

void cargarBolilleros(Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[]);
void consolidarEquiposEnArchivo(Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[], int lenBol);
void sortearBolillero1(Bolillero bol1[], Grupo g1[], Grupo g2[],Grupo g3[], Grupo g4[], Grupo g5[], Grupo g6[], Grupo g7[], Grupo g8[], int &len);
void mostrarBolilleros(FILE *f, Equipo reg);
int generarNumeroAleatorio();

int main()
{
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

	cargarBolilleros(bol1,bol2,bol3,bol4);
	int lenBol = 8;
	int	lenGr = 0;
	
	Equipo regEquipo;
	FILE *regEquipos = fopen("Equipos.dat", "rb");
	consolidarEquiposEnArchivo(bol1,bol2,bol3,bol4, lenBol);
	
	mostrarBolilleros(regEquipos, regEquipo);
	
	
	fclose(regEquipos);
	
	sortearBolillero1(bol1, g1,g2,g3,g4,g5,g6,g7,g8, lenGr);
	return 0;
	
}

void cargarBolilleros(Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[])
{
	strcpy(bol1[0].nombre, "Rusia");
	strcpy(bol1[0].federacion, "AFC");
	
	strcpy(bol1[1].nombre, "Alemania");
	strcpy(bol1[1].federacion, "UEFA");
	
	strcpy(bol1[2].nombre, "Brasil");
	strcpy(bol1[2].federacion, "Conmebol");

	strcpy(bol1[3].nombre, "Portugal");
	strcpy(bol1[3].federacion, "UEFA");

	strcpy(bol1[4].nombre, "Argentina");
	strcpy(bol1[4].federacion, "Conmebol");

	strcpy(bol1[5].nombre, "Belgica");
	strcpy(bol1[5].federacion, "UEFA");

	strcpy(bol1[6].nombre, "Polonia");
	strcpy(bol1[6].federacion, "UEFA");

	strcpy(bol1[7].nombre, "Francia");
	strcpy(bol1[7].federacion, "UEFA");

	// ************ BOLILLERO 2 ***************

	strcpy(bol2[0].nombre, "Espana");
	strcpy(bol2[0].federacion, "UEFA");
	
	strcpy(bol2[1].nombre, "Peru");
	strcpy(bol2[1].federacion, "Conmebol");
	
	strcpy(bol2[2].nombre, "Suiza");
	strcpy(bol2[2].federacion, "UEFA");
	
	strcpy(bol2[3].nombre, "Inglaterra");
	strcpy(bol2[3].federacion, "UEFA");
	
	strcpy(bol2[4].nombre, "Colombia");
	strcpy(bol2[4].federacion, "Conmebol");

	strcpy(bol2[5].nombre, "Mexico");
	strcpy(bol2[5].federacion, "Concacaf");
	
	strcpy(bol2[6].nombre, "Uruguay");
	strcpy(bol2[6].federacion, "Conmebol");
	
	strcpy(bol2[7].nombre, "Croacia");
	strcpy(bol2[7].federacion, "UEFA");
	
	
	// ************ BOLILLERO 3 ***************

	strcpy(bol3[0].nombre, "Dinamarca");
	strcpy(bol3[0].federacion, "UEFA");
	
	strcpy(bol3[1].nombre, "Islandia");
	strcpy(bol3[1].federacion, "UEFA");
	
	strcpy(bol3[2].nombre, "Costa Rica");
	strcpy(bol3[2].federacion, "Concacaf");

	strcpy(bol3[3].nombre, "Suecia");
	strcpy(bol3[3].federacion, "UEFA");
	
	strcpy(bol3[4].nombre, "Tunez");
	strcpy(bol3[4].federacion, "CAF");

	strcpy(bol3[5].nombre, "Egipto");
	strcpy(bol3[5].federacion, "CAF");

	strcpy(bol3[6].nombre, "Senegal");
	strcpy(bol3[6].federacion, "CAF");
	
	strcpy(bol3[7].nombre, "Iran");
	strcpy(bol3[7].federacion, "AFC");

	
	// ************ BOLILLERO 4 ***************

	strcpy(bol4[0].nombre, "Serbia");
	strcpy(bol4[0].federacion, "UEFA");
	
	strcpy(bol4[1].nombre, "Nigeria");
	strcpy(bol4[1].federacion, "CAF");

	strcpy(bol4[2].nombre, "Australia");
	strcpy(bol4[2].federacion, "AFC");
	
	strcpy(bol4[3].nombre, "Japon");
	strcpy(bol4[3].federacion, "AFC");

	strcpy(bol4[4].nombre, "Marruecos");
	strcpy(bol4[4].federacion, "CAF");

	strcpy(bol4[5].nombre, "Panama");
	strcpy(bol4[5].federacion, "Concacaf");

	strcpy(bol4[6].nombre, "Corea del Sur");
	strcpy(bol4[6].federacion, "AFC");
	
	strcpy(bol4[7].nombre, "Arabia Saudita");
	strcpy(bol4[7].federacion, "AFC");
	
	return;
}
void consolidarEquiposEnArchivo(Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[], int lenBol)
{
	FILE *regEquipos = fopen("Equipos.dat", "wb+");
	Equipo regEquipo;
	
	int i=0, j=0, k=0, m=0;
	
	while(i<lenBol){
		regEquipo.numBol = 1;
		strcpy(regEquipo.nombre, bol1[i].nombre);
		strcpy(regEquipo.federacion, bol1[i].federacion);
		i++;
		fwrite(&regEquipo,sizeof(Equipo),1,regEquipos);
	}	

		while(j<lenBol){
		regEquipo.numBol = 2;
		strcpy(regEquipo.nombre, bol2[j].nombre);
		strcpy(regEquipo.federacion, bol2[j].federacion);
		j++;
		fwrite(&regEquipo,sizeof(Equipo),1,regEquipos);
	}	
		while(k<lenBol){
		regEquipo.numBol = 3;
		strcpy(regEquipo.nombre, bol3[k].nombre);
		strcpy(regEquipo.federacion, bol3[k].federacion);
		k++;
		fwrite(&regEquipo,sizeof(Equipo),1,regEquipos);
	}
	
		while(m<lenBol){
		regEquipo.numBol = 4;
		strcpy(regEquipo.nombre, bol4[m].nombre);
		strcpy(regEquipo.federacion, bol4[m].federacion);
		m++;
		fwrite(&regEquipo,sizeof(Equipo),1,regEquipos);
	}
	
	fclose(regEquipos);	
	return;
	
}
int generarNumeroAleatorio()
{    
	int numeroAleatorio = (rand() % 8); // para el sorteo de la fase de grupos se genera un numero aleatorio entre 0 y 7
	int numEquipoSorteado = numeroAleatorio;

	return numEquipoSorteado;
}
void sortearBolillero1(Bolillero bol1[],Grupo g1[],Grupo g2[], Grupo g3[], Grupo g4[], Grupo g5[], Grupo g6[],	Grupo g7[],	Grupo g8[], int &lenGr)
{
	
	int pos, i=0, j=1;

	srand( time( NULL ) );
	// sorteo del bolillero 1, solo se saca rusia y se inserta en el grupo A y el resto 7 equipos en el resto de los grupos
	cout << "************** SORTEO **************"<<endl;
	if ( i == 0)
	{
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
 
            if(pos != g1[aux2].numBol)
                aux2++;
 
            else{
                    pos = generarNumeroAleatorio();
                    aux2 = 0;
 
                }
                
    if (pos == 0)
	{
		pos++;
	}
   }
 
    g1[i].numBol = pos;
    cout << g1[i].numBol <<endl; //para ver el num que se sorteo


		switch (pos)
	{
	case 1:
	strcpy(g2[j].nombreGrupo , "Grupo B");
	strcpy(g2[j].nombre, bol1[pos].nombre);
	strcpy(g2[j].federacion, bol1[pos].federacion);
	
	cout << g2[j].nombreGrupo <<endl;
	cout << g2[j].nombre<<"-"<<" ";
	cout << g2[j].federacion << endl;
	cout << "_______________________"<<endl;
	
	break;
	
	case 2:
	
	strcpy(g3[j].nombreGrupo , "Grupo C");
	strcpy(g3[j].nombre, bol1[pos].nombre);
	strcpy(g3[j].federacion, bol1[pos].federacion);
	
	cout << g3[j].nombreGrupo <<endl;
	cout << g3[j].nombre<<"-"<<" ";
	cout << g3[j].federacion<<endl;
	cout << "_______________________"<<endl;

	break;

	case 3:
	
	strcpy(g4[j].nombreGrupo , "Grupo D");
	strcpy(g4[j].nombre, bol1[pos].nombre);
	strcpy(g4[j].federacion, bol1[pos].federacion);
		
	cout << g4[j].nombreGrupo <<endl;
	cout << g4[j].nombre<<"-"<<" ";
	cout << g4[j].federacion<<endl;
	cout << "_______________________"<<endl;
	
		
	break;
	
	case 4:		
	strcpy(g5[j].nombreGrupo , "Grupo E");
	strcpy(g5[j].nombre, bol1[pos].nombre);
	strcpy(g5[j].federacion, bol1[pos].federacion);
	
	cout << g5[j].nombreGrupo <<endl;
	cout << g5[j].nombre<<"-"<<" ";
	cout << g5[j].federacion<<endl;
	cout << "_______________________"<<endl;
	
	break;
	
	case 5:
	
	strcpy(g6[j].nombreGrupo , "Grupo F");
	strcpy(g6[j].nombre, bol1[pos].nombre);
	strcpy(g6[j].federacion, bol1[pos].federacion);
	
	cout << g6[j].nombreGrupo <<endl;
	cout << g6[j].nombre<<"-"<<" ";
	cout << g6[j].federacion<<endl;
	cout << "_______________________"<<endl;


	break;
	
	case 6:	
	
	strcpy(g7[j].nombreGrupo , "Grupo G");
	strcpy(g7[j].nombre, bol1[pos].nombre);
	strcpy(g7[j].federacion, bol1[pos].federacion);
	
	cout << g7[j].nombreGrupo <<endl;
	cout << g7[j].nombre<<"-"<<" ";
	cout << g7[j].federacion<<endl;
	cout << "_______________________"<<endl;

	break;
	
	case 7:
	
	strcpy(g8[j].nombreGrupo , "Grupo H");
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

void mostrarBolilleros(FILE *regEquipos, Equipo regEquipo)
{
	fread(&regEquipo, sizeof(Equipo), 1, regEquipos);
	while (!feof(regEquipos))
	{
		cout << "Bolillero "<< regEquipo.numBol <<" "<<" - ";
		cout << regEquipo.nombre <<" -> "<<" ";
		cout << regEquipo.federacion <<endl;
		cout << "________________________" << endl;
		fread(&regEquipo,sizeof(Equipo),1,regEquipos);	
	}
	return;
}
