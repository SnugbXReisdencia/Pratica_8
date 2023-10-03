#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    system("clear");
    srand(static_cast<unsigned>(time(0)));
    double estacao[250], maxima = -100.0, minima = 100.0, media = 0.0;

   
    for (int i = 0; i < 250; i++) {
        estacao[i] = 10.0 + 30.0 * (rand() % 100) / 1000.0;
       
        if (estacao[i] > maxima) {
            maxima = estacao[i];
        }
        if (estacao[i] < minima) {
            minima = estacao[i];
        }
      
        media += estacao[i];
    }

   
    media = media / 250;

    cout << "A temperatura maxima: " << maxima << " graus" << endl;
    cout << "A temperatura minima: " << minima << " graus" << endl;
    cout << "A temperatura media: " << media << " graus" << endl << endl;

  
    for (int i = 0; i < 250; i++) {
        if (estacao[i] > media) {
            estacao[i] += 1.0;
        } else {
            estacao[i] -= 2.0;
        }
    }


    cout << "Atualizacao das temperaturas :" << endl;
    for (int i = 0; i < 250; i++) {
        cout << estacao[i] << " ";
    }
    cout << endl;

    return 0;
}
