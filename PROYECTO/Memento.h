#ifndef MEMENTO_H
#define MEMENTO_H

class Memento {
private:
	int puntaje;
	int max_puntaje;
	
public:
	Memento();
	void guardar_puntaje(int);
	int cargar_puntaje();
	int get_max_puntaje();
	
};

#endif

