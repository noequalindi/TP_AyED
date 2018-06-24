#ifndef structs_hpp
#define structs_hpp

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

#endif /* structs_hpp */
