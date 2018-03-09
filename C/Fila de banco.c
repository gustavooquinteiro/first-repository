#include <stdlib.h>
#include <stdio.h>
struct banco{
	int ag;
	int num;
	char titular[20];
	float saldo;
};
typedef struct fila {
	int ag;
	int num;
	int op;
	float valor;
	struct fila *ant;
}fila;
struct banco b[5];
fila *topo=NULL, *fim=NULL, *aux=NULL, *novo=NULL; 

int criar(){
	int i;
	for (i=0; i<5; i++){
		printf("Digite o numero da agencia: ");
		scanf("%d", &b[i].ag);
		printf("Digite o numero da conta corrente: ");
		scanf("%d", &b[i].num);
		printf("Digite o nome do titular: ");
		scanf("%s", b[i].titular);
		printf("Digite o saldo: ");
		scanf("%f", &b[i].saldo);
	}
	return 0;
}

int mostrarcontas(){
	int i;
	for (i=0; i<5; i++){
		printf("%d", b[i].ag);
		printf("%d", b[i].num);
		printf("%s", b[i].titular);
		printf("%f", b[i].saldo);
		printf("_________________");
	}
	return 0;
}

int cadastrar(){
	novo=(fila*)malloc(1*sizeof(fila));
	
	if (topo==NULL){
		novo->ant=NULL;
		topo=novo=fim;
		printf("Digite o numero da agencia: ");
		scanf("%d", &novo->ag);
		printf("Digite o numero da conta corrente: ");
		scanf("%d", &novo->num);
		printf("Digite a opção; 1 para depositar/2 para sacar: ");
		scanf("%d", &novo->op);
		printf("Digite o valor: ");
		scanf("%f", &novo->valor);
	}
	else{
		fim->ant=novo;
		fim=novo;
		printf("Digite o numero da agencia: ");
		scanf("%d", &novo->ag);
		printf("Digite o numero da conta corrente: ");
		scanf("%d", &novo->num);
		printf("Digite a opção; 1 para depositar/2 para sacar: ");
		scanf("%d", &novo->op);
		printf("Digite o valor: ");
		scanf("%f", &novo->valor);
	}
	return 0;
}
int atender(){
	int i;
	if (topo==NULL){
	}
	else{
		aux=topo; 
		for(i=0; i<5; i++){
		if(aux->ag==b[i].ag){
			if(aux->op==1){
				b[i].saldo=b[i].saldo+aux->valor; 
			}
			if(aux->op==2){
				b[i].saldo=b[i].saldo-aux->valor; 
			}
			}
		}
	}
	return 0;
}
int mostrarclientes(){
	if (topo==NULL){
	}
	else{
		aux=topo;
		while (aux->ant!=NULL){
			printf("%d", aux->ag);
			printf("%d", aux->num);
			printf("%d", aux->op);
			printf("%f",aux->valor);
			aux=aux->ant; 
		}
	}
	return 0;
	}
	
int main(){
int op=10;
while (op!=0){
printf("Escolha");
printf("1 - Criar Banco");
printf("2 - MOstrar Contas");
printf("3 - Cadastrar clientes");
printf("4 - Atender cliente");
printf("5 - Mostrar clientes");
scanf("%d", &op);

switch (op){
	case 1: 
		criar();
		break;
	case 2:
		mostrarcontas();
		break;
	case 3:
		cadastrar();
	case 4:
		atender();
		break;
	case 5:
		mostrarclientes();
		break;
	default: 
	printf("OPção Invalida");
	break;		
	}
}
return 0;
}
