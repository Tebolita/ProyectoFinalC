#include <iostream>
using namespace std;

const char *nombre_archivo ="palabras.dat";

struct Palabra{
    char palabra[50];
    char traduccion[50];
    char funcionalidad[200]; 
};

int crear(){
    FILE* archivo = fopen(nombre_archivo, "a+b");
    Palabra palabra;
    char continuar;
    cout << "Bienvenido!!" << endl;
    do
    {
        fflush(stdin);
        cout << "Ingrese la palabra a traduccir: ";
        cin.getline(palabra.palabra,50);
        cout << "Ingrese la traduccion de la palabra: ";
        cin.getline(palabra.traduccion,50);
        cout << "Ingrese la funcionalidad: ";
        cin.getline(palabra.funcionalidad,200);
        fwrite(&palabra,sizeof(Palabra),1,archivo);

        cout << "Palabra ingresada exitosamente!!" << endl;
        cout << "Deseas ingresar otra palabra?" << endl; 
        cout << "Ingrese S para continuar o N para regresar al menu principal" << endl; 
        cin >> continuar;
    } while (continuar=='S' || continuar =='s');
    fclose(archivo);
    if(continuar =='N' || continuar == 'n'){
        return 0;
    }
}

int leer(){
	FILE* archivo = fopen(nombre_archivo,"rb");
	if(!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Palabra palabra;
	fread(&palabra,sizeof(Palabra),1,archivo);
	int id=0;
	do{
        cout << "__________________________________________________________________________" << endl;
		cout<<palabra.palabra<<" | "<<palabra.traduccion<<" | "<<palabra.funcionalidad<<endl;
        cout << "__________________________________________________________________________" << endl;
		fread(&palabra,sizeof(palabra),1,archivo);
		id++;
	}while(feof(archivo)==0);
	fclose(archivo);
}