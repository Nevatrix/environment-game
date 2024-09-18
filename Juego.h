#pragma once
#include "Escenario.h"
#include "vector"
#include "iostream"

using namespace std;

class Juego
{
public:
	Juego();
	~Juego();
	void menu();
private:
	Escenario* escenario;
    void color(int n);
    void Instrucciones();
};
