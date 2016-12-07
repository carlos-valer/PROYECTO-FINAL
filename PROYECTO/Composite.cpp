#include "Composite.h"

Composite::Composite(){}

//SE CREAN ASTEROIDES EN POSICIONES ALEATORIAS--------------------------------
void Composite::crear_asteroides(){
	for(int i=0;i<5;i++){
		asteroides.push_back(new Asteroide(rand()%75+3, rand()%5+4));
	}
}

void Composite::dibujar_asteroides(Nave nave){
	list <Asteroide *>::iterator it;
	
	for(it = asteroides.begin();it != asteroides.end();it++){
		(*it)->mover();
		(*it)->colision(nave); //COLISION ENTRE NAVE Y ASTEROIDES
	}
	
}

//void Composite::crear_balas(){
//	
//}

