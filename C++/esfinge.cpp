#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
    int n, x, cont =0; 
    string numero; 
    queue <char> fila;
    char numeroAtual;
    string numeroCompleto; 
    cin >> n; 
    for (int i =0; i<n; i++){
        cin >> numero >> x; 
        cout << numero << endl; 
        for (int p =0; p<x;p++){
            for (int u=0; u<numero.size(); u++){
                   fila.push( numero[u] ); 
              }
             cont =0; 
             numeroAtual = fila.front(); 
            while (!fila.empty()){
               if (numeroAtual == fila.front()){ 
                      cont++; 
                }else{
                    string str;
                    str = cont + '0'; 
                  numeroCompleto += str + numeroAtual; 
                    cont =1;
                     numeroAtual = fila.front();
                 }
                fila.pop(); 
             }
             string str;
                    str = cont +'0';
                  numeroCompleto += str + numeroAtual; 
             cout << numeroCompleto << endl; 
             numero = numeroCompleto;
             numeroCompleto = ""; 
    }
             cout << endl;  
    }
}
