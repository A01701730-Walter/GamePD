/*
Proyecto GamePD
Walter Humphrey
A01701730
06/06/2020
*/

/*En esta clase "Biblioteca" se crea un catalogo que contiene
todos los juegos disponibles en la plataforma.*/

#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include"Juego.h"
using namespace std;

const int MAX = 1000; // Constante para tamaño de arreglos

class Biblioteca { // Se crea la classe de Biblioteca

// Se declaran atributos
private:
	int Titulos;// Variable de titulos (cantidad de juegos)
	Juego* Catalogo[MAX]; // El catalogo donde se agregaran los juegos 

// Se declaran metodos
public:
	Biblioteca() : Titulos(0), Catalogo() {}; // Constructor default

	void agrega_shooter(string name, int stars); // Funcion que agrega juegos shooter

	void agrega_rpg(string name, int stars); // Funcion que agrega juegos rpg

	void agrega_sport(string name, int stars); // Funcion que agrega juegos sport

	void agrega_shooterEXT(string name, int stars, string mp, string res, int gb); // Funcion que agrega juegos shooter

	void agrega_rpgEXT(string name, int stars, string mp, string res, int gb); // Funcion que agrega juegos rpg

	void agrega_sportEXT(string name, int stars, string mp, string res, int gb); // Funcion que agrega juegos sport

	void muestra_Catalogo(); // Funcion que muestra (imprime) el catalogo

	void crea_ejemplo(); // Funcion para crear ejemplos de varios juegos en tiempo de ejecucion con polimorfismo

	void muestra_CatalogoEXT(); // Funcion que muestra (imprime) el catalogo

	void crea_ejemploEXT(); // Funcion para crear ejemplos de varios juegos en tiempo de ejecucion con polimorfismo

	void clear_catalogo(); // Funcion para limpiar el catalogo
};

void Biblioteca::agrega_shooter(string name, int stars) { // Funcion que agrega juegos shooter a catalogo y aumenta el contador de titulos
	Catalogo[Titulos] = new Shooter(name, stars);
	Titulos++;

}

void Biblioteca::agrega_rpg(string name, int stars) { // Funcion que agrega juegos rpg a catalogo y aumenta el contador de titulos
	Catalogo[Titulos] = new RPG(name, stars);
	Titulos++;

}

void Biblioteca::agrega_sport(string name, int stars) { // Funcion que agrega juegos sport a catalogo y aumenta el contador de titulos
	Catalogo[Titulos] = new Sport(name, stars);
	Titulos++;

}

void Biblioteca::agrega_shooterEXT(string name, int stars, string mp, string res, int gb) { // Funcion que agrega juegos shooter a catalogo y aumenta el contador de titulos
	Catalogo[Titulos] = new Shooter(name, stars, mp, res, gb);
	Titulos++;

}

void Biblioteca::agrega_rpgEXT(string name, int stars, string mp, string res, int gb) { // Funcion que agrega juegos rpg a catalogo y aumenta el contador de titulos
	Catalogo[Titulos] = new RPG(name, stars, mp, res, gb);
	Titulos++;

}

void Biblioteca::agrega_sportEXT(string name, int stars, string mp, string res, int gb) { // Funcion que agrega juegos sport a catalogo y aumenta el contador de titulos
	Catalogo[Titulos] = new Sport(name, stars, mp, res, gb);
	Titulos++;

}

void Biblioteca::muestra_Catalogo() { // Funcion que muestra (imprime) el catalogo
	for (int i = 0; i < Titulos; i++)
		cout << Catalogo[i]->to_string();
}

void Biblioteca::crea_ejemplo() { // Funcion para crear ejemplos de varios juegos en tiempo de ejecucion con polimorfismo
	Catalogo[Titulos] = new Shooter("Fortnite", 9);
	Titulos++;
	Catalogo[Titulos] = new Shooter("Call of Duty", 8);
	Titulos++;
	Catalogo[Titulos] = new RPG("World of Warcraft", 9);
	Titulos++;
	Catalogo[Titulos] = new Sport("FIFA 20", 7);
	Titulos++;
}

void Biblioteca::muestra_CatalogoEXT() { // Funcion que muestra (imprime) el catalogo
	for (int i = 0; i < Titulos; i++)
		cout << Catalogo[i]->to_stringEXT();
}

void Biblioteca::crea_ejemploEXT() { // Funcion para crear ejemplos de varios juegos en tiempo de ejecucion con polimorfismo
	Catalogo[Titulos] = new Shooter("Fortnite", 9, " Si", " Battle Royale", 40);
	Titulos++;
	Catalogo[Titulos] = new Shooter("Call of Duty", 8, "Si", " FPS", 50);
	Titulos++;
	Catalogo[Titulos] = new RPG("World of Warcraft", 9, "Si", " MMORPG", 30);
	Titulos++;
	Catalogo[Titulos] = new Sport("FIFA 20", 7, "Si", " Futbol soccer", 25);
	Titulos++;
}

void Biblioteca::clear_catalogo() { // Funcion que limpia el catalogo
	Titulos = 0;
	Catalogo[Titulos] = 0;
}