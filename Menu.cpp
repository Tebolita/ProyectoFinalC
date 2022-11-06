#include "CRUD.cpp"
#include "IngresoTexto.cpp"
#include <iostream>
using namespace std;

int repetir;
void menu(){
    int opcion;
    cout << "Bienvenido" << endl;
    cout << "Programa para la traduccion de palabras"<< endl;
    cout << "0. Limpiar consola"<< endl;
    cout << "1. Ingresar una nueva palabra"<< endl;
    cout << "2. Leer las palabras en el sistema"<< endl;
    cout << "3. Actualizar un registro existente"<< endl; 
    cout << "4. Eliminar un registro existente"<< endl; 
    cout << "5. Ingresar texto a traduccir"<< endl; 
    cout << "Ingrese una opcion"<< endl;
    cin >> opcion;

    switch (opcion)
    {
     case 0:
        system("cls");
        menu();
        break;
    case 1:
        repetir= crear();
        if(repetir == 0){
            system("cls");
            menu();
        }
        break;


    case 2:
        repetir= leer();
        if(repetir == 0){
            system("cls");
            menu();
        }
        break;

    case 3:
        repetir= actualizar();
        if(repetir == 0){
            system("cls");
            menu();
        }
        break;
    case 4:
        repetir= borrar();
        if(repetir == 0){
            system("cls");
            menu();
        }
        break;
    case 5:
        repetir = ingreso_del_texto();
        if(repetir == 0){
            system("cls");
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