#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

float sumatoria(int cantidad, char** parametro) {
    int i = 2;
    int j = 0;
    int suma = 0;
        while (i < cantidad) {
            j = atoi(parametro[i]);
            suma = suma + j;
            i = i+1;
        }
    return suma;
}

float productoria(int cantidad, char** parametro) {
    int i=2;
    int j=0;
    int producto = 1;
        while (i < cantidad) {
            j = atoi(parametro[i]);
            producto = producto * j;
            i = i+1;
        }
    return producto;
}



int main(int cantidad, char** caracter) {
    string operacion;
    operacion = caracter[1];
    if (operacion == "sumatoria") {
        cout << sumatoria(cantidad, caracter) << endl;
    }
    else if (operacion == "productoria") {
        cout << productoria(cantidad, caracter) << endl;
    }
    return 0;
}


