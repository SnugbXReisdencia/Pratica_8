#include <iostream>
#include <string>
#include <ctime>
#include <vector>


using namespace std;

string gerarStringAleatoria(int tamanho) {
    string resultado;

    for (int i = 0; i < tamanho; ++i) {
        char caractere = 'a' + rand() % ('z' - 'a' + 1);
        resultado.push_back(caractere);
    }
    return resultado;
}


string addStringLista(vector <string>& lista) {

    string string1;

    for (int i = 0; i < 10; ++i) {
        string1 = gerarStringAleatoria(10);
        lista.push_back(string1);
    }

    for (int i = 0; i < 10; ++i) {
        if (!lista.empty()) {
            lista[i][0] = toupper(lista[i][0]);
        }
        cout << "String: " << lista[i] <<  endl;
    }
}



int main() {
    vector<string> lista_caracter;
    srand(static_cast<unsigned>(time(nullptr)));


    addStringLista(lista_caracter);



    return 0;
}
