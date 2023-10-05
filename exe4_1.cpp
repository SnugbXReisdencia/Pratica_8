# include <iostream>
# include <limits>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <vector>

using namespace std;

void pause();
void limpaTela();

void imprimirImagem(vector<vector<int>> imagem) {
    for (vector<int> linha : imagem) {
        for (int pixel : linha) {
            cout << pixel << " ";
        }
        cout << endl;
    }
}

vector<int> construirHistograma(vector<vector<int>> imagem) {
    vector<int> histograma(256, 0);

    for (vector<int> linha : imagem) {
        for (int pixel : linha) {
            histograma[pixel]++;
        }
    }

    return histograma;
}

int main(){
    limpaTela();

    srand(time(0));

    vector<vector<int>> imagem(480, vector<int>(640));
    vector<int> histograma(256, 0);

    for (size_t i = 0; i < imagem.size(); i++) {
        for (size_t j = 0; j < imagem[0].size(); j++) {
            imagem[i][j] = rand() % 256;
        }
    }

    imprimirImagem(imagem);

    cout << endl;

    histograma = construirHistograma(imagem);

    // Imprime o histograma
    for (int i = 0; i < 256; i++) {
        cout << "Intensidade " << i << ": " << histograma[i] << " pixels" << endl;
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