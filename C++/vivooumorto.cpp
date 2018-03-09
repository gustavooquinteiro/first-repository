#include <iostream>
#include <list>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(){
    int p, r;
    int c, a;
    int n, j;
    int cont = 0;
    while(scanf("%d %d", &p, &r) && p!=0 && r!=0){

        list<int> fila;
        printf("Teste %d\n", ++cont);
        for (int i = 0; i < p; i++) {
            scanf("%d", &c);
            fila.push_back(c);
        }

        for (int i = 0; i < r; i++){
            scanf("%d %d", &n, &j);
            list<int>::iterator y = fila.begin();
            for (int numer = 0; numer <n; numer++) {
                scanf("%d", &a);
                if (a != j){
                    list<int>::iterator aux = y;
                    fila.erase(y);
                    y--;
                }
                y++;
             if (y == fila.end())
                break;
            }
            //y = fila.begin();
        }
        printf("%d\n",fila.front());
    }
}
