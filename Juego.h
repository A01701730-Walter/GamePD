/*
* Proyecto GamePD
* Walter Humphrey
* A01701730
* 10/06/2020
*/

// En esta clase se crean los juegos a partir de herencia de la clase "Juego", esta clase es abstracta

#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Se crea la clase Juego
class Juego { 

	// Se declaran los atributos que heredaran las clases shooter, rpg y sport
protected:
	string nombre;
	int rating;
	string genero;
	string multi;
	string resumen;
	int espacio;

	// Se declaran los métodos que heredaran las clases shooter, rpg y sport
public:
	Juego(string name, int stars, string genre); // Constructor

	Juego(string name, int stars, string genre, string mp, string res, int gb); // Constructor (sobrecarga)
	
	/*
	*	set_nombre recibe string y lo establece como atributo de nombre
	*	@param string de nombre del juego
	*	@return
	*/
	void set_nombre(string name) { nombre = name; } 
	
	/*
	*	set_rating recibe un numero entero y lo establece como atributo de rating 
	*	@param numero entero de rating del juego
	*	@return
	*/
	void set_rating(int stars) { rating = stars; } 
	
	/*
	*	set_genero recibe un string y lo establece como atributo de genero 
	*	@param string de genero
	*	@return
	*/
	void set_genero(string genre) { genero = genre; } 
	
	/*
	*	set_multi recibe un string y lo establece como atributo de multijugador 
	*	@param string de tipo de multijugador
	*	@return
	*/
	void set_multi(string mp) { multi = mp; } 
	
	/*
	*	set_resumen recibe un string y lo establece como atributo de resumen 
	*	@param string de resumen del juego (pequeña descripcion)
	*	@return
	*/
	void set_resumen(string res) { multi = res; } 
	
	/*
	*	get_nombre regresa un string de atributo con nombre
	*	@param 
	*	@return string con nombre del juego
	*/
	string get_nombre() { return nombre; }

	/* 
	*	get_rating regresa un entero de atributo rating 
	*	@param 
	*	@return numero entero de rating del juego
	*/
	int get_rating() { return rating; } 

	/*
	*	get_genero regresa un string de atributo genero 
	*	@param 
	*	@return string de genero
	*/
	string get_genero() { return genero; } 

	/*
	*	get_multi regresar un string de atributo multijugador 
	*	@param 
	*	@return string tipo de multijugador
	*/
	string get_multi() { return multi; } 

	/*
	*	get_resumen regresar un string de atributo resumen 
	*	@param 
	*	@return string con un resumen del juego (pequeña descripcion)
	*/
	string get_resumen() { return resumen; } 

	virtual string to_string() = 0; 
	
	virtual string to_stringEXT() = 0; 
	
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

// Se crea la clase shooter que hereda de juego
class Shooter : public Juego { 
public:
	
	Shooter(string name, int stars) : Juego(name, stars, "Shooter") { } // Se declara el constructor 
	
	Shooter(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "Shooter", mp, res, gb) { } // Constructor con atributos extra

	string to_string(); 
	
	string to_stringEXT(); 

	int calcula_espacio(int base, int dlc); 
};

/*
*	to_string concatena valores de atributos  y los regresa en forma de string para poder ser impresos
*	@param
*	@return string con los valores y texto concatenados
*/
string Shooter::to_string() { 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n" "\n";
	return aux.str();
}

/*
*	to_stringEXT concatena valores de atributos (base y extra) y los regresa en forma de string para poder ser impresos
*	@param
*	@return string con los valores y texto concatenados
*/
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

/*
*	calcula_espacio calcula y regresa el espacio. Recibe el peso del juego base y los dlcs y los suma
*	@param entero del peso base, entero del peso de dlcs
*	@return entero con el valor del espacio total
*/
int Shooter::calcula_espacio(int base, int dlc) { 
	espacio = base + dlc;
	return espacio;
}

// Se crea la clase rpg
class RPG : public Juego { 
public:
	
	RPG(string name, int stars) : Juego(name, stars, "RPG") { } // Se declara el constructor 
	
	RPG(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "RPG", mp, res, gb) { }	// Se declara el constructor con sobrecarga (atributos extra)
	
	string to_string(); 
	
	string to_stringEXT(); 
	
	int calcula_espacio(int base, int expansiones, int perfiles); 
};

/*
*	to_string concatena valores de atributos  y los regresa en forma de string para poder ser impresos
*	@param
*	@return string con los valores y texto concatenados
*/
string RPG::to_string() { 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n" "\n";
	return aux.str();
}

/*
*	to_stringEXT concatena valores de atributos (base y extra) y los regresa en forma de string para poder ser impresos
*	@param
*	@return string con los valores y texto concatenados
*/
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

/* 
*	calcula_espcio calcula y regresa el espacio espacio. Recibe el peso del juego base, expansiones y perfiles y los suma
*	@param entero del peso base, entero de peso de expansiones, entero de peso de perfiles
*	@return entero con el valor del espacio total
*/
int RPG::calcula_espacio(int base, int expansiones, int perfiles) { 
	espacio = base + expansiones + perfiles;
	return espacio;
}

// Se crea la clase sport
class Sport : public Juego { 
public:
	
	Sport(string name, int stars) : Juego(name, stars, "Sport") { } // Se declara el constructor 
	
	Sport(string name, int stars, string mp, string res, int gb) : Juego(name, stars, "Sport", mp, res, gb) { } // Se declara el constructor con sobrecarga (atributos extra)
	
	string to_string(); 

	string to_stringEXT(); 
	
	int calcula_espacio(int base); 
};

/*
*	to_string concatena valores de atributos  y los regresa en forma de string para poder ser impresos
*	@param
*	@return string con los valores y texto concatenados
*/
string Sport::to_string() { 
	stringstream aux;
	aux << " Nombre: " << nombre << "\n"
		<< " Rating: " << rating << "\n"
		<< " Genero: " << genero << "\n" "\n";
	return aux.str();
}

/*
*	to_stringEXT concatena valores de atributos (base y extra) y los regresa en forma de string para poder ser impresos
*	@param
*	@return string con los valores y texto concatenados
*/
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

/*
*	calcula_espacio recibe el espacio del juego base y lo regresa
*	@param entero del peso base
*	@return entero con el valor del espacio total
*/
int Sport::calcula_espacio(int base) { 
	espacio = base;
	return espacio;
}