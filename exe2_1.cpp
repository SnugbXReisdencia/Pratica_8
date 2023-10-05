# include <iostream>
# include <limits>
# include <cstring>
# include <cstdlib>
# include <ctime>

using namespace std;

void pause();
void limpaTela();

int main(){
    limpaTela();

    srand(time(0));

    int tam = 100;
    int vet[tam];
    int frequencia[20] = {0};
    int numeroMaisFrequente = 0;
    int qtd_Frequencia = 0;

    for (int i = 0; i < tam; i++) {
        vet[i] = 1 + rand() % 20;
        frequencia[vet[i] - 1]++;
    }

    for (int i = 0; i < 20; i++) {
        if (frequencia[i] > qtd_Frequencia) {
            qtd_Frequencia = frequencia[i];
            numeroMaisFrequente = i + 1;
        }
    }

    cout << "Vet gerado:" << endl;
    for (int i = 0; i < tam; i++) {
        if(i == tam - 1){
            cout << vet[i] << " ";
        } else {
            cout << vet[i] << ", ";
        }
    }

    cout << endl;

    cout << "Frequência dos números:" << endl;
    for (int i = 0; i < 20; i++) {
        cout << "Número " << (i + 1) << ": " << frequencia[i] << " vezes" << endl;
    }

    cout << "\nNúmero(s) mais frequente(s): " << numeroMaisFrequente << " (aparece " << qtd_Frequencia << " vezes)" << endl;

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