#ifndef COMPOSITE_H
#define COMPOSITE_H
#include "Asteroide.h"
#include "Bala.h"
#include "Nave.h"
#include <list>
using namespace std;
class Composite : public Asteroide, Bala{
private:
	list <Bala *> balas;
	list <Asteroide *> asteroides;	
	
public:
	Composite();
	void crear_asteroides();
	void dibujar_asteroides(Nave);
	void crear_balas();
	void dibujar_balas();
};

#endif

