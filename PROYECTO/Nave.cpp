#include "Nave.h"

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80

Nave::Nave(){}

Nave::Nave(int x, int y, int corazon, int vida)
{
	this->x = x;
	this->y = y;
	this->corazon = corazon;
	this->vida = vida;
}

int Nave::getX(){
	return x;
}
int Nave::getY(){
	return y;
}

int Nave::getVidas(){
	return vida;
}

void Nave::corazones(){
	corazon--;
}
//DIBUJA LOS BORDES DEL ESCENARIO
void Nave::pintar_limites(){
	for(int i=2;i<78;i++){
		
		facade.gotoxy(i,3);
		printf("%c", 205);
		facade.gotoxy(i,33);
		printf("%c", 205);
	}
	for(int i=4;i< 33;i++){
		facade.gotoxy(2,i);
		printf("%c", 186);
		facade.gotoxy(77,i);
		printf("%c", 186);
	}
	
	facade.gotoxy(2,3);
	printf("%c",201);
	facade.gotoxy(2,33);
	printf("%c",200);
	facade.gotoxy(77,3);
	printf("%c",187);
	facade.gotoxy(77,33);
	printf("%c",188);
}



void Nave::pintar()
{
	facade.gotoxy(x,y);
	
	printf("  %c",30);
	facade.gotoxy(x,y+1);
	printf(" %c%c%c",30,30,30);
	facade.gotoxy(x,y+2);
	printf("%c%c %c%c",30,30,30,30);
}

void Nave::borrar()
{
	facade.gotoxy(x, y);
	printf("        ");
	facade.gotoxy(x, y+1);
	printf("        ");
	facade.gotoxy(x, y+2);
	printf("        ");
}

void Nave::mover()
{
	if(kbhit()){
		char tecla = getch();
		borrar();
		if(tecla == IZQUIERDA && x > 3){ x--;}
		if(tecla == DERECHA && x+6 < 78){ x++;}
		if(tecla == ARRIBA  && y > 4){ y--;}
		if(tecla == ABAJO  && y+3 <33){ y++;}
		
		pintar();
		ver_vidas();
	}	
}

void Nave::ver_vidas()
{
	facade.gotoxy (50,2);
	printf("VIDAS %d",vida);
	
	facade.gotoxy (64,2);
	printf("SALUD ");
	facade.gotoxy (70,2);
	printf("       ") ;
	for(int i =0;i<corazon;i++){
		facade.gotoxy(70+i,2);
		printf("%c",219);
	}
}

void Nave::morir()
{
	if(corazon == 0){
		borrar();
		
//		SIMULA UNA EXPLOSION-----------------------------------------------
		facade.gotoxy(x,y);
		printf("   **   ");
		facade.gotoxy(x,y+1);
		printf("  ****  ");
		facade.gotoxy(x,y+2);
		printf("   **   ");
		Sleep(200);
		
		borrar();
		facade.gotoxy(x,y);
		printf(" * ** *");
		facade.gotoxy(x,y+1);
		printf("  **** ");
		facade.gotoxy(x,y+2);
		printf(" * ** *");
		
		Sleep(200);
		borrar();
//		----------------------------------------------------------------
		
		vida--;
		corazon = 3;
		ver_vidas();
		
		pintar();
	}
}
