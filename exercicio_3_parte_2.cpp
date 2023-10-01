#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

int main(){

    string palavra1, palavra2;

    srand(time(NULL));

    for(int i = 0; i < 10; i ++){
        char caractere1 = 'a' + rand() % ('z' - 'a');
        char caractere2 = 'a' + rand() % ('z' - 'a');
        palavra1.push_back(caractere1);
        palavra2.push_back(caractere2);
    }

    palavra1[0] = toupper(palavra1[0]);
    palavra2[0] = toupper(palavra2[0]);

    vector<string> strings = {palavra1, palavra2};

    sort(strings.begin(), strings.end());

    cout<<"Strings em ordem alfabetica:"<<endl;
    for(string str : strings){
        cout<<str<<endl;
    }

    return 0;
}