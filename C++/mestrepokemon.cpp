#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool comp (int i, int j){
    return (i>j); 
}
int main(){
    int t, l, p; 
    vector <int> pokemon;
    cin >> t >> l;
    for (int i=0; i<t; i++){
         cin >> p;
         pokemon.push_back(p);
    }
    sort(pokemon.begin(), pokemon.end(), comp);
    for (int i =0; i<l; i++)
        cout << pokemon[i] << endl; 
    
}
