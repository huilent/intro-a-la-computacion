#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;



int RaizCuadrada (int n) {
    int i=1;
        while (i*i <= n) {
            i=i+1;
        }
    return (i-1);
}

/*
Introducimos la función raiz cuadrada ya que hace un poco más eficiente la búsqueda de números primos:
 si un número no tiene divisores primos menores o iguales a su raíz cuadrada,
 entonces no tendrá ningún otro divisor primo (distinto de sí mismo).
 */

bool esPrimo (int n) {
    bool primo = true;
    int i = 2;
    if (n <= 1) {
        primo = false;
    }
        while (i <= RaizCuadrada(n)) {
            if (n%i == 0) {
                primo = false;
            }
            i=i+1;
        }
    return primo;
}

int cantidadPrimosMenoresOIguales (int n) {
    int i = 2;
    int cantidad = 0;
    while (i <= n) {
        if (esPrimo(i)) {
            cantidad = cantidad+1;
        }
        i=i+1;
    }
    return cantidad;
}

int cantidadDivisoresPrimos (int n) {
    int i = 2;
    int cantidad = 0;
    while (i <= n) {
        if ( esPrimo(i) && n%i==0 ) {
            cantidad = cantidad+1;
        }
        i=i+1;
    }
    return cantidad;
}

/*
 El caso en el que n es primo, y por lo tanto tiene un único divisor primo,
 no lo estamos considerando aparte, ya que durante el 'if' se vuelve a verificar si n es primo,
 en caso afirmativo, la 'cantidad' quedará igual a 1.
 */

int iesimoDivisorPrimo (int n, int i) {
    if (cantidadDivisoresPrimos(n) >= i) {
        int cantidad = 0;
        int j = 2;
        while (cantidad < i) {
                if (esPrimo(j) && n%j==0) {
                    cantidad = cantidad+1;
                }
            j=j+1;
        }
        return (j-1);
    }
    else
        return -1;
}

int potenciaIesimoDivisorPrimo (int n, int i) {
    int k = iesimoDivisorPrimo(n, i);
    int j = n;
    int potencia = 0;
    if (k != -1) {
        while (j % k == 0) {
            j = j / k;
            potencia = potencia + 1;
        }
        return potencia;
    }
    else
        return -1;
}

int main (int cantidad, char** parametros) {
    string f = parametros[1];
    int n = atoi(parametros[2]);
    int i;
    if (f == "esPrimo") {
        if(esPrimo(n)) {
            cout << "si" << endl;
        }
        else {
            cout << "no" << endl;
        }
    }
    if (f == "cantidadPrimosMenoresOIguales") {
        cout << cantidadPrimosMenoresOIguales(n) << endl;
    }
    if (f == "cantidadDivisoresPrimos") {
        cout << cantidadDivisoresPrimos(n) << endl;
    }
    if (f == "iesimoDivisorPrimo") {
        i = atoi(parametros[3]);
        int aux = iesimoDivisorPrimo(n, i);
        if (aux != -1) {
            cout << aux << endl;
        }
        else {
            cout << n << " no tiene " << i << " divisores primos" << endl;
        }
    }
    if (f == "potenciaIesimoDivisorPrimo") {
        i = atoi(parametros[3]);
        int aux = potenciaIesimoDivisorPrimo(n, i);
        if (aux != -1) {
            cout << aux << endl;
        }
        else {
            cout << n << " no tiene " << i << " divisores primos" << endl;
        }
    }
    return 0;
}