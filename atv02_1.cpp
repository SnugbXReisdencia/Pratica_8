#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    system("clear");
    srand(static_cast<unsigned>(time(0)));
    int vet[100], rep[20] = {0}, num[20], maisRepete = 0;

    for (int i = 0; i < 100; i++) {
        vet[i] = rand() % 20 + 1; // gerar entre 1 e 20
        rep[vet[i] - 1]++;
    }

    for (int i = 0; i < 100; i++) {
        cout << vet[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 20; i++) {
        int ContRep = 0; 
        for (int j = 0; j < 100; j++) {
            if (vet[j] == i + 1) {  //comparar com i,  1 a 20
                ContRep++;
            }
        }
        rep[i] = ContRep;
        num[i] = i + 1; 
    }

    for (int i = 0; i < 20; i++) {
        cout << "O numero " << num[i] << " aparece " << rep[i] << " vezes." << endl;
        if (rep[i] > maisRepete) {
            maisRepete = rep[i];
        }
    }

    cout << "numero que mais  repetem  ";
    for (int i = 0; i < 20; i++) {
        if (rep[i] == maisRepete) {
            cout << num[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
