#include <iostream>
#include <vector>
using namespace std;

/*int main() {
    int i=1;
    int suma=0;
    while(i < 1000) {
        if( i%3 == 0 || i%5 == 0) {
            suma = suma + i;
        }
        i=i+1;
    }

        cout << suma << endl;

    return 0;
}



int main() {
    int c = 1;
    int d = 0;
    int suma = 0;
        while(c <= 4000000) {
            if(c%2 == 0) {
                suma = suma + c;
                cout << c << endl;
            }
            c=c+d;
            d=c-d;
        }
    cout << suma << endl;
    return 0;
}

*/

bool pico (vector <int> n) {
    bool pico = true;
    int i=0;
        while(i <= n.size()) {
            if (n[i] <= n[i + 1] || n[i] >= n[i + 1]) {
                pico = true;
            }
            else if
            i=i+1;
        }

}

int main() {

}
