#ifndef FACADE_H
#define FACADE_H

#include <windows.h>

class Facade {
private:
	HANDLE pantalla;
	COORD xy_pos;
	
public:
	Facade();
	void gotoxy(int, int);
	
};

#endif

