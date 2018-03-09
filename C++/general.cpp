#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(){
    int s, i; 
    cin >> s >> i; 
    vector <string> nomes;
    string n;
    for (int i=0; i<s+1; i++){
        getline(cin, n); 
        //cin.ignore(); 
        nomes.push_back(n);        
    }
    sort(nomes.begin(), nomes.end());
    cout << nomes[i] << endl; 
}
