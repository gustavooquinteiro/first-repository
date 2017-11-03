#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct agenda {
char nome[50];
char fone[15];
char endereco[50];
	
	struct agenda*prox;
};

struct agenda *ini=NULL;




int inserir(){

struct agenda *novo , *ant, *aux;

novo=(struct agenda*)malloc(1*sizeof( struct agenda)); 
printf ("Digite o nome: ");
scanf("%s", novo->nome);
printf ("Digite o telefone: ");
scanf("%s", novo->fone);
printf ("Digite o endereço: ");
scanf("%s", novo->endereco);
novo-> prox=NULL;

if(ini==NULL){
	ini= novo;
}
else{
ant=aux=ini;

while (strcmp( novo->nome, aux->nome)>0){
	ant=aux;
	aux=aux->prox;
	if (aux==NULL) break;
}
if (ant==aux){
	novo->prox=ini;
	ini=novo;
}
else{
	if(aux==NULL)
	ant -> prox=novo;
	else{
		ant->prox=novo;
		novo->prox=aux;
	}
}
}
return(0);
}

void mostrar (){

struct agenda *aux2;
	aux2=ini;
	
if (aux2==NULL)
printf("Agenda está vazia. Entre com os dados.");

else{
	system("clear");
	printf("AGENDA");
 while (aux2!=NULL){
	printf("\n NOME: %s", aux2->nome);	
	printf("\n CONTATO: %s", aux2->fone);
	printf("\n ENDEREÇO: %s \n", aux2->endereco);	
aux2=aux2->prox;
}
}
	
}

int main(){
int op;
do{
	printf ("\n ESCOLHA UMA OPÇÃO: \n");
	printf ("1 INSERIR\n");
	printf ("2 MOSTRAR\n");
	scanf ("%d", &op);
	
	
	if (op==2){

		mostrar();
	}

	if (op==1){
		inserir();
	}

} while(op!=0);
	return(0);
}
