#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

#include "Ejercicio2.hpp"

void sortearFaseGrupos(Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[],Grupo g1[], Grupo g2[], Grupo g3[], Grupo g4[], Grupo g5[], Grupo g6[], Grupo g7[], Grupo g8[], int lenBol, int lenGr)
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
void cargarBolilleros (FILE *regEquipos, Equipos vecEquipos[], Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[])
{
    //Equipos lineaEquipo; //struct para leer y guardar los datos del archivo
    
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
