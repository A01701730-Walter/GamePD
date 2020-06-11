/*
* Proyecto GamePD
* Walter Humphrey
* A01701730
* 10/06/2020
*/

// En esta clase "Biblioteca" se crea un catalogo que contiene todos los juegos disponibles en la plataforma.

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include"Juego.h"
using namespace std;

const int MAX = 1000; // Constante para tamaño de arreglos

// Se crea la classe de Biblioteca
class Biblioteca { 

// Se declaran atributos
private:

	int Titulos; // Variable de titulos (cantidad de juegos)
	Juego* Catalogo[MAX]; // El catalogo donde se agregaran los juegos (como apuntador para polimorfismo)

// Se declaran metodos
public:
	
	Biblioteca() : Titulos(0), Catalogo() {}; // Constructor default
	
	void agrega_shooter(string name, int stars); 
	
	void agrega_rpg(string name, int stars); 

	void agrega_sport(string name, int stars); 

	void agrega_shooterEXT(string name, int stars, string mp, string res, int gb); 

	void agrega_rpgEXT(string name, int stars, string mp, string res, int gb); 

	void agrega_sportEXT(string name, int stars, string mp, string res, int gb); 

	void muestra_Catalogo(); 

	void crea_ejemplo(); 

	void muestra_CatalogoEXT(); 

	void crea_ejemploEXT(); 

	void clear_catalogo(); 
};

/*
*	agrega_shooter crea un objeto shooter y lo agrega en Catalogo[] en el 
*	indice de Titulos, despues agrega 1 al indice. Usamos new para polimorfismo.
*	@param string del nombre del juego y numero entero del rating del juego
*	@return
*/
void Biblioteca::agrega_shooter(string name, int stars) { 
	Catalogo[Titulos] = new Shooter(name, stars);
	Titulos++;

}

/*
*	agrega_rpg crea un objeto rpg y lo agrega en Catalogo[] en el
*	indice de Titulos, despues agrega 1 al indice. Usamos new para polimorfismo.
*	@param string del nombre del juego y numero entero del rating del juego
*	@return
*/
void Biblioteca::agrega_rpg(string name, int stars) { 
	Catalogo[Titulos] = new RPG(name, stars);
	Titulos++;

}

/*
*	agrega_sport crea un objeto sport y lo agrega en Catalogo[] en el
*	indice de Titulos, despues agrega 1 al indice. Usamos new para polimorfismo.
*	@param string del nombre del juego y numero entero del rating del juego
*	@return
*/
void Biblioteca::agrega_sport(string name, int stars) { 
	Catalogo[Titulos] = new Sport(name, stars);
	Titulos++;

}

/*
*	agrega_shooterEXT crea un objeto shooter con atributos extra y lo agrega en 
*	Catalogo[] en el indice de Titulos, despues agrega 1 al indice. 
*	Usamos new para polimorfismo.
*	@param string de nombre, numero entero de rating, string de tipo de multijugador, 
*		   string de resumen, numero entero de peso del juego
*	@return
*/
void Biblioteca::agrega_shooterEXT(string name, int stars, string mp, string res, int gb) { 
	Catalogo[Titulos] = new Shooter(name, stars, mp, res, gb);
	Titulos++;

}

/*
*	agrega_rpgEXT crea un objeto rpg con atributos extra y lo agrega en
*	Catalogo[] en el indice de Titulos, despues agrega 1 al indice.
*	Usamos new para polimorfismo.
*	@param string de nombre, numero entero de rating, string de tipo de multijugador,
*		   string de resumen, numero entero de peso del juego
*	@return
*/
void Biblioteca::agrega_rpgEXT(string name, int stars, string mp, string res, int gb) { 
	Catalogo[Titulos] = new RPG(name, stars, mp, res, gb);
	Titulos++;

}

/*
*	agrega_sportEXT crea un objeto sport con atributos extra y lo agrega en
*	Catalogo[] en el indice de Titulos, despues agrega 1 al indice.
*	Usamos new para polimorfismo.
*	@param string de nombre, numero entero de rating, string de tipo de multijugador,
*		   string de resumen, numero entero de peso del juego
*	@return
*/
void Biblioteca::agrega_sportEXT(string name, int stars, string mp, string res, int gb) { 
	Catalogo[Titulos] = new Sport(name, stars, mp, res, gb);
	Titulos++;

}

/*	
*	muestra_Catalogo recorre Catalogo[] imprimiendo juego por juego
*	con los atributos base
*	@param
*	@return
*/
void Biblioteca::muestra_Catalogo() { 
	for (int i = 0; i < Titulos; i++)
		cout << Catalogo[i]->to_string();
}

/*
*	crea_ejemplo crea dos juegos shooter, uno rpg y uno sport con
*	atributos de nombre y rating. Al crear un juego aumenta el indice.
*	Usamos new para polimorfismo.
*	@param
*	@return
*/
void Biblioteca::crea_ejemplo() { 
	Catalogo[Titulos] = new Shooter("Fortnite", 9);
	Titulos++;
	Catalogo[Titulos] = new Shooter("Call of Duty", 8);
	Titulos++;
	Catalogo[Titulos] = new RPG("World of Warcraft", 9);
	Titulos++;
	Catalogo[Titulos] = new Sport("FIFA 20", 7);
	Titulos++;
}

/*	
*	muestra_CatalogoEXT recorre Catalogo[] imprimiendo juego por juego
*	con los atributos extendidos
*	@param
*	@return
*/
void Biblioteca::muestra_CatalogoEXT() { 
	for (int i = 0; i < Titulos; i++)
		cout << Catalogo[i]->to_stringEXT();
}

/*
*	crea_ejemploEXT crea dos juegos shooter, uno rpg y uno sport con
*	atributos de nombre, rating, tipo de multijugador, resumen y espacio. 
*	Al crear un juego aumenta el indice. Usamos new para polimorfismo.
*	@param
*	@return
*/
void Biblioteca::crea_ejemploEXT() { 
	Catalogo[Titulos] = new Shooter("Fortnite", 9, "Online", " Battle Royale", 40);
	Titulos++;
	Catalogo[Titulos] = new Shooter("Call of Duty", 8, "Online y local", " FPS", 50);
	Titulos++;
	Catalogo[Titulos] = new RPG("World of Warcraft", 9, "Online", " MMORPG", 30);
	Titulos++;
	Catalogo[Titulos] = new Sport("FIFA 20", 7, "Online y local", " Futbol soccer", 25);
	Titulos++;
}

/*
*	clear_catalogo limpia Catalogo[] y regresa el indice a 0
*	@param
*	@return
*/
void Biblioteca::clear_catalogo() { 
	Titulos = 0;
	Catalogo[Titulos] = 0;
}