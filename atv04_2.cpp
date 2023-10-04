#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string geraString(); 

string mudaPrimeiraLetraparaMaiucula(string nome);


int main() {

    srand(static_cast<unsigned>(time(0)));

  
    string nome1[10];
    string nome2[10];

  
    for (int i = 0; i < 10; i++) {
        nome1[i] = geraString();
        nome2[i] = geraString();
    }

  for( int i = 0; i < 10; i++){
    nome1[i] = mudaPrimeiraLetraparaMaiucula(nome1[i]);
    nome2[i] = mudaPrimeiraLetraparaMaiucula(nome2[i]);
  }
   
    for( int i = 0; i < 10; i++){
        if(nome1[i] > nome2[i]){
            cout << nome1[i] << " " << nome2[i] << endl;
        }
        else if (nome1[i] < nome2[i]){
            cout << nome2[i] << " " << nome1[i] << endl;
        }
      
    }
   
    return 0;
}

string geraString()
{
    string aleatorio;
    for (int i = 0; i < 10; i++) {
        char letra = 'a' + rand() % ('z' - 'a' + 1);
        aleatorio.push_back(letra);
    }
    return aleatorio;
}
string mudaPrimeiraLetraparaMaiucula(string nome)
 {
    if (!nome.empty()) {
        nome[0] = toupper(nome[0]);
    }
    return nome;
}