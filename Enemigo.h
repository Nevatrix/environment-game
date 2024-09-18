#pragma once
#include "Entidad.h"
class Enemigo : public Entidad
{
public:
	Enemigo(int x, int y);
	void dibujar() override;
	bool getVisible() { return visible; }
	void setVisible(bool visible) { this->visible = visible; }
private:
	bool visible = false;
};