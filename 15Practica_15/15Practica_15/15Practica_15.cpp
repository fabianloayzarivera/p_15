// 15Practica_15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <locale.h>

using namespace std;

class Shape { 
private:
	float area;
public:
	Shape() {};
};

class Circle : public Shape { 
private :
	float radius;
public:
	Circle() {};
};

class VirtualShape { 
private:
	float area;
public:
	VirtualShape() {};
	virtual ~VirtualShape() {}; 
};

class CircleDerivada : public VirtualShape { 
public:
	CircleDerivada() {};
	virtual ~CircleDerivada() {};
};

class VirtualShape2 { 
private:
	float area;
public:
	VirtualShape2() {	getArea();};
	virtual void getArea() {printf("Calculate Area from VirtualShape");};
};

class CircleDerivada2 : public VirtualShape2 { 
public:
	CircleDerivada2() { getArea();};
	virtual void getArea() {printf("Calculate Area from CircleDerivada2");};
};

int main()
{
	cout << "------>Cuánto espacio ocupa la tabla de funciones virtuales ?" << endl;
	cout << "El objeto guarda un puntero a funcion por cada funcion virtual que contenga" << endl;
	cout << "El espacio se puede calcular multiplicando el sizeof(ptr) * el numero de las funciones virtuales" << endl;
	cout << "Tambien existen herramientas en visual studio que nos permiten analizar un objeto y observar la tabla" << endl;
	cout << "La clase VirtualShape contiene una sola funcion virtual por lo que su tabla virtual solo almacena ese unico puntero" << endl <<endl;

	cout << "------>Dónde está situada la tabla de funciones virtuales ?" << endl;
	cout << "La tabla se encuentra en el OnlyRead de la memoria y no es modificable." << endl<<endl;

	cout << "------>Cuánto espacio ocupa adicionalmente un objeto por tener una tabla de funciones virtuales ?" << endl;

	cout<< "Non virtual object size: "<<endl;
	Shape shape;
	printf("%d\n", sizeof(shape));

	cout << "Virtual object size: " << endl;
	VirtualShape vShape;
	printf("%d\n", sizeof(vShape));

	cout << "El size de un virtual object obtenido por sizeof(ptr) es mayor que el de un objeto no virtual, puesto que contiene la tabla de funciones virtuales, y como fue explicado en la pregunta anterior el espacio que ocupa la misma depende de la cantidad de funciones virtuales que contenga, en este caso 1 funcion" << endl << endl;
	cout << "------>Qué pasa si llamo a un método virtual desde el constructor " << endl;

	VirtualShape2 vShape2;
	cout << "Se ejectua el metodo virtual getArea() de la clase padre y no el de la clase derivada" << endl;
	cout << "No se puede llamar a una funcion virtual en los constructores cuando construimos la clase padre, por que las clases derivadas no han tenido su build aun, lo que significa que la funcion vitual getArea de la clase derivada no sera encontrada" << endl << endl;

	cout << "------>Comparar la llamada a una función virtual con la llamada a una función no virtual.¿Cuántos pasos adicionales tienen que realizarse para llamar a una función cuando esta es virtual ?" << endl;
	cout << "Pasos para llamar a una Funcion Virtual: " << endl;
	cout << "1. Usar el ptr *__vptr apuntando a la vtable para usar la tabla que necesitamos" << endl;
	cout << "2. Localizamos la funcion que necesitamos y la llamamos" << endl;
	cout << "3. Llamamos a la funcion" << endl << endl;

	cout << "Pasos para llamar a un Funcion NO Virtual: " << endl;
	cout << "1. Simplemente invocamos la funcion desde el objeto" << endl<<endl;
	
	cout << "Pasos para llamar a una funcion NO virtual a traves de un puntero" << endl;
	cout << "1. Obtener la funcion que es apuntada por el puntero" << endl;
	cout << "2. LLamamos a esta funcion" << endl << endl;

	
	cout << "Como conclusion, podermos ver que como minimo, si estamos usando funciones virtuales, tendremos un nivel mas de indireccion" << endl;

	getchar();
    return 0;
}

