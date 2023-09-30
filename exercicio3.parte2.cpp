#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

string gerarStringAleatoria(int tamanho) {
    string resultado;
    for (int i = 0; i < tamanho; ++i) {
        char caractere = 'a' + rand() % ('z' - 'a' + 1);
        resultado.push_back(caractere);
    }
    sort(resultado.begin(), resultado.end());

    return resultado;
}

string primeiraLetraMaiuscula(const string& str) {
    srand(static_cast<unsigned>(time(0)));
    string resultado = str;
    if (!resultado.empty()) {
        resultado[0] = toupper(resultado[0]);
    }
    return resultado;
}

int main() {
    string string1 = gerarStringAleatoria(10);

    string1 = primeiraLetraMaiuscula(string1);

    cout << "Strings em ordem alfabetica: " << string1 <<  endl;

    return 0;
}
