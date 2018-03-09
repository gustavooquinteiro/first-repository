#include <iostream>
#include <queue>
#include <utility> 
#include <vector>
using namespace std;

typedef struct atendente{
    int id;
    int tempo; 
} atendente;

bool cmp (atendente a, atendente b){
	return (a.tempo > b.tempo || (a.tempo == b.tempo && a.id > b.id));
}

int main(){
    int n, l;
    cin >> n >> l;
    int t;
	priority_queue<atendente, vector<atendente>, bool(*)(atendente, atendente)>atendentes(cmp); 
    vector<int>quant(n+1); 
    atendente s;
    for (int i = 1; i<= n; i++){
        s.id = i;
        s.tempo = 0;
        quant[s.id] = 0;
        atendentes.push(s); 
    }
    for(int i = 0; i < l; i++){
        cin >> t;
        s = atendentes.top();
        atendentes.pop();
        quant[s.id]++; 
        s.tempo += t; 
        atendentes.push(s); 
    }
    for (int i = 1; i <= n; i++){
        cout  << i << " " << quant[i] << endl;
    }
}