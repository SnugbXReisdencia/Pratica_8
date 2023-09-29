#include <iostream>
#include <cstdlib>
#include <ctime>

float numero_aleatorio();
float temp_maior(float vetor[]);
float temp_menor(float vetor[]);
using namespace std;

int main() {
    float valor_digitado[250];
    float maior_ , menor_;
    // Inicializa a semente para a geração de números aleatórios
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < 250; i++) {
        valor_digitado[i] = numero_aleatorio();
    }

    maior_ = temp_maior(valor_digitado);
    menor_ = temp_menor(valor_digitado);
    cout <<"-----------------------------" <<
    "\nMaior temperatuda : "<< maior_ << 
    "\n-----------------------------" <<
    "\nMenor temperatura : "<< menor_<<endl;

    return 0;
}


float numero_aleatorio() {
    float valor_random = 1 + 30.0 *(rand() %100) / 3000.0; 
    cout << "Numero aleatorio: " << valor_random << endl;
    return valor_random;
}

float temp_maior(float vetor[]){

    float maior = 0;
    maior = vetor[0];
    for (int i = 0; i <=249; i++){       
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }
    return maior;

}

float temp_menor(float vetor[]){

    float menor = 0;
    menor = vetor[0];
    for (int i = 0; i <=249; i++){       
        if(vetor[i] < menor){
            menor = vetor[i];
        }
    }

    return menor;
    
}