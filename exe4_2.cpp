# include <iostream>
# include <limits>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <algorithm>


using namespace std;

void pause();
void limpaTela();

string gerarStringAleatoria() {
    string resultado;
    for (int i = 0; i < 10; i++) {
        char caractere = 'a' + rand() % ('z' - 'a' + 1);
        resultado += caractere;
    }
    return resultado;
}

int main(){
    limpaTela();

    srand(time(0));
    int tam = 100;
    string strs[tam];

    for (int i = 0; i < tam; i++) {
        strs[i] = gerarStringAleatoria();
    }

    for (int i = 0; i < tam; i++) {
        strs[i][0] = toupper(strs[i][0]);
    }

    sort(strs, strs + tam);

    cout << "String gerada: \n\n";
    for (int i = 0; i < tam; i++) {
        cout << strs[i] << endl;
    }

    pause();
    return 0;
}

void pause()
{
    // cin.ignore();
    cout << "\nPressione a tecla Enter para continuar...\n";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void limpaTela()
{
    cin.clear();

    // Verifica se a variável de ambiente WINDIR está definida (ambiente Windows)
    const char *windir = getenv("WINDIR");

    if (windir != nullptr && strlen(windir) > 0)
    {
        // Se estiver definida, estamos no Windows, então use "cls"
        system("cls");
    }
    else
    {
        // Caso contrário, estamos em um ambiente Unix/Linux, use "clear"
        system("clear");
    }
}