#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    int n;
    string ganhador;
    map<string, int> vencedor;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> ganhador;
        vencedor[ganhador]++;
    }
    int maior = (*vencedor.begin()).second;
    ganhador = (*vencedor.begin()).first;
    for (map<string, int>::iterator itupper = vencedor.begin(); itupper != vencedor.end(); ++itupper) {
      if (maior < (*itupper).second){
        maior = (*itupper).second;
        ganhador = (*itupper).first;
      }
    }
    cout << ganhador << endl;
}
