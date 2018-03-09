#include <iostream>
#include <set>
using namespace std;
int main(){
    int i, n, k, a;
    set <int> amigos; 
    set <int> amigosDeAmigos;
    cin >> i;
    int cont =0; 
    for (int x =0; x<i;x++){
        cin >> k >> n;
        amigos.insert(k); 
        amigosDeAmigos.erase(k); 
        for (int y =0; y<n;y++){
            cin >>a;  
            if (amigos.find(a) == amigos.end())
                amigosDeAmigos.insert(a);
        }  
    }
    for(set<int>::iterator it=amigosDeAmigos.begin(); it!=amigosDeAmigos.end(); it++){
        cont++;
    }

    
    cout << cont << endl;
}
