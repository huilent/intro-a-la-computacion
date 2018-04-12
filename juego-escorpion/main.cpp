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

array<int,2> comparar(array<int,4>secreto, array<int,4>propuesto) {
    int i = 0;
    int j = 0;
    array<int,2> aux = {0, 0};
    while(i < 4) {
        if (propuesto[i] == secreto[i]) { aux[0] = aux[0] + 1; }
        else {
            while (j < 4) {
                if (i != j) {
                    if (propuesto[i] == secreto[j]) { aux[1] = aux[1] + 1; }
                }
                j = j + 1;
            }
        }
        i = i + 1;
        j = 0;
    }
    return aux;
}

void jugar(){
    int jugada = 0;
    bool gano = false;
    array<int,4> secreto = generar_sin_repetir();
    array<int,4> propuesto = {0, 0, 0, 0};
    array<int,2> Buenos_Regulares = {0, 0};
    while(jugada < 10 && !gano){
        propuesto = pedir();
        Buenos_Regulares = comparar(secreto, propuesto);
        if(Buenos_Regulares[0] == 4){gano = true;}
        else{
            cout << "Su número propuesto: " << propuesto[0] << propuesto[1] << propuesto[2] << propuesto[3] << endl;
            cout << "Tiene " << Buenos_Regulares[0] << " bueno(s)" << endl;
            cout << "Tiene " << Buenos_Regulares[1] << " regular(es)" << endl;
            cout << "Inténtelo nuevamente." << endl;
        }
        jugada = jugada+1;
    }
    if(gano){
        cout << "¡¡¡GANÓ!!!" << endl;
    }
    else {
        cout << "PERDIÓ :(" << endl;
    }
}

int main() {
    jugar();
    return 0;
}

/*
int main(){
    array<int,4> s = {1, 2, 7, 4};
    array<int,4> p = {1, 3, 2, 4};
    array<int,2> a = {0, 0};
    a = comparar(s,p);
    cout << "Tiene " << a[0] << " bueno(s)" << endl;
    cout << "Tiene " << a[1] << " regular(es)" << endl;
    return 0;
}
 */