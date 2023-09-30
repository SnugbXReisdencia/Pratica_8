#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include <regex>

using namespace std;

struct Data{
    int dia;
    int mes;
    int ano;
};
void pedi_data(Data data, string data_string);

int main(){
    Data data;
    string dta_;

    cout << "Digite a data(dd/mm/yyyy)" << endl;
    cin >> dta_;

    pedi_data(data, dta_);
        

    return 0;
}

void pedi_data(Data data, string data_string){
    string dia, mes, ano;
    string data_ext;

    regex datePattern(R"(\d{1,2}/\d{1,2}/\d{2,4})");

    if(!regex_match(data_string, datePattern)){
        cout << "Formato invalido" << endl;

    }else{

        size_t pos1 = data_string.find("/"); // Encontra a posição da primeira barra
        size_t pos2 = data_string.find("/", pos1 + 1); // Encontra a posição da segunda barra

        if (pos1 != string::npos && pos2 != string::npos) { // Se ambas as barras forem encontradas
            dia = data_string.substr(0, pos1); 
            mes = data_string.substr(pos1 + 1, pos2 - pos1 - 1);
            ano = data_string.substr(pos2 + 1);
        } else {
            cout << "Formato de data inválido." << endl;
        }
        // dia = data_string.substr(0,2);
        // mes = data_string.substr(3,2);
        // ano = data_string.substr(6,10);

        data.dia = atol(dia.c_str());
        data.mes = atoi(mes.c_str());
        data.ano = atoi(ano.c_str());

        if((data.dia >= 1 && data.dia <= 30 ) && (data.mes == 4||data.mes == 6 || data.mes ==9 || data.mes ==7 || data.mes ==11)){

        }
        else if((data.dia >= 1 && data.dia <= 31 ) && (data.mes == 1||data.mes == 3 || data.mes ==5 || data.mes ==7 || data.mes ==8 || data.mes ==10 || data.mes ==12)){

        }
        else if((data.dia >= 1 && data.dia <= 28 ) && (data.mes == 2)){

        }
        else if(data.dia >= 29 && data.mes == 2 && (data.ano % 400 == 0 || data.ano % 4 == 0 && data.ano % 100 !=0)){

        }else{
            cout << "Data invalida" << endl;

        }

        if(data.mes >= 1 && data.mes <= 6){
            data_ext = (data.mes == 1) ? "janeiro" : (data.mes == 2) ? "fevereiro" :(data.mes == 3) ? "marco" :(data.mes == 4) ? "abril":(data.mes == 5) ? "maio" : "Junho";
            cout<< data.dia<< " de "<< data_ext << " de " << data.ano <<endl;

        }else if(data.mes >= 7 && data.mes <= 12){
            data_ext = (data.mes == 7) ? "julho" :(data.mes == 8) ? "agosto" :(data.mes == 9) ? "setembro" :(data.mes == 10) ? "outubro" :(data.mes == 11) ? "novembro" :"Dezembro";
            cout<< data.dia<< " de "<< data_ext << " de " << data.ano <<endl;

        }else{
            cout<< "data.mes invalida" <<endl;

        }
    }
}


// Substitui a substring


