#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

string geraString(); 

string mudaPrimeiraLetraparaMaiucula(string nome);


int main() {

    srand(static_cast<unsigned>(time(0)));

  
    string nome1 = geraString();
    string nome2 = geraString();

  
    nome1 = mudaPrimeiraLetraparaMaiucula(nome1);
    nome2 = mudaPrimeiraLetraparaMaiucula(nome2);

  
    if (nome1 < nome2) {
        cout << nome1 << endl << nome2 << endl;
    } else {
        cout << nome2 << endl << nome1 << endl;
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