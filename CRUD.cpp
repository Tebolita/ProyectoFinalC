#include <iostream>
#include <windows.h>
using namespace std;

const char *nombre_archivo ="palabras.txt";

struct Palabra{
    char nombre[50];
    char traduccion[50];
    char significado[200]; 
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
        cin.getline(palabra.nombre,50);
        cout << "Ingrese la traduccion de la palabra: ";
        cin.getline(palabra.traduccion,50);
        cout << "Ingrese la funcionalidad: ";
        cin.getline(palabra.significado,200);
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
       // cout << "-----------------------------------------------------------------" << endl;
		cout <<"Palabra: "<< palabra.nombre << endl;
        cout <<"Traduccion: "<<palabra.traduccion<<endl;
        cout <<"Funcionalidad: "<<palabra.significado<<endl;
        cout << "--------------------------------------------------------------------" << endl;
		fread(&palabra,sizeof(palabra),1,archivo);
		id++;
	}while(feof(archivo)==0);
	fclose(archivo);
    system("pause");
    return 0;
}

// Mostrar solo las palabras al usuario
int leerOne(){
    FILE* archivo = fopen(nombre_archivo,"rb");
    Palabra palabra;
    if(!archivo){
        archivo = fopen(nombre_archivo,"w+b");
    }
    fread(&palabra,sizeof(Palabra),1,archivo);
    int id=0;
    cout << "Palabras disponibles" << endl;
    do{
        cout<< id <<": "<<palabra.nombre << " | ";
        fread(&palabra,sizeof(palabra),1,archivo);
        id++;
    }while(feof(archivo)==0);
    fclose(archivo);
    return id;
}

int actualizar(){
    char continuar;
    Palabra palabra;
    FILE* archivomodifcar = fopen(nombre_archivo,"r+b");
    int id;
    do
    {
        //Funcion de leer
        id = leerOne();
        //Parte de la actualizacion
        cout << " " << endl;
       
        int idfile = 0;
        cout << "Actualmente hay " << id << " id's actuales para actualizar" << endl;
        cout<<"Por favor indique el Id a modificar: ";
        cin>>idfile;
        cin.ignore();
        fseek(archivomodifcar,idfile * sizeof(Palabra),SEEK_SET);
        if(idfile<=id){
            cout << "Ingrese la modificacion de la palabra: ";
            cin.getline(palabra.nombre,50);
            cout << "Ingrese la modificacion de la traduccion: " ;
            cin.getline(palabra.traduccion,50);
            cout << "Ingrese la modificacion de la funcionalidad: ";
            cin.getline(palabra.significado,200);
            fwrite(&palabra,sizeof(Palabra),1,archivomodifcar);
            
            cout << "Ingrese S para actualizar otra palabra o N para regresar al menu principal" << endl; 
            cin >> continuar;  
            cin.ignore();  
        }else{
            system("cls");
            cout << "ID no encontrado" << endl;
            actualizar();
        }
    } while (continuar == 'S' || continuar == 's');
    fclose(archivomodifcar);
    if(continuar =='N' || continuar == 'n'){
        return 0;
    }
    
}


int borrar(){
    int id;
    char continuar;
    const char *nombre_archivo_temp ="archivo_temp.dat";
	FILE* archivo_temp = fopen(nombre_archivo_temp,"w+b");
	FILE* archivo = fopen(nombre_archivo,"rb");
	Palabra palabra;
	int idfile=0,id_n=0;
    do
    {
        //Funcion de leer
        id = leerOne();
        //Parte de la actualizacion
        cout << " " << endl;
         if(idfile<=id){
            cout<<"Ingre el ID a eliminar:";
            cin>>idfile;
            while(fread(&palabra,sizeof(Palabra),1,archivo)){
                if (id_n!=idfile){
                    fwrite(&palabra,sizeof(Palabra),1,archivo_temp);
                }
                id_n++;
            }
            fclose(archivo);
            fclose(archivo_temp);
            
            
            archivo_temp = fopen(nombre_archivo_temp,"rb");
            archivo = fopen(nombre_archivo,"wb");
            while(fread(&palabra,sizeof(Palabra),1,archivo_temp)){
                    fwrite(&palabra,sizeof(Palabra),1,archivo);
                
            }
            fclose(archivo);
            fclose(archivo_temp);
            cout << "Ingrese S para eleminar otra palabra o N para regresar al menu principal" << endl; 
            cin >> continuar;  
            cin.ignore();  
        }else{
            system("cls");
            cout << "ID no encontrado" << endl;
            borrar();
        }
    } while (continuar == 'S' || continuar == 's');
    if(continuar =='N' || continuar == 'n'){
        return 0;
    }



}
