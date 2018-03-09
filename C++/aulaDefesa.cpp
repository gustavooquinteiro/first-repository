#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    
    int f, cont; 
    string feitico;
    while (cin >> f && f != 0){
        set <string> runas;
        cont =1;
        for (int i =0; i<f;  i++){
            cin >> feitico;
            sort(feitico.begin(), feitico.end()); 
            //cout << feitico << endl;
            runas.insert(feitico);          
        }
        
        cout << runas.size() << endl; 

    }
    
}
