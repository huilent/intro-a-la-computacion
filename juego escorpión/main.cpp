#include <iostream>
#include <array>
#include <estalib>
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

int main(){
    array<int,4> a = (1,2,2,4);
    array<int,4> b = (1,2,3,4);
    cout << sin_digitos_repetidos(a)  << "y" << sin_digitos_repetidos(b) << endl;
    return 0;
}
