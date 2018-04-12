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


bool esPrimo (int n) {
    bool primo = true;
    int i = 2;
    if (n <= 1) {
        return false;
    }
        while (i <= RaizCuadrada(n)) {
            if (n%i == 0) {
                return false;
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
    int aux = 0;
    if (k != -1) {
        while (j % k == 0) {
            j = j / k;
            aux = aux + 1;
        }
        return aux;
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