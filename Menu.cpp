#include "CRUD.cpp"
#include <iostream>
using namespace std;

int repetir;
void menu(){
    int opcion;
    cout << "Bienvenido" << endl;
    cout << "Programa para la traduccion de palabras"<< endl;
    cout << "1. Ingresar una nueva palabra"<< endl;
    cout << "2. Leer las palabras en el sistema"<< endl;
    cout << "Ingrese una opcion"<< endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        repetir= crear();
        if(repetir == 0){
            menu();
        }
        break;


    case 2:
        repetir= leer();
        if(repetir == 0){
            menu();
        }
        break;

    default:
        break;
    }
}

main(){
    menu();
}