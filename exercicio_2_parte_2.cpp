#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    double estacoes[250], soma = 0.0;
    
    srand(time(NULL));

    for(int i = 0; i < 250; i++){
        estacoes[i] = 10 + 30.0 * (rand() % 100) / 3000.0;
        soma += estacoes[i];
    }

    double media = soma / 250;
    double maxima = estacoes[0], minima = estacoes[0];

    cout<<"Temperatura media = "<<fixed<<setprecision(2)<<media<<endl;
    for(int i = 0; i < 250; i++){
        cout<<"Temperatura "<<i + 1<<": "<<estacoes[i]<<endl;
        if(estacoes[i] > maxima) maxima = estacoes[i];
        else if(estacoes[i] < minima) minima = estacoes[i];
    }

    cout<<endl;
    //APÓS APLICAÇÃO DO MODELO
    cout<<"============================================================"<<endl;
    cout<<"Temperaturas apos a aplicacao do modelo:"<<endl;
    for(int i = 0; i < 250; i++){
        if(estacoes[i] > media) estacoes[i]++;
        else if(estacoes[i] < media) estacoes[i] -= 2;

        cout<<"Nova temperatura "<<i + 1<<": "<<estacoes[i]<<endl;
    }

    return 0;
}