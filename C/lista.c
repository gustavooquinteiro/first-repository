#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct agenda{
	char nome [30];
	char fone [15];
	char endereco[50];
	struct agenda *prox;
};

struct agenda *ini;
struct agenda *novo, *ant, *aux;
FILE *arquivo; 

int inserir (){
novo = (struct agenda *)malloc(1 * sizeof (struct agenda));
printf("Digite um nome");
scanf("%s", novo->nome); 
printf("Digite um telefone");
scanf("%s", novo->fone);
printf("Digite um endereco");
scanf("%s", novo->endereco);

novo->prox = NULL;

if (ini==NULL){
	ini=novo;
} else{
	ant = aux = ini; 
	while(strcmp(aux->nome,novo->nome)<0){
		ant = aux;
		aux = aux->prox;
		if (aux == NULL) break;
	}
	if (ant == aux){
		novo->prox = ini;
		ini = novo;
	}else{
		if (aux == NULL)
		ant->prox = novo;
		else{
			ant-> prox = novo;
			novo -> prox = aux;
		}
	}
}
return 0;
} 

int mostrar(){
	aux = ini;
	while (aux!=NULL){
		printf("%s \n", aux->nome);
		printf("%s \n", aux->endereco);
		printf("%s \n", aux->fone);
		aux = aux-> prox;
	}
	return 0;
}

int salvar (){
	struct agenda *aux;
	aux = ini; 
	if (aux == NULL)
		printf("Lista vazia");
	else{
		arquivo = fopen("agenda.txt", "w");
		while (aux!=NULL){
			fwrite(aux, sizeof(struct agenda), 1, arquivo);
			aux = aux->prox;
		}
		fclose(arquivo);
	}
	
	return 0;
}

int ler (){
	struct agenda *aux, *tmp;
	arquivo = fopen("agenda.txt", "r");
	while(!feof(arquivo)){
		tmp = (struct agenda *)malloc(1 * sizeof(struct agenda)); 
		tmp -> prox = NULL;
		fread(tmp, sizeof(struct agenda), 1, arquivo);
		if (ini==NULL)
		aux = ini = tmp;
		else{
			aux ->prox = tmp;
			aux = tmp;
		}
	}
	fclose(arquivo);

	return 0; 			
}

int buscar(){
	char busca [20];
	aux = ini; 
	printf("Digite um nome para buscar: ");
	scanf("%s", busca);
	while (aux!=NULL){
		if (strcmp(aux->nome, busca)==0){
			printf("NOME DO CONTATO: %s", aux->nome); 
			printf("ENDERECO: %s", aux->endereco); 
			printf("TELEFONE: %s ", aux->fone);
			break;
		}
	aux=aux->prox;	
	}

	return 0;
}

int main (){
	int op = 0;
	do {
	printf("Digite 1 para inserir valores na lista \n Digite 2 para mostrar a lista \n Digite 3 para salvar \n Digite 4 para ler \n Digite 5 para buscar \n Digite 0 para sair");
	scanf("%d", &op);lk
		switch (op){
			case 1: inserir(); break;
			case 2: mostrar(); break; 
			case 3: salvar(); break;
			case 4: ler(); break; 
			case 5: buscar(); break;
		} 
	}while(op!=0);
	return 0;
}
