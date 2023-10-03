#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

int main() {

    srand(static_cast<unsigned>(time(0)));  
    double nota1[15], nota2[15], media[15] ;

    for (int i = 0; i < 15; i++) {
        nota1[i] = ((static_cast<float>(rand()) / RAND_MAX) * 10);
        nota2[i] = ((static_cast<float>(rand()) / RAND_MAX) * 10);
        media[i] = (nota1[i] + nota2[i]) / 2;
    }

    cout << endl;

    for (int i = 0; i < 15; i++) {
     
        if (nota1[i]<nota2[i]){ 
           cout <<"Aluno "<< i+1 << " nota1 " << setprecision(2) << nota1[i] << " nota2 "<< setprecision(2) << nota2[i] << " Melhorou " << " Media " << setprecision(2) << media[i] << endl;
        }
        else if (nota1[i]>nota2[i]){ 
           cout <<"Aluno "<< i+1 << " nota1 " << setprecision(2) << nota1[i] << " nota2 "<< setprecision(2) << nota2[i] << " Piorou"<< " Media " << media[i] <<  endl;
        }
        else if (nota1[i]==nota2[i]){ 
           cout <<"Aluno "<< i+1 << " nota1 " << setprecision(2) << nota1[i] << " nota2 "<< setprecision(2) << nota2[i] << " Melhorou " << " Manteve a nota " << " Media " << media[i] <<  endl;
        }

    }
    
    return 0;
}
