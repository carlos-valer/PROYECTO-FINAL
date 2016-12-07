#include <iostream>
#include <windows.h>
#include <conio.h>
#include <list>

#include "Facade.h"
#include "Memento.h"
#include "Nave.h"
#include "Asteroide.h"
#include "Bala.h"


using namespace std;

void gotoxy(int x, int y)
{
	HANDLE pantalla;
	pantalla = GetStdHandle(STD_OUTPUT_HANDLE);
	
	COORD xy_pos;
	
	xy_pos.X = x;
	xy_pos.Y = y;	
	
	SetConsoleCursorPosition(pantalla, xy_pos);
}
void ocultar_cursor()
{
	HANDLE pantalla;
	pantalla = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursor;
	
	cursor.dwSize = 100;
	cursor.bVisible = FALSE;
	
	SetConsoleCursorInfo(pantalla,&cursor);
}



 
int main () {
	Facade facade;
	Memento memento;
	ocultar_cursor();
	facade.gotoxy(20,10);
	printf("1) CARGAR JUEGO");
	facade.gotoxy(20,12);
	printf("2) NUEVA PARTIDA ");
	
	char rpta;
	scanf("%c",&rpta);
	
	int puntaje;
	if(rpta == '1'){
		puntaje = memento.cargar_puntaje();
	}
	else{puntaje = 0;}
	system("cls");
	
//	SE CREA UNA NAVE CON UNA POSICION Y CANTIDAD DE VIDAS PASADO POR PARAMETRO
	Nave nave(37,30,3,3);
//	--------------------------------------
	
//	SE DIBUJA LOS BORDES DEL ESCENARIO
	nave.pintar_limites();
	
	nave.pintar();
	nave.ver_vidas();
//	----------------------------------------------
	list <Asteroide *> asteroides;
	list <Asteroide *>::iterator it_ast;
	
	for(int i=0;i<2;i++){
		asteroides.push_back(new Asteroide(rand()%75+3, rand()%5+4));
	}

	list <Bala *> balas;
	list <Bala *>::iterator it;
	bool perder = false;

	int cont = 0;
	while(!perder){
//		AUMENTAN LOS ASTEROIDES CADA CIERTO TIEMPO
		cont++;
		if(cont%50 == 0){
			
			asteroides.push_back(new Asteroide(rand()%75+3, rand()%5+4));
			asteroides.push_back(new Asteroide(rand()%75+3, rand()%5+4));
		}
		facade.gotoxy(4,2);
		printf("PUNTOS : %d",puntaje);
//		VER SI SE PRESIONA UNA TECLA
		if(kbhit()){
			char tecla = getch();
			if(tecla == 'a'){
				balas.push_back(new Bala(nave.getX()+2, nave.getY()-1));
			}
//			PAUSAR
			while(tecla == 13){
				tecla = getch();
				if(tecla != 13){break;}
				
			}
		}

//		DIBUJO BALAS---------------------------------------------
		for(it = balas.begin();it!=balas.end();it++){
			(*it)->mover();
			if((*it)->limite()){
				facade.gotoxy((*it)->getX(), (*it)->getY());
				printf(" ");
				
				delete(*it);
				
				it = balas.erase(it);
			}
		}
		//		DIBUJO LOS ASTEROIDES---------------------------------------------
		for(it_ast=asteroides.begin();it_ast!=asteroides.end();it_ast++){
			(*it_ast)->mover();
			(*it_ast)->colision(nave); //COLISION ENTRE NAVE Y ASTEROIDES
		}
//		composite.dibujar_asteroides(nave);
		
		
//		COLISION ENTRE BALA Y ASTEROIDE----------------------------------------------------
		for(it_ast=asteroides.begin();it_ast!=asteroides.end();it_ast++){
			for(it = balas.begin();it!=balas.end();it++){
				if((*it_ast)->getX() == (*it)->getX() && ((*it_ast)->getY()+1 == (*it)->getY() || (*it_ast)->getY() == (*it)->getY())){
					facade.gotoxy((*it)->getX(), (*it)->getY());
					printf(" ");
					
					delete(*it);
					it = balas.erase(it);
					
					asteroides.push_back(new Asteroide(rand()%74+3, 4));
					
					facade.gotoxy((*it_ast)->getX(), (*it_ast)->getY());
					delete(*it_ast);
					it_ast = asteroides.erase(it_ast);
					
					puntaje+=5;
				}
			}
		}
//		VERIFICAR SI ESTAS MUERTO
		if(nave.getVidas() == 0){
			perder =true;
		}
		nave.morir();
		nave.mover();
		
		Sleep(30);
	}
	
	system("cls");
	facade.gotoxy(20, 10);
	printf("FIN DEL JUEGO !!!");
	
	facade.gotoxy(20,13);
	printf("PUNTAJE FINAL : %d",puntaje);
	memento.guardar_puntaje(puntaje);
	
	Sleep(1000);
	
	
	
	return 0;
}

