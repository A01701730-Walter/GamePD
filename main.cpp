/*
Proyecto GamePD
Walter Humphrey
A01701730
01/06/2020
*/

/* GamePD es un servicio de streaming para jugar a cientos de 
videojuegos sin necesidad de comprarlos con solo pagar una suscripcion.
Este programa crea una biblioteca de juegos y muestra el ejemplo de
4 juegos con su titulo, rating y genero. Después se generan varios catálogos
agregando juegos y mostrando más información*/

// Se agregan las bibliotecas y clases
#include<iostream>
#include"Juego.h"
#include"Biblioteca.h"

using namespace std;

int main(){
	Biblioteca Biblioteca;
	Biblioteca.crea_ejemplo(); // Crea un catalogo con 4 juegos de ejemplo
	cout << " ------------------------" "\n" "\n";
	cout << " Catalogo " << "\n" "\n";
	Biblioteca.muestra_Catalogo(); // Imprime el catalogo
	cout << " ------------------------" "\n" "\n";
	cout << " Catalogo actualizado " << "\n" "\n";
	Biblioteca.agrega_sport("NBA:2K20", 8); // Agrega 1 juego
	Biblioteca.agrega_shooter("Battlefield V", 9); // Agrega 1 juego
	Biblioteca.muestra_Catalogo(); // Muestra el catalogo actualizado
	Biblioteca.clear_catalogo(); // Limpia catalogo
	cout << " ------------------------" "\n" "\n";
	cout << " Catalogo con mas informacion " << "\n" "\n";
	Biblioteca.crea_ejemploEXT(); // Crea catalogo con los 4 juegos de ejemplo pero con info extra
	Biblioteca.muestra_CatalogoEXT(); // Muestra catalogo con info extra
	cout << " ------------------------" "\n" "\n";
	cout << " Catalogo actualizado con mas informacion" << "\n" "\n";
	Biblioteca.agrega_sportEXT("NBA:2K20", 8, "Si", " Basketball", 25); // Agrega 1 juego con mas info
	Biblioteca.agrega_shooterEXT("Battlefield V", 9, "Si", " Primera Guerra Mundial", 60); // Agrega 1 juego con mas info
	Biblioteca.muestra_CatalogoEXT(); // Muestra catalogo actualizado con info extra
	cout << " ------------------------" "\n" "\n";
	cout << " Juego con informacion completa y espacio requerido con dlcs o expansiones" << "\n" "\n";
	Shooter C("Call of Duty", 9, "Si", " BR", 50); // Crea ejemplo de shooter
	C.calcula_espacio(50, 60); // Calcula el espacio base + dlc
	cout << C.to_stringEXT(); // Imprime
	RPG W("World of Warcraft", 9, "Si", " MMORPG", 30); // Crea ejemplo de rpg
	W.calcula_espacio(30, 30, 5); // Calcula el espacio base + expansiones + perfiles
	cout << W.to_stringEXT(); // Imprime
	cout << " ------------------------" "\n" "\n";	
	return 0;
}
