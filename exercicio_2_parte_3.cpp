#include <iostream>
#include <iomanip>
using namespace std;

int main(){

    float notas1[15], notas2[15], medias[15];

    srand(time(NULL));

    for(int i = 0; i < 15; i++){
        notas1[i] = ((float) rand()/RAND_MAX) * 10;
        notas2[i] = ((float) rand()/RAND_MAX) * 10;
        medias[i] = (notas1[i] + notas2[i]) / 2;

        cout<<"Aluno "<<i+1<<": ";
        if(notas1[i] > notas2[i]) cout<<"Piorou\t";
        else if(notas1[i] < notas2[i]) cout<<"Melhorou\t";
        else cout<<"Manteve a nota\t";

        cout<<"Media = "<<fixed<<setprecision(2)<<medias[i]<<endl;
    }

    return 0;
}