#ifndef NAVE_H
#define NAVE_H
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include "Facade.h"

class Nave {
private:
	Facade facade;
	int x;
	int y;
	int corazon;
	int vida;
public:
	Nave();
	Nave(int, int, int, int);
	int getX();
	int getY();
	int getVidas();
	void pintar();
	void borrar();
	void mover();
	void ver_vidas();
	void morir();
	
	void corazones();
	
	void pintar_limites();
	
};

#endif

