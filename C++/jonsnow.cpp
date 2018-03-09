#include <iostream>
#include <vector>
using namespace std;
int main(){
    int h, c;
    int o, d;
    int n =0;
    int maior = 1;
    while (cin >> h >> c && h!=0){
    vector <int> casas (h+1); 
        
    for (int i =0; i<c; i++){
            cin >> o >> d;
            casas[o]++;
            casas[d]++;
        }
        
        for (int i = 0; i<casas.size(); i++){
            if(casas[maior] <= casas[i]) {
                maior = i;
            }            
        }
         
        cout << "Teste " << ++n << endl;
         for(int i =0; i<casas.size(); i++){
             if(casas[maior] == casas[i]){
                 cout << i << " " ;
             }
         }
         cout << endl;
         maior = 1; 
         }
}
