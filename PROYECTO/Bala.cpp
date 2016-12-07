#include "Bala.h"

Bala::Bala(){}

Bala::Bala(int x, int y) {
	this->x = x;
	this->y = y;
}

int Bala::getX(){return x;}

int Bala::getY(){return y;}

void Bala::mover()
{
	facade.gotoxy(x,y);
	printf(" ");
	
	y--;
	
	facade.gotoxy(x,y);
	printf("*") ;
}


//VER SI ESTA FUERA(PARA QUE NO SE QUEDE ARRIBA)
bool Bala::limite()
{
	if(y == 4){return true;}
	else{return false;}
}

