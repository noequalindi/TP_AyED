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
struct Grupo
{
    char letra;
    int asignados;
    Bolilla bolilla[4];
};

struct GenerarArchivo
{
	char letra[2];
	Equipo equipo;
	int numGrupo;
};

struct Consolidado
{
	char letra[2];
	Equipo equipo;
	int numGrupo;
};
#endif /* structs_hpp */
