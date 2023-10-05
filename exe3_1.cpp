# include <iostream>
# include <limits>
# include <cstring>
#include <sstream>

using namespace std;

void pause();
void limpaTela();

bool bissexto(int ano) {
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}

bool dataValida(int dia, int mes, int ano) {
    if (mes < 1 || mes > 12 || ano < 1 || dia < 1) {
        return false;
    }

    int diasNoMes[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (bissexto(ano)) {
        diasNoMes[2] = 29;
    }

    return dia <= diasNoMes[mes];
}

int main(){
    limpaTela();

    string data;
    cout << "Digite uma data no formato dd/mm/aaaa: ";
    getline(cin, data);

    int dia, mes, ano;

    stringstream ss(data);
    char delim;
    ss >> dia >> delim >> mes >> delim >> ano;

    if (!ss || delim != '/' || !dataValida(dia, mes, ano)) {
        cout << "Data inválida!" << endl;
        return 1;
    }

    string meses[] = {
        "janeiro", "fevereiro", "março", "abril",
        "maio", "junho", "julho", "agosto",
        "setembro", "outubro", "novembro", "dezembro"
    };

    cout << "Dia: " << dia << endl;
    cout << "Mês: " << meses[mes - 1] << endl;
    cout << "Ano: " << ano << endl;

    cout << "Data por extenso: " << dia << " de " << meses[mes - 1] << " de " << ano << endl;

   

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