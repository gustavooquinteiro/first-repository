#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct pais{
    int id;
    int medalhasOuro;
    int medalhasPrata;
    int medalhasBronze; 
};
bool comp(pais i, pais j){
    if ((i.medalhasOuro > j.medalhasOuro)
        ||(i.medalhasOuro == j.medalhasOuro && i.medalhasPrata > j.medalhasPrata) 
        ||(i.medalhasOuro == j.medalhasOuro && i.medalhasPrata == j.medalhasPrata && i.medalhasBronze > j.medalhasBronze) 
        ||(i.medalhasOuro == j.medalhasOuro && i.medalhasPrata == j.medalhasPrata && i.medalhasBronze == j.medalhasBronze && i.id < j.id)){
        return true;
    } else{
        return false;
    }
}
int main(){
    int n, m, o, p, b;
    cin >> n >> m; 
    vector <pais> ganhadores; 
    vector <int> medalhasOuro (n+1);
    vector <int> medalhasPrata (n+1);
    vector <int> medalhasBronze (n+1);
    pais participante;

    for (int i =0; i<m; i++){
        cin >> o >> p >> b; 
        medalhasOuro[o]++;
        medalhasPrata[p]++; 
        medalhasBronze[b]++; 
    }

    for (int i =0; i <= n; i++){
        participante.id = i; 
        participante.medalhasOuro = medalhasOuro[i];
        participante.medalhasPrata = medalhasPrata[i];
        participante.medalhasBronze = medalhasBronze[i]; 
        ganhadores.push_back(participante); 
    }

    sort(ganhadores.begin(), ganhadores.end(), comp); 

    for (int i =0; i<ganhadores.size(); i++){
     if(ganhadores[i].id !=0)
        cout << ganhadores[i].id << " "; 
    }
    cout << endl;

}
