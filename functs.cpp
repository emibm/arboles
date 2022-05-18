#include<iostream>
#include "trees.h"
#include <cstdio>
#include <cstdlib>
#include <string.h>

using namespace std;

void menu()
{
cout<<endl<<"                  ------|| D I S T R I B U I D O R A ||------"<<endl<<endl<<endl;	
cout<<"  1) Agregar producto / Modificar stock"<<endl<<endl;
cout<<"  2) Mostrar arbol de busqueda"<<endl<<endl;
cout<<"  3) Buscar un producto por el codigo"<<endl<<endl;
cout<<"  4) Eliminar un producto"<<endl<<endl;
cout<<"  0) << S A L I R >>"<<endl<<endl;
cout<<endl<<"                           <+> Eliga una opcion: ";
}

/* +++++++++++++++++++++++++++++++ crearNodo +++++++++++++++++++++++++++++++++ */

ABB crearNodo(ABB &arbol,Producto &lista,double code,char* descripcion,float precio,int stock)
{
Producto nuevo = new nodoProducto;
Producto aux=lista,antaux=NULL;

nuevo->codigo=code;
strcpy(nuevo->descripcion,descripcion);
nuevo->precio=precio;
nuevo->stock=stock;
nuevo->siguiente=NULL;

if(!lista)
	{
	lista=nuevo;
	insertar(arbol,crearNodoABB(code,nuevo));
	return arbol;
	}

while(aux)
	{
	if(aux->codigo==code) break;	
	antaux=aux;
	aux=aux->siguiente;
	}
if(aux) {delete(nuevo);return NULL;}
if(antaux) antaux->siguiente=nuevo;

insertar(arbol,crearNodoABB(code,nuevo));
return arbol;
}

/* +++++++++++++++++++++++++++++++ crearNodoABB +++++++++++++++++++++++++++++++++ */

ABB crearNodoABB(double code,Producto lista)
{
ABB nuevo=new nodoArbol;                                                                                                                                          
nuevo->prod_code=lista->codigo;
nuevo->producto=lista;
nuevo->izq=NULL;
nuevo->der=NULL;
return nuevo;
}

/* +++++++++++++++++++++++++++++++ inOrden +++++++++++++++++++++++++++++++++

– Inorden hijo izquierdo
– Visita al padre
– Inorden hijo derecho */

void inOrden(ABB arbol)
{
if (arbol==NULL)
	return;

inOrden(arbol->izq);

cout<<endl<< " Codigo: "<<arbol->producto->codigo;	
cout<<endl<< " Descripcion: ";
puts(arbol->producto->descripcion);
cout<<" Precio: $"<<arbol->producto->precio;
cout<<endl<<" Stock: "<<arbol->producto->stock;
cout<<endl;

inOrden(arbol->der);
}

/* +++++++++++++++++++++++++++++++ insertar +++++++++++++++++++++++++++++++++ */

void insertar (ABB &arbol, ABB n)
{
if(arbol==NULL)	arbol=n;
else
	if(n->prod_code<arbol->prod_code)
		insertar(arbol->izq,n);
	else
		if(n->prod_code>arbol->prod_code)
			insertar(arbol->der,n);
}

/* +++++++++++++++++++++++++++++++ MostrarP +++++++++++++++++++++++++++++++++ */

void MostrarP(ABB arbol,int ord)
{
if(ord!=1 && ord!=2){cout<<endl<<endl<<"                    ------ ERROR: Opcion invalida ------";return;}	
if(!arbol){cout<<endl<<endl<<"                 ------ No hay productos para mostrar ------";return;}
system("cls");
cout<<endl<<"                  ------|| D I S T R I B U I D O R A ||------";
cout<<endl<<"                    ++++++++++ P R O D U C T O S ++++++++++"<<endl<<endl;

Producto aux=arbol->producto;
switch(ord)
	{
	case 1:		
	while (aux)
		{
		cout<<endl<< " Codigo: "<<aux->codigo;	
		cout<<endl<< " Descripcion: ";
		puts(aux->descripcion);
		cout<<" Precio: $"<<aux->precio;
		cout<<endl<<" Stock: "<<aux->stock;
		cout<<endl;
		aux=aux->siguiente;
		}
	break;
	
	case 2:
		inOrden(arbol);
	break;
	
	default:
		cout<<endl<<" ERROR - Elija una opcion correcta";
	break;
	}
}

/* +++++++++++++++++++++++++++++++ Search +++++++++++++++++++++++++++++++++ */

ABB Search(ABB arbol,double code)
{
if(!arbol) return NULL;	
if(code > arbol->prod_code)Search(arbol->der,code);
if(code < arbol->prod_code)Search(arbol->izq,code);
if(code == arbol->prod_code) return arbol;
}

/* +++++++++++++++++++++++++++++++ Delete +++++++++++++++++++++++++++++++++ */

void Delete(ABB &arbol,Producto &lista,double code)
{
Producto aux=lista,antaux=NULL;
char s;

while(aux)
	{
	if(aux->codigo==code) break;		
	antaux=aux;
	aux=aux->siguiente;
	}
if(!aux){cout<<endl<<endl<<"                         ERROR: Producto no encontrado"; return;}
if(aux->stock != 0) {cout<<endl<<endl<<"                    ERROR: No es posible la eliminacion del producto"; return;}

cout<<endl<<" Descripcion del producto: ";puts(aux->descripcion);
cout<<endl<<" |><| Seguro que desea borrar ? (s/n): ";cin>>s;fflush stdin;
if(s!='s' && s!='S') return;

if(!antaux) 
    {	
	aux->siguiente=NULL;	
	delete aux;	 
	borrar(arbol,code);
	lista=NULL;
	}
else 
    {
	antaux->siguiente=aux->siguiente;	
	aux->siguiente=NULL;
	delete aux;
	borrar(arbol,code);
	}

cout<<endl<<"                  +++++++ Producto borrado con exito !! +++++++";
return;
}

/*+++++++++++++++++++++++++++++++ Borrar un nodo +++++++++++++++++++++++++++++++++ */

void borrar(ABB &arbol, double x)
{
if(arbol==NULL)
	return;
if(x<arbol->prod_code)
	borrar(arbol->izq, x);
else
	if(x>arbol->prod_code)
		borrar(arbol->der, x);
	else
		{
		ABB p = arbol;
		arbol = unirABB(arbol->izq, arbol->der);
		delete p;
		}
}

/* +++++++++++++++++++++++++++++++ unirABB +++++++++++++++++++++++++++++++++ */

ABB unirABB(ABB izq, ABB der)
{
if(izq==NULL) 
	return der;
if(der==NULL) 
	return izq;

ABB centro = unirABB(izq->der, der->izq);
izq->der = centro;
der->izq = izq;

return der;
}

/* +++++++++++++++++++++++++++++++ preOrden +++++++++++++++++++++++++++++++++ 
- Visita al padre
– Preorden hijo izquierdo
– Preorden hijo derecho 

void preOrden(ABB arbol)
{
if (arbol==NULL)
	return;

cout<<arbol->prod_code<<" ";
preOrden(arbol->izq);
preOrden(arbol->der);
}

 +++++++++++++++++++++++++++++++ postOrden +++++++++++++++++++++++++++++++++ 
– Postorden hijo izquierdo
– Postorden hijo derecho
– Visita al padre 

void postOrden(ABB arbol)
{
if (arbol==NULL)
	return;

postOrden(arbol->izq);
postOrden(arbol->der);
cout<<arbol->prod_code<<" ";
}*/













