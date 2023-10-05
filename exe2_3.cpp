# include <iostream>
# include <limits>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <iomanip>

using namespace std;

void pause();
void limpaTela();

int main(){
    limpaTela();

    srand(time(0));

    int numAlunos = 15;
    float notas1[numAlunos];
    float notas2[numAlunos];
    float medias[numAlunos];

    for (int i = 0; i < numAlunos; i++) {
        notas1[i] = ((float)rand() / RAND_MAX) * 10;
        notas2[i] = ((float)rand() / RAND_MAX) * 10;

        medias[i] = (notas1[i] + notas2[i]) / 2;

        if (notas2[i] > notas1[i]) {
            cout << "Aluno " << i + 1 << ": Melhorou" << endl;
        } else if (notas2[i] < notas1[i]) {
            cout << "Aluno " << i + 1 << ": Piorou" << endl;
        } else {
            cout << "Aluno " << i + 1 << ": Manteve a nota" << endl;
        }
    }

    cout << "\nMédias dos alunos:\n";
    for (int i = 0; i < numAlunos; i++) {
        cout << "Aluno " << i + 1 << ": " << fixed << setprecision(1) << medias[i] << endl;
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