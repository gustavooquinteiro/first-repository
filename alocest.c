#include <stdio.h>
#include <stdlib.h>
#define max 3

int dado[max];
int topo=0;
int op;

void exibir(){
printf("\n");
int temp;
for (temp=topo-1;temp>=0; temp--){
printf("Na posição %d temos %d\n", temp, dado[temp]);
}
printf("\n");
}

void inserir (){
if(topo==max){
printf("A pilha está cheia \n ");
}
else{
printf("Digite o valor para entrar na pilha: \n");
scanf("%d",&dado[topo]);
topo++;
}
exibir();
}

void remover(){
if(topo==0){
printf("\nApilha esta vazia\n");
}
else{
printf("\nRetirado o valor %d da pilha\n",dado[topo-1]);
topo--;
}
exibir();
}

int menu(){
printf("Para inserir digite 1\n");
printf("Para remover digite 2\n");
printf("Para exibir digite 3\n");
printf("Para sair digite 4\n");
scanf("%d",&op);
switch(op){
case 1: inserir(); break;
case 2: remover(); break;
case 3: exibir(); break;
}
return 0;
}

int main(){
while(op!=4){
menu();
}
return 0;
}
