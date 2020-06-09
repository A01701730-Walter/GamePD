/*
Proyecto GamePD
Walter Humphrey
A01701730
09/06/2020
*/

/*En esta clase "Biblioteca" se crea un catalogo que contiene
todos los juegos disponibles en la plataforma.*/

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include"Juego.h"
using namespace std;

// Constante para tamaño de arreglos
const int MAX = 1000; 

// Se crea la classe de Biblioteca
class Biblioteca { 

// Se declaran atributos
private:
	// Variable de titulos (cantidad de juegos)
	int Titulos;
	// El catalogo donde se agregaran los juegos 
	Juego* Catalogo[MAX]; 

// Se declaran metodos
public:
	// Constructor default
	Biblioteca() : Titulos(0), Catalogo() {}; 
	
	// Funcion que agrega juegos shooter
	void agrega_shooter(string name, int stars); 
	
	// Funcion que agrega juegos rpg
	void agrega_rpg(string name, int stars); 
	
	// Funcion que agrega juegos sport
	void agrega_sport(string name, int stars); 
	
	// Funcion que agrega juegos shooter (atributos extra)
	void agrega_shooterEXT(string name, int stars, string mp, string res, int gb); 

	// Funcion que agrega juegos rpg (atributos extra)
	void agrega_rpgEXT(string name, int stars, string mp, string res, int gb); 

	// Funcion que agrega juegos sport (atributos extra)
	void agrega_sportEXT(string name, int stars, string mp, string res, int gb); 

	// Funcion que muestra (imprime) el catalogo
	void muestra_Catalogo(); 

	// Funcion para crear ejemplos de varios juegos en tiempo de ejecucion con polimorfismo
	void crea_ejemplo(); 

	// Funcion que muestra (imprime) el catalogo (atributos extra)
	void muestra_CatalogoEXT(); 

	// Funcion para crear ejemplos de varios juegos (atributos extra) en tiempo de ejecucion con polimorfismo
	void crea_ejemploEXT(); 

	// Funcion para limpiar el catalogo
	void clear_catalogo(); 
};

// Funcion que agrega juegos shooter a catalogo y aumenta el contador de titulos
void Biblioteca::agrega_shooter(string name, int stars) { 
	Catalogo[Titulos] = new Shooter(name, stars);
	Titulos++;

}

// Funcion que agrega juegos rpg a catalogo y aumenta el contador de titulos
void Biblioteca::agrega_rpg(string name, int stars) { 
	Catalogo[Titulos] = new RPG(name, stars);
	Titulos++;

}

// Funcion que agrega juegos sport a catalogo y aumenta el contador de titulos
void Biblioteca::agrega_sport(string name, int stars) { 
	Catalogo[Titulos] = new Sport(name, stars);
	Titulos++;

}

// Funcion que agrega juegos shooter (atributos extra) a catalogo y aumenta el contador de titulos
void Biblioteca::agrega_shooterEXT(string name, int stars, string mp, string res, int gb) { 
	Catalogo[Titulos] = new Shooter(name, stars, mp, res, gb);
	Titulos++;

}

// Funcion que agrega juegos rpg (atributos extra) a catalogo y aumenta el contador de titulos
void Biblioteca::agrega_rpgEXT(string name, int stars, string mp, string res, int gb) { 
	Catalogo[Titulos] = new RPG(name, stars, mp, res, gb);
	Titulos++;

}

// Funcion que agrega juegos sport (atributos extra) a catalogo y aumenta el contador de titulos
void Biblioteca::agrega_sportEXT(string name, int stars, string mp, string res, int gb) { 
	Catalogo[Titulos] = new Sport(name, stars, mp, res, gb);
	Titulos++;

}

// Funcion que recorre el catalogo imprimiendo juego por juego
void Biblioteca::muestra_Catalogo() { 
	for (int i = 0; i < Titulos; i++)
		cout << Catalogo[i]->to_string();
}

// Funcion para crear ejemplos de varios juegos en tiempo de ejecucion con polimorfismo y agregarlos al catalogo
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

// Funcion que recorre el catalogo imprimiendo juego por juego (atributos extra)
void Biblioteca::muestra_CatalogoEXT() { 
	for (int i = 0; i < Titulos; i++)
		cout << Catalogo[i]->to_stringEXT();
}

// Funcion para crear ejemplos de varios juegos (atributos extra) en tiempo de ejecucion con polimorfismo y agregarlos al catalogo
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

// Funcion que limpia el catalogo
void Biblioteca::clear_catalogo() { 
	Titulos = 0;
	Catalogo[Titulos] = 0;
}