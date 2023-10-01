#include <iostream>
#include <string>
#include <sstream>
using namespace std;

bool valida_data(int, int, int);
void imprimir_data_por_extenso(int, int, int);

int main(){

    string data;
    cout<<"Digite uma data no formato (dd/mm/aaaa): ";
    cin>>data;

    int dia, mes, ano;
    istringstream ss(data);

    char delimiter;
    ss>>dia>>delimiter>>mes>>delimiter>>ano;
    
    if(!valida_data(dia, mes, ano)){
        cout<<"Esta data eh invalida!"<<endl;
    } else {
        if(ss){
            cout<<"Dia: "<<dia<<endl;
            cout<<"Mes: "<<mes<<endl;
            cout<<"Ano: "<<ano<<endl;
        }

        cout<<"Data por extenso: ";
        imprimir_data_por_extenso(dia, mes, ano);
    }

    return 0;
}

bool valida_data(int dia, int mes, int ano){
    if(mes < 1 || mes > 12)
        return false;
    if(mes == 2){
        if(ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)){
            if(dia < 1 || dia > 29)
                return false;
        } else if(dia < 1 || dia > 28) {
            return false;
        }
    } else if (mes == 1 || mes == 3 || mes == 5 || 
                mes == 7 || mes == 8 || mes == 10 || mes == 12){
        if(dia < 1 || dia > 31)
            return false;
    } else {
        if(dia < 1 || dia > 30)
            return false;
    }

    return true;
}

void imprimir_data_por_extenso(int dia, int mes, int ano){
    string meses[] = {"janeiro", "fevereiro", "marco", "abril", "maio", "junho",
                        "julho", "agosto", "setembro", "outubro", "novembro", "dezembro"};

    cout<<dia<<" de "<<meses[mes - 1]<<" de "<<ano<<endl;
}