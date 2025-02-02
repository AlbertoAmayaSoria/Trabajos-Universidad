#include <iostream>
#include "Vector.hpp"

using namespace std;

int main()
{
    //Constructor de copias se llama al recibir un objeto como valor de argumento, cunado una funcion devuelve un objeto, y cuando se inicializa un objeto tambien: funcion(clase objeto)/ clase funcion(){clase objeto...return objeto;}/clase unObjeto=otroObjeto || unObjeto(otroObjeto)
    //Todos los metodos estaticos solamente tienen acceso a miembros estaticos, ya sean otros metodos o datos de la clase. son atributos de clase no atributos de objeto. todo metodo no estatico de una clase tiene acceso a un puntero de autoreferencia a la instancia que lo llame, se llama this.
    //los constructores son los unicos que aceptan iniciallizadores.
    //una pila es una coleccion de datos apilados
//   Vector a, b(3), c(5,3.2);
//
//   a.Imprimir();
//
//   cout << endl;
//
//   b.Imprimir();
//
//   cout << endl;
//
//
//   c.Imprimir();
//
//   cout << endl;
//
//
//   cout << "\nCapturando un vector" << endl;
//   a.Capturar();
//
//   cout << endl;
//
//   a.Imprimir();
   //*****************************************************************************************
   int n, p;
   double esc, norma;


   cout << "Programa que realiza operaciones con uno o dos vectores" << endl;
   do{
    cout << "Dimensi\242n: ";
    cin >> n;
   }while(n < 1 );
   cout << "Introducir escalar: ";
   cin >> esc;
   Vector v(n), w(n), z(n);



   cout << "\n\nCapturando el primer vector" << endl;
   cin >> v;

   cout << "\n\nCapturando el segundo vector" << endl;
   cin >> w;

   z = v + w;

   cout << "\n\nSuma:\n";

   //v.Imprimir();
   cout << v << " + " << w << " = " << z;
//*****************************************************************************************
   z = v - w;

   cout << "\n\nResta:\n";

   cout << v << " - " << w << " = " << z;
//*****************************************************************************************
   p = v * w;

   cout << "\n\nProducto Punto:\n";


   cout << v << " * " << w << " = " << p;

//*****************************************************************************************
   z = esc * v;

   cout << "\n\nProducto por Escalar:\n";



   cout << v << " * " << esc << " = " << z;

//*****************************************************************************************
   norma = v.Norma(v);

   cout << "\n\nNorma:\n";

   cout << "|" << v << "| = " << norma << endl;






    return 0;
}
