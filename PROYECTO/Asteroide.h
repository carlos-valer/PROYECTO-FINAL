#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include "Nave.h"
#include "Facade.h"
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>

class Asteroide {
private:
	Facade facade;
	int x;
	int y;
	
public:
	Asteroide();
	Asteroide(int, int);
	int getX();
	int getY();
	void pintar();
	void mover();
	
	void colision(class Nave &);
};

#endif

