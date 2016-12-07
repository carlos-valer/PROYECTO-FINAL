#include "Facade.h"

Facade::Facade() {
	pantalla = GetStdHandle(STD_OUTPUT_HANDLE);
	
}
void Facade::gotoxy(int x, int y)
{
	xy_pos.X = x;
	xy_pos.Y = y;
	SetConsoleCursorPosition(pantalla, xy_pos);
}
