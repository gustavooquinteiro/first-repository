#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
	int valor;
	struct pilha *ant;
}p;

struct pilha *topo=NULL;
struct pilha *novo;

int inserir(){
	if(topo==NULL){
		topo=(p*)malloc(1*sizeof(p));
		topo->ant=NULL;
		printf("Digite um valor:");
		scanf("%d",&topo->valor);
	}
	else{
		novo=(p*)malloc(1*sizeof(p));
		novo->ant=topo;
		printf("Digite um valor: ");
		scanf("%d",&novo->valor);
		topo=novo;
	}

return(0);
}

int  mostrar(){
p *aux;
	if(topo==NULL){
	printf("Pilhas vazias");
	}
	else{
	aux=topo;
		while(aux!=NULL){
		printf("\n %d",aux->valor);
		aux=aux->ant;
		}
	}
return 0;
}

int main(){
int a;
	do{
	printf("\n Digite uma das opcoes: ");
	printf("\n Digite 1 para inserir valores");
	printf("\n Digite 2 para mostrar");
	printf("\n Digite 0 para sair");
	scanf("%d",&a);
		switch(a){
		case 1: inserir(); break;
		case 2: mostrar(); break;
		}
	}while(a!=0);
return 0;
}
