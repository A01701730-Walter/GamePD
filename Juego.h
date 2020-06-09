/*
Proyecto GamePD
Walter Humphrey
A01701730
09/06/2020
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
	// Constructor
	Juego(string name, int stars, string genre); 

	// Sobrecarga de constructor (atributos extra)
	Juego(string name, int stars, string genre, string mp, string res, int gb); 
	
	// Funcion que recibe string y lo establece como atributo de nombre
	void set_nombre(string name) { nombre = name; } 

	// Funcion que recibe un entero y lo establece como atributo de rating
	void set_rating(int stars) { rating = stars; } 

	// Funcion que recibe un string y lo establece como atributo de genero
	void set_genero(string genre) { genero = genre; } 

	// Funcion que recibe un string y lo establece como atributo de multijugador
	void set_multi(string mp) { multi = mp; } 

	// Funcion que recibe un string y lo establece como atributo de resumen
	void set_resumen(string res) { multi = res; } 

	// Funcion para regresar un string de atributo nombre
	string get_nombre() { return nombre; } 

	// Funcion para regresar un entero de atributo rating
	int get_rating() { return rating; } 

	// Funcion para regresar un string de atributo genero
	string get_genero() { return genero; } 

	// Funcion para regresar un string de atributo multijugador
	string get_multi() { return multi; } 

	// Funcion para regresar un string de atributo resumen
	string get_resumen() { return resumen; } 

	// Funcion para convertir atributos a string (Polimorsfismo)
	virtual string to_string() = 0; 
	
	// Funcion para convertir atributos a string (extendida)
	virtual string to_stringEXT() = 0; 
	
	// Funcion para calcular el espacio (sobreescritura)
	int calcula_espacio() { return espacio; }; 

};

// Se declara el constructor 
Juego::Juego(string name, int stars, string genre) { 
		nombre = name;
		rating = stars;
		genero = genre;
}

// Constructor con atributos extra
Juego::Juego(string name, int stars, string genre, string mp, string res, int gb) { 
		nombre = name;
		rating = stars;
		genero = genre;
		multi = mp;
		resumen = res;
		espacio = gb;
}

// Se crea la clase shooter
class Shooter : public Juego { 
public:
	// Se declara el constructor 
	Shooter(string name, int stars) : Juego(name, stars, "Shooter") { 

	}
	
	// Constructor con atributos extra
	Shooter(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "Shooter", mp, res, gb) { 

	}
	// Funcion que convierte atributos a string (nombre, rating y genero) 
	string to_string(); 
	
	// Funcion pque convierte atributos a string (nombre, rating,  genero, multijugador, espacio y pequeña descripción)
	string to_stringEXT(); 
	
	// Calcula espacio (sobreescritura)
	int calcula_espacio(int base, int dlc); 
};

// Funcion que concatena valores de atributos y los regresa en forma de string para poder ser impresos
string Shooter::to_string() { 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n" "\n";
	return aux.str();
}

// Funcion que concatena valores de atributos (extendido) y los regresa en forma de string para poder ser impresos
string Shooter::to_stringEXT() { 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n"
		<< " Multijugador: " << multi << "\n"
		<< " Espacio: " << espacio << " GB" << "\n"
		<< resumen << "\n" "\n";
	return aux.str();
}

// Calcula y regresa el espacio. Recibe el peso del juego base y los dlcs y los suma
int Shooter::calcula_espacio(int base, int dlc) { 
	espacio = base + dlc;
	return espacio;
}

// Se crea la clase rpg
class RPG : public Juego { 
public:
	// Se declara el constructor 
	RPG(string name, int stars) : Juego(name, stars, "RPG") { 

	} 
	
	// Se declara el constructor con sobrecarga (atributos extra)
	RPG(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "RPG", mp, res, gb) { 

	}
	
	// Funcion que convierte atributos a string (nombre, rating y genero)
	string to_string(); 
	
	// Funcion pque convierte atributos a string (nombre, rating,  genero, multijugador, espacio y pequeña descripción)
	string to_stringEXT(); 
	
	// Calcula espacio (sobreescritura)
	int calcula_espacio(int base, int expansiones, int perfiles); 
};

// Funcion que concatena valores de atributos y los regresa en forma de string para poder ser impresos 
string RPG::to_string() { 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n" "\n";
	return aux.str();
}

// Funcion que concatena valores de atributos (extendido) y los regresa en forma de string para poder ser impresos
string RPG::to_stringEXT() { 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n"
		<< " Multijugador: " << multi << "\n"
		<< " Espacio: " << espacio << " GB" << "\n"
		<< resumen << "\n" "\n";
	return aux.str();
}

// Calcula y regresa el espacio espacio. Recibe el peso del juego base, expansiones y perfiles y los suma
int RPG::calcula_espacio(int base, int expansiones, int perfiles) { 
	espacio = base + expansiones + perfiles;
	return espacio;
}

// Se crea la clase sport
class Sport : public Juego { 
public:
	// Se declara el constructor 
	Sport(string name, int stars) : Juego(name, stars, "Sport") { 

	}
	// Se declara el constructor con sobrecarga (atributos extra)
	Sport(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "Sport", mp, res, gb) { 

	}
	
	// Funcion que convierte atributos a string (nombre, rating y genero)
	string to_string(); 
	
	// Funcion para regresar nombre, rating, genero y pequeña descripción (extendida)
	string to_stringEXT(); 
	
	// Calcula espacio (sobreescritura)
	int calcula_espacio(int base); 
};

// Funcion que concatena valores de atributos y los regresa en forma de string para poder ser impresos
string Sport::to_string() { 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n" "\n";
	return aux.str();
}

// Funcion que concatena valores de atributos (extendido) y los regresa en forma de string para poder ser impresos
string Sport::to_stringEXT() { 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n"
		<< " Multijugador: " << multi << "\n"
		<< " Espacio: " << espacio << " GB" << "\n"
		<< resumen << "\n" "\n";
	return aux.str();
}

// Recibe el espacio del juego base y lo regresa
int Sport::calcula_espacio(int base) { 
	espacio = base;
	return espacio;
}