#include <iostream>
#include <cstdlib>
#include <ctime>

float numero_aleatorio();
void compara_nota(float vetor[],float vetor2[], int tam);
float* media_aluno(float vetor[],float vetor2[],float vetor3[], int tam);


using namespace std;

int main() {
    float nota1[15], nota2[15], medias[15];
    float* media_;
    int tamanho_vetor = sizeof(nota1) / sizeof(nota1[0]);

    srand(static_cast<unsigned>(time(nullptr)));
    for (int i = 0; i < tamanho_vetor; i++) {
        nota1[i] = numero_aleatorio();
        nota2[i] = numero_aleatorio();
        cout <<"-----------------------------" <<
            "\nAluno " << (i + 1) << " Nota 01: " << nota1[i]<< 
            "\nAluno " << (i + 1) << " Nota 02: " << nota2[i] <<endl;
    }

    compara_nota(nota1, nota2, tamanho_vetor);
    media_ = media_aluno(nota1, nota2, medias, tamanho_vetor);

    for (int i = 0; i < tamanho_vetor; i++) {
        cout <<"-----------------------------" <<endl;
        cout << " Aluno " << (i + 1) << ", Media: " << media_[i] <<endl;
    }

    return 0;
}


float numero_aleatorio() {
    float valor_random = ((float)rand()/RAND_MAX)*10; 
    return valor_random;
}

void compara_nota(float vetor[],float vetor2[], int tam){
    for (int i = 0; i < tam; i++) {
        cout <<"-----------------------------" <<endl;
        if(vetor2[i] > vetor[i]){
            cout <<  " Aluno " << (i + 1) << ", Melhorou!!!" <<endl;
        }else if(vetor2[i] < vetor[i]){
            cout << " Aluno " << (i + 1) << ", Piorou!!!" <<endl;
        }else if(vetor2[i] == vetor[i]){
            cout <<  " Aluno " << (i + 1) <<", Manteve a nota" <<endl;
        }
    }
}

float* media_aluno(float vetor[],float vetor2[],float vetor3[], int tam){
    float media = 0;
    for (int i = 0; i < tam; i++) {
        media = (vetor2[i] + vetor[i]) / 2;
        vetor3[i] = media;
    }
    return vetor3;
}