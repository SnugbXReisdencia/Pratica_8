#include <iostream>
#include <vector>
using namespace std;

int main(){

    int imagem [640][480];
    vector<int> histograma(256, 0);

    srand(time(NULL));

    for(int i = 0; i < 640; i++){
        for(int j = 0; j < 480; j++){
            imagem[i][j] = rand() % 256;
            histograma[imagem[i][j]]++;
        }
    }

    cout<<"HISTOGRAMA"<<endl;
    cout<<"Valor\tPixels"<<endl;
    for(int i = 0; i < 256; i++){
        cout<<i<<"\t"<<histograma[i]<<endl;
    }
    return 0;
}