#pragma once
#include "Entidad.h"
#include "conio.h"
class Personaje : public Entidad
{
public:
	Personaje(int x, int y, int vidas);
	void mover();
	void dibujar() override;
	int getVidas() { return vidas; }
	void setVidas(int vidas) { this->vidas = vidas; }
protected:
    int vidas;
};
