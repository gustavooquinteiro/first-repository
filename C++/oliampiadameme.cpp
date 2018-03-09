#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
struct pais{
        string nome;
        int pontuacao; 
};
    
bool comp(pais i, pais j){
    if(i.pontuacao > j.pontuacao || (i.pontuacao == j.pontuacao && i.nome < j.nome)){
        return true;
    }else{
        return false;
    }
}
int main(){
    int n; 
    int cont =0;
    while(cin >> n && n!=0){
    pais p; 
    string nome;
    vector<pais> participantes(n); 
        for (int i =0; i< n; i++){
        cin >> nome; 
        cin.ignore();
        int ponto, maior =0, menor = 1001, pontuacao=0;
        for (int i =0; i<12;i++){
            cin>>ponto;
            if(maior<ponto) maior = ponto; 
            if(menor> ponto) menor =ponto; 
            pontuacao+=ponto; 
            }
        p.nome = nome;
        p.pontuacao = pontuacao -  maior - menor;
        participantes[i] = p; 
        }
    
       sort(participantes.begin(), participantes.end(), comp);
       int anterior = 1001, classificacao =1;
       cout<<"Teste " << ++cont << endl;
        for (int i =0; i<participantes.size();i++){
            if(participantes[i].pontuacao != anterior)
                classificacao = i+1;
            cout << classificacao << " " << participantes[i].pontuacao << " " << participantes[i].nome<< endl;
            anterior = participantes[i].pontuacao; 
        }
        cout << endl; 

}
}
