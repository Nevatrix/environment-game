#pragma once
#include "Agua.h"
#include "Reciclables.h"
#include "Personaje.h"
#include "Enemigo.h"
#include "Semillas.h"
#include "vector"

class Escenario
{
private:
    vector<Entidad*> listaEntidades;
    float porcentaje;
    int cantidad_enemigos = Entidad::RandInt(25, 30);
    int cantidad_agua = Entidad::RandInt(15, 20);
    int cantidad_reciclables = Entidad::RandInt(15, 20);
    int cantidad_semillas = Entidad::RandInt(10, 15);
    int contador_agua = 0;
    clock_t tiempo_ultimo_cambio;
    size_t indice_enemigo_actual;
    void addAgua(int x, int y);
    void addEnemigo(int x, int y);
    void addReciclable(int x, int y);
    void addSemilla(int x, int y);
    void addPersonaje(int x, int y);
    void imp_game_over();
    void imp_you_win();
    bool verificarColision(int x1, int y1, int x2, int y2);
    void generarPosicionNoUtilizada(vector<int>& posX_usadas, vector<int>& posY_usadas, int& x, int& y);
    void generarCuadricula();
    void generarCorazon(int x, int y, int color);
    void generarBarraPorcentaje(int porcentaje);
    void hacerVisibleEnemigo(size_t indice);

public:
    Escenario();
    ~Escenario();
    void play();
};