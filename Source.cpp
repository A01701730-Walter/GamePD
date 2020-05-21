/*
Proyecto GamePD
Walter Humphrey
A01701730
21/05/2020
*/

/* GamePD es un servicio de streaming para jugar a cientos de 
videojuegos sin necesidad de comprarlos con solo pagar una suscripcion.
Este programa crea una biblioteca de juegos y muestra el ejemplo de
4 juegos con su titulo, rating y genero. En proximos entregables se 
añadiran funcionalidades.*/

// Se agregan las bibliotecas y clases
#include<iostream>
#include"Juego.h"
#include"Biblioteca.h"

using namespace std;

int main(){
	Biblioteca Biblioteca;
	Biblioteca.crea_ejemplo();
	Biblioteca.muestra_Catalogo();

	return 0;
}