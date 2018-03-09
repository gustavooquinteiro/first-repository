#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
int main(){
    int n, p, m;
    list<int> fila;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        fila.push_back(p);
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> p;
        list<int>::iterator it = find(fila.begin(), fila.end(), p);
        fila.erase(it);
    }
    for (list<int>::iterator it = fila.begin(); it != fila.end() ; it++) {
        cout << *it << " ";
    }
    cout << endl;

}
