#include <iostream>
#include <sstream>
#include <string>

bool ehDataValida(int dia, int mes, int ano) {
    if (ano < 0 || mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        return false;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return false;
    }

    if (mes == 2) {
        if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0)) {
            if (dia > 29) {
                return false;
            }
        } else {
            if (dia > 28) {
                return false;
            }
        }
    }

    return true;
}

std::string obterMesPorExtenso(int mes) {
    static const char *meses[] = {
        "Janeiro", "Fevereiro", "Março", "Abril",
        "Maio", "Junho", "Julho", "Agosto",
        "Setembro", "Outubro", "Novembro", "Dezembro"
    };

    return meses[mes - 1];
}

int main() {
    std::string data;
    std::cout << "Digite uma data no formato dd/mm/aaaa: ";
    std::cin >> data;

    int dia, mes, ano;
    char barra1, barra2;
    std::istringstream ss(data);
    ss >> dia >> barra1 >> mes >> barra2 >> ano;

    if (ss && barra1 == '/' && barra2 == '/' && ehDataValida(dia, mes, ano)) {
        std::cout << "Dia: " << dia << std::endl;
        std::cout << "Mês: " << mes << std::endl;
        std::cout << "Ano: " << ano << std::endl;

        std::cout << dia << " de " << obterMesPorExtenso(mes) << " de " << ano << std::endl;
    } else {
        std::cout << "Data inválida!" << std::endl;
    }

    return 0;
}
