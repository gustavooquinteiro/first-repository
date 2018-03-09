#include <list>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    scanf(" %d", &n);
    list<int> lista;
    bool flag = false;
    for (int i = 0; i < n; i++) {
        string op;
        cin>> op;
        int a;
        if (op == "back" && !flag){
            if (lista.empty()){
                printf("No job for Ada?\n");
            }else{
                printf("%d\n",lista.back());
                lista.pop_back();
            }
        } else if (op=="back" && flag){
            if (lista.empty()){
                printf("No job for Ada?\n");
            }else{
                printf("%d\n", lista.front());
                lista.pop_front();
            }
        }
        if (op == "front" && !flag){
            if (lista.empty()){
                printf("No job for Ada?\n");
            }else{
                printf("%d\n", lista.front());
                lista.pop_front();
            }
        } else if (op=="front" && flag){
          if (lista.empty()){
                printf("No job for Ada?\n");
            }else{
                printf("%d\n",lista.back());
                lista.pop_back();
            }
        }
        if (op == "reverse")
            flag = !flag;

        if (op == "push_back" && !flag){
            scanf("%d",&a);
            lista.push_back(a);
        }  else if (op == "push_back" && flag){
            scanf("%d",&a);
            lista.push_front(a);

        }

        if (op == "toFront" && !flag){
            scanf("%d",&a);
            lista.push_front(a);
        } else if (op=="toFront" && flag){
            scanf("%d", &a);
            lista.push_back(a);
        }
    }
}
