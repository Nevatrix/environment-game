#pragma once
#include "Escenario.h"

class Juego
{
private:
	Escenario* escenario;
	void color(int n);
	void Instrucciones();
			
public:
	Juego();
	~Juego();
	void menu();
};