#include <cstdlib>
#include <iostream>
#include <ctime>

int numero_aleatorio();
void repeti_numero(int vetor[], int vetor2[]);
using namespace std;

int main(){
    int valor_digitado[100];
    int valor_[20];
 
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i <100;i++){
        valor_digitado[i] = numero_aleatorio();
        cout << "aleatorio: " <<valor_digitado[i]  <<endl;
    }
    
    repeti_numero(valor_digitado, valor_);

    return 0;
}
int numero_aleatorio(){
    int valor =0;
    valor = rand()%20 +1;
 
    return valor;
}

void repeti_numero(int vetor[], int vetor2[]){
    cout <<"-----------------------------" <<endl;
    int count = 0;
    int maior = 0;
    int valor = 0;
    for (int i = 1; i <=20; i++){
        for (int j = 0; j <100; j++){
            if(vetor[j] == i){
                count ++;
            }
        }
        vetor2[i-1] = count;
        cout << "O numero "<< i << " : " <<vetor2[i-1] <<endl;
        count=0;
    }

    maior = vetor2[0];
    for (int i = 0; i <=19; i++){       
        if(vetor2[i] > maior){
            maior = vetor2[i];
            valor = i+1;
        }

    }
    cout << "O numero que aparece e : "<< valor  << 
    "\nNo total de : "<< maior <<endl;
}
