#ifndef BALA_H
#define BALA_H
#include "Facade.h"

#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
class Bala {
private:
	Facade facade;
	int x;
	int y;
public:
	Bala();
	Bala(int, int);
	
	int getX();
	int getY();
	void mover();
	bool limite();
};

#endif

