#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct produto{
	int cod;
	int preco;
	char desc[20];
	int quant;
}prod;
int tam;
prod *p;

int criar(){
printf("Digite o tamanho do vetor:");
scanf("%d",&tam);
p = (prod *)malloc(tam*sizeof(prod));
return 0;
}

int inserir(){
	int i = 0;
		printf("Digite o código do produto:");
		scanf("%d",&p[i].cod);
		printf("Digite o preço do poduto:");
		scanf("%d",&p[i].preco);
		printf("Digite uma descrição do produto:");
		scanf("%s",p[i].desc);
		printf("Digite a quantidade do produto:");
		scanf("%d",&p[i].quant);
	
	return 0;
}

int ler(){
	int i;
	for(i=0;i<tam;i++){
		scanf("%d",&p[i].cod);
		scanf("%d",&p[i].preco);
		scanf("%s",p[i].desc);
		scanf("%d",&p[i].quant);
	}
	
 return 0;	
}

int buscar(){
char b[20];
int i;

printf("Digite um nome:");
scanf("%s", b);	
for(i=0;i<tam;i++){
		if(strcmp(b, p[i].desc)){
		scanf("%d",&p[i].cod);
		scanf("%d",&p[i].preco);
		scanf("%s",p[i].desc);
		scanf("%d",&p[i].quant);
		}
}
return 0;
}
int atualizar(){
	
return 0;	
}

int main (){
int op;
printf("Escolha alguma coisa:");
printf("1 - Criar\n 2 - Inserir \n 3 - Ler \n 4-Buscar \n 5-Atualizar \n 6 - Salvar em arquivo \n 7-Ler Arquivo \n 8--Sai");
scanf("%d",&op);
switch(op){
case 1: criar();break;
case 2: inserir(); break;
case 3: ler(); break;
case 4: buscar(); break;
case 5: atualizar(); break;



}



return 0;
}
