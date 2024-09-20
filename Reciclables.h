#pragma once
#include "Entidad.h"

class Reciclables : public Entidad
{
private:

public:
	Reciclables(int x, int y);
	void dibujar() override;
};