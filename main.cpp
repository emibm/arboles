#include<iostream>
#include "trees.h"
#include <windows.h>
#include <cstdio>

using namespace std;


/*+++++++++++++++++++++++++++++++++ WELCOME TO ARBOLES EJ 12 ++++++++++++++++++++++++++++++++++++ */

int main (int argc, char *argv[]) 
{
int exit=0, opcmenu, stock,orden;
double code;
float precio;
char seguir, descripcion[100];
char* desc=descripcion;

Producto lista=NULL;
ABB indice=NULL,inaux=NULL;

while(!exit)
{
inaux=NULL;
system("cls");
menu();
cin>>opcmenu;
fflush stdin;

switch(opcmenu)
	{
	case 1:
		do{			
		system("cls");
		menu();
		cout<<endl<<endl<<" Ingrese codigo del producto: ";
		cin>>code;
		fflush stdin;
		inaux=Search(indice,code);
		if(!inaux)
			{
			cout<<" Descripcion: ";	
			gets(desc);
			fflush stdin;
			cout<<" Precio: $ ";
			cin>>precio;
			fflush stdin;
			cout<<" Cantidad en stock: ";
			cin>>stock;
			fflush stdin;
			crearNodo(indice,lista,code,desc,precio,stock);
			}			
		if(inaux)
			{
			cout<<endl<<endl<<"                       ----- EL CODIGO YA EXISTE -----";
			cout<<endl<<"-> Descripcion: "; puts(inaux->producto->descripcion);
			cout<<"-> Stock actual: "<<inaux->producto->stock;
			cout<<endl<<endl<<"                  (?) Desea modificar stock ? (s/n): ";
			cin>>seguir;
			fflush stdin;
			
			if(seguir=='s' || seguir=='S')
				{					
				cout<<endl<<" Ingrese cantidad a restar o sumar: ";
				cin>>orden;
				fflush stdin;
				inaux->producto->stock=inaux->producto->stock+orden;
				cout<<endl<<"                       STOCK MODIFICADO CON EXITO !!";
				}			
			}
		else
			cout<<endl<<"               +++++ Producto agregado exitosamente !! +++++";
		
		cout<<endl<<endl<<" Seguir ingresando datos ? (s/n): ";
		cin>>seguir;
		fflush stdin;
		}while(seguir=='s' or seguir=='S');
	break;
	
	case 2:
		cout<<endl<<" 1) Mostrar por orden de ingreso";
		cout<<endl<<" 2) Mostrar ordenados por codigo";
		cout<<endl<<endl<<" <+> Ingrese una opcion: ";
		cin>>orden; 
		fflush stdin;
		MostrarP(indice,orden);
	break;
	
	case 3:		
		cout<<endl<<endl<<" (?) Ingrese codigo del producto: ";
		cin>>code;
		fflush stdin;
		if(indice) inaux=Search(indice,code);
		
		if(inaux)
			{
			cout<<endl<< " Codigo: "<<inaux->producto->codigo;	
			cout<<endl<< " Descripcion: ";
			puts(inaux->producto->descripcion);
			cout<<" Precio: $"<<inaux->producto->precio;
			cout<<endl<<" Stock: "<<inaux->producto->stock;		
			}
		else cout<<endl<<endl<<"                       ERROR: No se encuentra el codigo";
	break;
		
	case 4:
		cout<<endl<<endl<<" |><| Ingrese codigo del producto a eliminar |><| : ";
		cin>>code;
		fflush stdin;
		Delete(indice,lista,code);
	break;
	
	default:
		exit=1;
	break;	
	}

cout<<endl<<endl;
system("pause");
} // Fin while
return 0;
} // Fin main

