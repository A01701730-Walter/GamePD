/*
Proyecto GamePD
Walter Humphrey
A01701730
06/06/2020
*/

//En esta clase se crean los juegos a partir de herencia de la clase "Juego", esta clase es abstracta

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
	string multi;
	string resumen;
	int espacio;

	// Se declaran los metodos
public:
	Juego(string name, int stars, string genre); // Constructor

	Juego(string name, int stars, string genre, string mp, string res, int gb); // Sobrecarga de constructor
	
	void set_nombre(string name) { nombre = name; } // Funcion para dar nombre

	void set_rating(int stars) { rating = stars; } // Funcion para dar rating

	void set_genero(string genre) { genero = genre; } // Funcion para dar genero

	void set_multi(string mp) { multi = mp; } // Funcion para dar genero

	void set_resumen(string res) { multi = res; } // Funcion para dar genero

	string get_nombre() { return nombre; } // Funcion para regresar nombre

	int get_rating() { return rating; } // Funcion para regresar rating

	string get_genero() { return genero; } // Funcion para regresar genero

	string get_multi() { return multi; } // Funcion para regresar genero

	string get_resumen() { return resumen; } // Funcion para regresar genero

	virtual string to_string() = 0; // Funcion para convertir atributos a string (Polimorsfismo)

	virtual string to_stringEXT() = 0; // Funcion para convertir atributos a string (extendida)

	int calcula_espacio() { return espacio; }; // Funcion para calcular el espacio (sobreescritura)

};

Juego::Juego(string name, int stars, string genre) { // Se declara el constructor 
		nombre = name;
		rating = stars;
		genero = genre;
}

Juego::Juego(string name, int stars, string genre, string mp, string res, int gb) { // Se sobrecarga el constructor, muestra informacion extendida
		nombre = name;
		rating = stars;
		genero = genre;
		multi = mp;
		resumen = res;
		espacio = gb;
}

class Shooter : public Juego { // Se crea la clase shooter
public:
	Shooter(string name, int stars) : Juego(name, stars, "Shooter") { // Se declara el constructor 

	}

	Shooter(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "Shooter", mp, res, gb) { // Se declara el constructor con sobrecarga

	}

	string to_string(); // Funcion para regresar nombre, rating y genero 

	string to_stringEXT(); // Funcion para regresar nombre, rating, genero y pequeña descripción (extendida)

	int calcula_espacio(int base, int dlc); // Calcula espacio (sobreescritura)
};

string Shooter::to_string() { // Funcion para regresar nombre, rating y genero 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n" "\n";
	return aux.str();
}

string Shooter::to_stringEXT() { // Funcion para regresar nombre, rating, genero y pequeña descripción (extendida)
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n"
		<< " Multijugador: " << multi << "\n"
		<< " Espacio: " << espacio << " GB" << "\n"
		<< resumen << "\n" "\n";
	return aux.str();
}

int Shooter::calcula_espacio(int base, int dlc) { // Calcula espacio, suma el peso del juego base mas dlcs
	espacio = base + dlc;
	return espacio;
}

class RPG : public Juego { // Se crea la clase rpg
public:
	RPG(string name, int stars) : Juego(name, stars, "RPG") { // Se declara el constructor 

	} 

	RPG(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "RPG", mp, res, gb) { // Se declara el constructor con sobrecarga, muestra informacion extendida

	}

	string to_string(); // Funcion para regresar nombre, rating y genero 

	string to_stringEXT(); // Funcion para regresar nombre, rating, genero y pequeña descripción (extendida)

	int calcula_espacio(int base, int expansiones, int perfiles); // Calcula espacio (sobreescritura)
};

string RPG::to_string() { // Funcion para regresar nombre, rating y genero 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n" "\n";
	return aux.str();
}

string RPG::to_stringEXT() { // Funcion para regresar nombre, rating, genero y pequeña descripción (extendida)
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n"
		<< " Multijugador: " << multi << "\n"
		<< " Espacio: " << espacio << " GB" << "\n"
		<< resumen << "\n" "\n";
	return aux.str();
}

int RPG::calcula_espacio(int base, int expansiones, int perfiles) { // Calcula espacio, suma el peso del juego base mas expansiones y perfiles
	espacio = base + expansiones + perfiles;
	return espacio;
}

class Sport : public Juego { // Se crea la clase sport
public:
	Sport(string name, int stars) : Juego(name, stars, "Sport") { // Se declara el constructor 

	}

	Sport(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "Sport", mp, res, gb) { // Se declara el constructor con sobrecarga, muestra informacion extendida

	}

	string to_string(); // Funcion para regresar nombre, rating y genero

	string to_stringEXT(); // Funcion para regresar nombre, rating, genero y pequeña descripción (extendida)

	int calcula_espacio(int base); // Calcula espacio (sobreescritura)
};

string Sport::to_string() { // Funcion para regresar nombre, rating y genero
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n" "\n";
	return aux.str();
}

string Sport::to_stringEXT() { // Funcion para regresar nombre, rating, genero y pequeña descripción (extendida)
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n"
		<< " Multijugador: " << multi << "\n"
		<< " Espacio: " << espacio << " GB" << "\n"
		<< resumen << "\n" "\n";
	return aux.str();
}

int Sport::calcula_espacio(int base) { // Calcula espacio que es el juego base
	espacio = base;
	return espacio;
}