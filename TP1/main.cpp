#include <iostream>

using namespace std;

bool esPrimo(int n) {
    int i = 2;
    while (n > i && n % i != 0) {
        i = i + 1;
    }
    return n == i;
}

/*int main() {
    int resultado = esPrimo(1);
    if (resultado) {
        cout << "Es primo";
    } else {
        cout << "No es primo";
    }
    return 0;
}*/
int cantidadPrimosManoresOIguales (int n) {
    int i = 2;
    int j = 0;
    while (i <= n) {
        if (esPrimo(i)){
            j = j+1;
        }
        i = i+1;
    }
    return j;
}

/*int main() {
    int resultado = cantidadPrimosManoresOIguales(11);
    cout << resultado;
    return 0;
}
*/
int cantidadDivisoresPrimos (int n) {
    int i = 0;
    int j = 2;
    if (esPrimo(n)){
        i = 1;
    } else {
        while (j <= n){
            if (esPrimo(j) && n % j == 0) {
                i = i + 1;
            }
        j = j + 1;
        }
    }
    return i;
}

/*int main() {
    int resultado = cantidadDivisoresPrimos(9);
    cout << resultado;
    return 0;
}*/

int iesimoDivisorPrimo (int n, int i) {
    int j = 2;
    int m = 0;
    if (cantidadPrimosManoresOIguales(n) < i) {
        j = 0;
    } else {
        while (m < i) {
            if (esPrimo(j) && n%j == 0){
                m = m+1;
            }
        j = j+1;
        }
    return j-1;
} }

int main() {
        int resultado = iesimoDivisorPrimo(2,1);
        cout << resultado;
        return 0;
}

