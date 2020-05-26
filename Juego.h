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
	string multi;
	string resumen;
	int espacio;

	// Se declaran los metodos
public:
	Juego(string name, int stars, string genre) { // Se declara el constructor 
		nombre = name;
		rating = stars;
		genero = genre;
	}

	Juego(string name, int stars, string genre, string mp, string res, int gb) { // Se sobrecarga el constructor 
		nombre = name;
		rating = stars;
		genero = genre;
		multi = mp;
		resumen = res;
		espacio = gb;
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

	void set_multi(string mp) { // Funcion para dar genero
		multi = mp;
	}

	void set_resumen(string res) { // Funcion para dar genero
		multi = res;
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

	string get_multi() { // Funcion para regresar genero
		return multi;
	}

	string get_resumen() { // Funcion para regresar genero
		return resumen;
	}
	virtual string to_string() = 0; // Funcion para convertir atributos a string

	virtual string to_stringEXT() = 0; // Funcion para convertir atributos a string (extendida)

	int calcula_espacio() { // Funcion para calcular el espacio (sobreescritura)

	}
};

class Shooter : public Juego { // Se crea la clase shooter
public:
	Shooter(string name, int stars) : Juego(name, stars, "Shooter") { // Se declara el constructor 

	}
	
	Shooter(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "Shooter", mp, res, gb) { // Se declara el constructor con sobrecarga

	}

	string to_string() { // Funcion para regresar nombre, rating y genero 
		stringstream aux;
		aux << " Nombre: " << nombre << "\n"
			<< " Rating: " << rating << "\n"
			<< " Genero: " << genero << "\n" "\n";
		return aux.str();
	}

	string to_stringEXT() { // Funcion para regresar nombre, rating, genero y pequeña descripción (extendida)
		stringstream aux;
		aux << " Nombre: " << nombre << "\n"
			<< " Rating: " << rating << "\n"
			<< " Genero: " << genero << "\n"
			<< " Multijugador: " << multi << "\n"
			<< " Espacio: " << espacio << " GB" << "\n"
			<< resumen << "\n" "\n";
		return aux.str();
	}

	int calcula_espacio(int base, int dlc) { // Calcula espacio (sobreescritura)
		espacio = base + dlc;
		return espacio;
	}
};

class RPG : public Juego { // Se crea la clase rpg
public:
	RPG(string name, int stars) : Juego(name, stars, "RPG") { // Se declara el constructor 

	}

	RPG(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "RPG", mp, res, gb) { // Se declara el constructor con sobrecarga

	}

	string to_string() { // Funcion para regresar nombre, rating y genero 
		stringstream aux;
		aux << " Nombre: " << nombre << "\n"
			<< " Rating: " << rating << "\n"
			<< " Genero: " << genero << "\n" "\n";
		return aux.str();
	}

	string to_stringEXT() { // Funcion para regresar nombre, rating, genero y pequeña descripción (extendida)
		stringstream aux;
		aux << " Nombre: " << nombre << "\n"
			<< " Rating: " << rating << "\n"
			<< " Genero: " << genero << "\n"
			<< " Multijugador: " << multi << "\n"
			<< " Espacio: " << espacio << " GB" << "\n"
			<< resumen << "\n" "\n";
		return aux.str();
	}

	int calcula_espacio(int base, int expansiones, int perfiles) { // Calcula espacio (sobreescritura)
		espacio = base + expansiones + perfiles;
		return espacio;
	}
};

class Sport : public Juego { // Se crea la clase sport
public:
	Sport(string name, int stars) : Juego(name, stars, "Sport") { // Se declara el constructor 

	}

	Sport(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "Sport", mp, res, gb) { // Se declara el constructor con sobrecarga

	}

	string to_string() { // Funcion para regresar nombre, rating y genero
		stringstream aux;
		aux << " Nombre: " << nombre << "\n"
			<< " Rating: " << rating << "\n"
			<< " Genero: " << genero << "\n" "\n";
		return aux.str();
	}

	string to_stringEXT() { // Funcion para regresar nombre, rating, genero y pequeña descripción (extendida)
		stringstream aux;
		aux << " Nombre: " << nombre << "\n"
			<< " Rating: " << rating << "\n"
			<< " Genero: " << genero << "\n"
			<< " Multijugador: " << multi << "\n"
			<< " Espacio: " << espacio << " GB" << "\n"
			<< resumen << "\n" "\n";
		return aux.str();
	}

	int calcula_espacio(int base) { // Calcula espacio (sobreescritura)
		espacio = base;
		return espacio;
	}
};
