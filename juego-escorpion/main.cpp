#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>

using namespace std;

bool sin_digitos_repetidos(array<int,4> a) {
    int i = 0;
    int j = 1;
    bool result = true;
    while (i<4 && result){
        while (j<4 && result){
            if (a[i] == a[j]){
                result = false;
            }
            j = j+1;
        }
        i=i+1;
        j=i+1;
    }
    return result;
}



array<int,4> generar() {
    array<int, 4> azar = {0, 0, 0, 0};
    int i = 0;
    int seed = time(NULL);
    srand(seed);
    while (i < 4) {
        azar[i] = rand() % 10;
        i = i + 1;
    }
    return azar;
}

array<int,4> generar_sin_repetir (){
    array<int,4> Sin_repe = {0, 0, 0, 0};
    bool Sin = false;
        while (!(Sin && Sin_repe[0]!=0)) {
            Sin_repe = generar();
            Sin = sin_digitos_repetidos(Sin_repe);
        }
    return Sin_repe;
}

array<int,4> pedir() {
    array<int, 4> propuesto = {0, 0, 0, 0};
    int i = 0;
    bool Sin_repe = false;
    while (!Sin_repe) {
        while (i < 4) {
            cout << "Ingrese el " << i+1 << "º dígito" << endl;
            cin >> propuesto[i];
            i = i + 1;
        }
        if (sin_digitos_repetidos(propuesto)) { Sin_repe = true; }
        else {
            cout << "Dígitos repetidos. Tendrá que ingresarlos de nuevo" << endl;
        }
        i = 0;
    }
    return propuesto;
}

int main(){
    int i = 0;
    array<int,4> a = pedir();
    while (i < 4) {
        cout << a[i];
        i = i+1;
    }
    return 0;
}