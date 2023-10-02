#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

int main(){

    srand(time(NULL));

    vector<string> palavras;

    for(int i = 0; i < 10; i++){
        string palavra;
        for(int j = 0; j < 10; j++){
            char caractere = 'a' + rand() % ('z' - 'a');
            palavra.push_back(caractere);
        }
        palavra[0] = toupper(palavra[0]);
        palavras.push_back(palavra);
    }

    sort(palavras.begin(), palavras.end());

    for(string palavra : palavras) cout<<palavra<<endl;

    return 0;
}