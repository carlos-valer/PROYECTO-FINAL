#include "Memento.h"
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

Memento::Memento() {}

void Memento::guardar_puntaje(int puntaje)
{
	ofstream entrada_;
	entrada_.open("puntaje.txt",ios::out);
	entrada_ << puntaje <<endl;
	entrada_.close();
	
	ofstream entrada;
	entrada.open("maximos_puntajes.txt",ios::out | ios::app);
	entrada << puntaje <<endl;
	entrada.close();
}
int Memento::cargar_puntaje()
{
	ifstream salida;
	salida.open("puntaje.txt",ios::in);
	
	if(salida.fail()){ puntaje = 0;}
	else{
		salida >> puntaje;
	}
	return puntaje;
}

int Memento::get_max_puntaje()
{
	ifstream salida;
	salida.open("maximos_puntajes.txt", ios::in);
	if(salida.fail()){
		max_puntaje = 0;
		cout << "NO HAY PUNTAJES REGISTRADOS !!!"<<endl;
	}
	else{
		int puntos;
		vector <int > lista;
		salida >> puntos;
		
		while(!salida.eof()){
			lista.push_back(puntos);
			salida >> puntos;
		}
		max_puntaje = lista[0];
		for(int i=1;i<lista.size();i++){
			if(max_puntaje < lista[i]){max_puntaje = lista[i];}
		}
	}
	return max_puntaje;
}
