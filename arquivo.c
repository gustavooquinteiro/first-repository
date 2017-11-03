#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct produto{
	int cod;
	float preco;
	char desc[20];
	int quant;
}item;

FILE *p;
item *k;

int editar(){
p=fopen("arquivo.bin","wb");
printf("Digite o codigo do produto: ");
scanf("%d",&k->cod);
printf("Digite o preço do produto: ");
scanf("%f",&k->preco);
printf("Digite a descrição do produto: ");
scanf("%s",k->desc);
printf("Digite a quantidade de produto: ");
scanf("%d",&k->quant);
fwrite(&k,sizeof(item),1,p);
fclose(p);
return 0;
}

int ler(){
 p=fopen("arquivo.txt","rb");
 fread(k, sizeof(item),1,p);
return 0;
}

int abrir(){
	
	return 0;
}

int main(){
int op;
do{
printf("\n 1 - ESCREVER");
printf("\n 2 - LER");
printf("\n 3 - ABRIR");
scanf("%d",&op);
switch(op){
case 1:editar(); break;
case 2:ler(); break;
case 3:abrir(); break;
}
}while(op!=0);
return 0;
}
