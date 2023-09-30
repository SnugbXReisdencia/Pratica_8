#include <iostream>
#include <vector>
using namespace std;

int main(){
    int vetor[100], valores[20] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //Geração de valores aleatórios entre 1 e 20 e contagem
    for(int i = 0; i < 100; i++){
        vetor[i] = 1 + rand() % 20;
        valores[vetor[i] - 1]++;
    }

    int mais = valores[0], menos = valores[0];
    vector<int> maiores, menores;
    for(int i = 0; i < 20; i++){
        cout<<"Valor "<<i + 1<<" aparece "<<valores[i]<<" vezes"<<endl;
        if(valores[i] > mais) mais = valores[i];
        if(valores[i] < menos) menos = valores[i];
    }

    for(int i = 0; i < 20; i++){
        if(valores[i] == mais) maiores.push_back(i + 1);
        if(valores[i] == menos) menores.push_back(i + 1);
    }

    cout<<"Valor(es) que mais aparece(m): ";
    for(int valor : maiores) cout<<valor<<" ";
    cout<<endl;
    cout<<"Valor(es) que menos aparece(m): ";
    for(int valor : menores) cout<<valor<<" ";
    cout<<endl;

    return 0;
}