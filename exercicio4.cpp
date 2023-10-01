#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main() {
    srand(time(0));


    const int largura = 640;
    const int altura = 480;


    int imagem[altura][largura];

    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            imagem[i][j] = rand() % 256;
        }
    }

    vector<int> histograma(256, 0);


    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            histograma[imagem[i][j]]++;
        }
    }

    cout << "Histograma da Imagem:" << endl;
    for (int i = 0; i < 256; ++i) {
        cout << i << ": " << histograma[i] << endl;
    }

    return 0;
}
