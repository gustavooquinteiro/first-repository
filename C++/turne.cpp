#include <iostream>
#include <queue>
#include <string>
#include <ctype.h> 
using namespace std;
int main(){
    string cidade; 
    queue <string> lista; 
    while (cin >> cidade){
        lista.push(cidade);
    }
    while (!lista.empty()){
        cout << lista.front() << endl;
        string aux = lista.front();
        lista.pop(); 
        if (lista.empty())
            break; 
        else{
            if (aux[aux.size()-1] == tolower(lista.front()[0])){
                lista.push(lista.front()); 
                lista.pop(); 
            }
        }
    }
}
