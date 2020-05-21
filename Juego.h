/*
Proyecto GamePD
Walter Humphrey
A01701730
21/05/2020
*/

/*En esta clase se crean los juegos a partir de herencia de la clase "Juego"*/

#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Juego { // Se crea la clase Juego
	// Se declaran los atributos que heredaran las clases shooter, rpg y sport
protected:
	string nombre;
	int rating;
	string genero;

	// Se declaran los metodos
public:
	Juego(string name, int stars, string genre) { // Se declara el constructor 
		nombre = name;
		rating = stars;
		genero = genre;
	}

	void set_nombre(string name) { // Funcion para dar nombre
		nombre = name;
	}

	void set_rating(int stars) { // Funcion para dar rating
		rating = stars;
	}

	void set_genero(string genre) { // Funcion para dar genero
		genero = genre;
	}

	string get_nombre() { // Funcion para regresar nombre
		return nombre;
	}

	int get_rating() { // Funcion para regresar rating
		return rating;
	}

	string get_genero() { // Funcion para regresar genero
		return genero;
	}

	virtual string to_string() = 0; // Funcion para convertir atributos a string
};

class Shooter : public Juego { // Se crea la clase shooter
public:
	Shooter(string name, int stars) : Juego(name, stars, "Shooter") { // Se declara el constructor 

	}
	
	string to_string() { // Funcion para regresar nombre, rating y genero
		stringstream aux;
		aux << " Nombre: " << nombre << "\n"
			<< " Rating: " << rating << "\n"
			<< " Genero: " << genero << "\n" << "\n";
		return aux.str();
	}
};

class RPG : public Juego { // Se crea la clase rpg
public:
	RPG(string name, int stars) : Juego(name, stars, "RPG") { // Se declara el constructor 

	}

	string to_string() { // Funcion para regresar nombre, rating y genero
		stringstream aux;
		aux << " Nombre: " << nombre << "\n"
			<< " Rating: " << rating << "\n"
			<< " Genero: " << genero << "\n" << "\n";
		return aux.str();
	}
};

class Sport : public Juego { // Se crea la clase sport
public:
	Sport(string name, int stars) : Juego(name, stars, "Sport") { // Se declara el constructor 

	}

	string to_string() { // Funcion para regresar nombre, rating y genero
		stringstream aux;
		aux << " Nombre: " << nombre << "\n"
			<< " Rating: " << rating << "\n"
			<< " Genero: " << genero << "\n" << "\n";
		return aux.str();
	}
};
