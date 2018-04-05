#include <iostream>

using namespace std;

bool esPrimo(int n) {
    int i = 2;
    while (n > i && n % i != 0) {
        i = i + 1;
    }
    return n == i;
}

int main() {
    int resultado = esPrimo(1);
    if (resultado) {
        cout << "Es primo";
    } else {
        cout << "No es primo";
    }
    return 0;
}