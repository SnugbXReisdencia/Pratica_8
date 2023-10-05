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

    int numEstacoes = 250;
    float temperaturas[numEstacoes];
    float temperaturaMaxima = -1000.0;
    float temperaturaMinima = 1000.0;
    float temperaturaMedia = 0.0;

    srand(time(0));

    for (int i = 0; i < numEstacoes; i++) {
        temperaturas[i] = 10.0 + (40.0 - 10.0) * (rand() / static_cast<float>(RAND_MAX));
        
        if (temperaturas[i] > temperaturaMaxima) {
            temperaturaMaxima = temperaturas[i];
        }
        if (temperaturas[i] < temperaturaMinima) {
            temperaturaMinima = temperaturas[i];
        }
        
        temperaturaMedia += temperaturas[i];

        cout << "Estação " << i + 1 << ": " << temperaturas[i] << " graus" << endl;

    }
    
    cout << endl;

    temperaturaMedia /= numEstacoes;

    for (int i = 0; i < numEstacoes; i++) {
        if (temperaturas[i] > temperaturaMedia) {
            temperaturas[i] += 1.0;
        } else {
            temperaturas[i] -= 2.0;
        }
    }

    cout << "Temperatura Máxima: " << temperaturaMaxima << " graus" << endl;
    cout << "Temperatura Mínima: " << temperaturaMinima << " graus" << endl;
    cout << "Temperatura Média: " << temperaturaMedia << " graus" << endl;

   

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