#ifndef Ejercicio1
#define Ejercicio1

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
void cargarBolilleros(FILE *f, Equipos vec[], Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[]);
void insertar(Grupo arr[], int &len, Bolillero bol[], int pos);
void sortearFaseGrupos(Bolillero bol1[], Bolillero bol2[], Bolillero bol3[], Bolillero bol4[], Grupo g1[], Grupo g2[],Grupo g3[], Grupo g4[], Grupo g5[], Grupo g6[], Grupo g7[], Grupo g8[], int lenBol, int lenGr);

#endif // Ejercicio1
