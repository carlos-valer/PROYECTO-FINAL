#include "Asteroide.h"

Asteroide::Asteroide(){}

Asteroide::Asteroide(int x, int y) {
	this->x=x;
	this->y=y;
}

int Asteroide::getX(){return x;}

int Asteroide::getY(){return y;}

void Asteroide::pintar()
{
	facade.gotoxy(x,y);
	printf("%c",184);
}

void Asteroide::mover()
{
	facade.gotoxy(x,y);
	printf(" ");
	y++;
	if(y>32){
		x =rand()%71+4;
		y=4;
	}
	pintar();
}

void Asteroide::colision(Nave &nave)
{
	if(x >= nave.getX() && x < nave.getX()+6 && y >=nave.getY() && y <=nave.getY()+2)
	{
		nave.corazones();
		nave.borrar();
		nave.pintar();
		nave.ver_vidas();
		x =rand()%71+4;
		y=4;
	}
	
	
	
}

