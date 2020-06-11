/*
* Proyecto GamePD
* Walter Humphrey
* A01701730
* 10/06/2020
*/

/* 
*	GamePD es un servicio de streaming para jugar cientos de 
*	videojuegos sin necesidad de comprarlos con solo pagar una suscripcion.
*	El programa despliega un menu con diversas interacciones como mostrar el
*	catalogo y agregar un juego de cualquier genero.
*/

// Se agregan las bibliotecas y clases
#include<iostream>
#include"Juego.h"
#include"Biblioteca.h"

using namespace std;

int main(){
	Biblioteca Biblioteca; // Crea objeto Biblioteca
	bool salir = false;

	while (salir == false) { // Empieza ciclo
		int opcion;
		cout << "          GamePD         " "\n"; // Impresion del menu
		cout << " ------------------------" "\n";
		cout << " - Menu - " "\n";
		cout << "1. Mostrar catalogo base simple" "\n";
		cout << "2. Mostrar catalogo base extendido" "\n";
		cout << "3. Agregar Shooter" "\n";
		cout << "4. Agrega RPG" "\n";
		cout << "5. Agrega Sport" "\n";
		cout << "6. Salir" "\n";
		cout << "Seleccione su opcion: " "\n";
		cin >> opcion;
		string name;
		int stars;

		switch (opcion) {
			case 1:
				Biblioteca.clear_catalogo(); 
				Biblioteca.crea_ejemplo(); 
				Biblioteca.muestra_Catalogo(); 
				break;

			case 2:
				Biblioteca.clear_catalogo(); 
				Biblioteca.crea_ejemploEXT(); 
				Biblioteca.muestra_CatalogoEXT(); 
				break;
			
			case 3:
				Biblioteca.crea_ejemplo(); 
				cout << " Nombre: ";
				cin >> name;
				cout << " Rating: ";
				cin >> stars;
				Biblioteca.agrega_shooter(name, stars); 
				cout << "\n" " Catalogo: " "\n" "\n";
				Biblioteca.muestra_Catalogo(); 
				salir = true; 
				break;

			case 4:
				Biblioteca.crea_ejemplo(); 
				cout << " Nombre: ";
				cin >> name;
				cout << " Rating: ";
				cin >> stars;
				Biblioteca.agrega_rpg(name, stars);
				cout << "\n" " Catalogo: " "\n" "\n";
				Biblioteca.muestra_Catalogo();
				salir = true;
				break;

			case 5:
				Biblioteca.crea_ejemplo();
				cout << " Nombre: ";
				cin >> name;
				cout << " Rating: ";
				cin >> stars;
				Biblioteca.agrega_sport(name, stars);
				cout << "\n" " Catalogo: " "\n" "\n";
				Biblioteca.muestra_Catalogo();
				salir = true;
				break;

			case 6:
				salir = true;
				break;
		}
	}
	return 0;
}