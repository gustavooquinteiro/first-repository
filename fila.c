#include <stdio.h>
#include <stdlib.h>

int a[10];
int i,op, quant;

int inserir(){
quant=(int *)malloc(1*sizeof(int));
printf("Digite um numero:");
scanf("%d",&a[i]);

return 0;
}

int remover(){
for (i=0; i<10; i++){
	a[i]=a[i+1];
}

return 0;
}

int listar(){
for(i=0;i<10;i++){
	printf("\n %d",a[i]);
}
return 0;
}

int main (){
do{
	printf("Digite uma opção \n 1 - Para inserir \n 2 - Para remover \n 3 - Para listar:");
	scanf("%d",&op);
		switch(op){
			case 1:
				inserir();
				break;
			case 2:
				remover(); 
				break;
			case 3:
				listar();
				break;
			default:
			break;
		}
}while(op!=0); 

return 0;
}
