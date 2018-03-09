#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct carro{
    int id;
    int tempo;
};
bool comp(carro i, carro j){
    if(i.tempo<j.tempo)
        return true;
    return false; 
}
int main(){
    int c, v, t; 
  carro corredor;
    cin >> c >> v; 
    vector <carro> ganhadores; 
    
    for(int i =0; i< c; i++){
        int r = i +1;
        corredor.id=r;
        corredor.tempo =0;
        for(int y=0; y<v; y++){
            cin>>t;
            corredor.tempo+=t;  
        }
        ganhadores.push_back(corredor); 
    }
    sort(ganhadores.begin(), ganhadores.end(), comp);
    
    for (int i=0; i<3; i++)
        cout << ganhadores[i].id << endl;
}
