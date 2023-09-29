#include <iostream>
#include <cstdlib>
#include <ctime>

float numero_aleatorio();
float temp_maior(float vetor[], int tam);
float temp_menor(float vetor[], int tam);
float media_temp(float vetor[], int tam);
float* atualiza_temp(float vetor[], int tam, float media);
using namespace std;

int main() {
    float valor_digitado[10];
    int tamanho_vetor = sizeof(valor_digitado) / sizeof(valor_digitado[0]);
    float maior_ , menor_, media_;
    float * vetor_atuazado; 
    // Inicializa a semente para a geração de números aleatórios
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < tamanho_vetor; i++) {
        valor_digitado[i] = numero_aleatorio();
    }

    maior_ = temp_maior(valor_digitado, tamanho_vetor);
    menor_ = temp_menor(valor_digitado, tamanho_vetor);
    media_ = media_temp(valor_digitado, tamanho_vetor);
    cout <<"-----------------------------" <<
    "\nMaior temperatuda : "<< maior_ << 
    "\n-----------------------------" <<
    "\nMenor temperatura : "<< menor_<<
    "\n-----------------------------" <<
    "\nMedia : "<< media_ <<  endl;


    vetor_atuazado = atualiza_temp(valor_digitado, tamanho_vetor, media_);

    for (int i = 0; i < tamanho_vetor; i++) {
        cout << "temperatura atualizada: " <<vetor_atuazado[i] << endl;
    }

    // Não se esqueça de liberar a memória alocada
    delete[] vetor_atuazado;

    return 0;
}


float numero_aleatorio() {
    float valor_random = 1 + 30.0 *(rand() %100) / 3000.0; 
    cout << "temperatura: " << valor_random << endl;
    return valor_random;
}

float temp_maior(float vetor[],int tam){

    float maior = 0;
    maior = vetor[0];
    for (int i = 0; i <tam; i++){       
        if(vetor[i] > maior){
            maior = vetor[i];
        }
    }
    return maior;
}

float temp_menor(float vetor[], int tam){

    float menor = 0;
    menor = vetor[0];
    for (int i = 0; i <tam; i++){       
        if(vetor[i] < menor){
            menor = vetor[i];
        }
    }
    return menor; 
}

float media_temp(float vetor[], int tam){
    float soma = 0;
    float media_cal = 0;
    for (int i = 0; i <tam; i++){       
        soma += vetor[i];
    }
    media_cal = soma / tam;

    return media_cal;

}    


float* atualiza_temp(float vetor[], int tam, float media){

    for (int i = 0; i <tam; i++){       
        if(vetor[i] > media ){
            vetor[i]++;
        }else if(vetor[i] < media ){
            vetor[i] --;
            vetor[i] --;
        }
    }
    return vetor;

}  
