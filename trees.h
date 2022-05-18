#ifndef TREES_H
#define TREES_H

struct nodoProducto
{
double codigo;
char descripcion[100];
float precio;
int stock;
nodoProducto* siguiente;
};
typedef nodoProducto* Producto;

struct nodoArbol
{
double prod_code;
nodoProducto* producto;
nodoArbol* izq;
nodoArbol* der;
};
typedef nodoArbol* ABB;

void menu();
void Delete(ABB &,Producto &,double);
void MostrarP(ABB,int);
void insertar (ABB &, ABB);
void inOrden(ABB);

ABB crearNodoABB(double,Producto);
ABB crearNodo(ABB &,Producto &,double,char*,float,int);
ABB Search(ABB,double);
void borrar(ABB &,double);
ABB unirABB(ABB,ABB);

//void preOrden(ABB);
//void postOrden(ABB);


#endif
