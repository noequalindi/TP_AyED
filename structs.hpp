#ifndef structs_hpp
#define structs_hpp

struct Equipo
{
    char nombre[30];
    char federacion[30];
};

struct Bolilla
{
    int numBol;
    Equipo equipo;
};

#endif /* structs_hpp */
