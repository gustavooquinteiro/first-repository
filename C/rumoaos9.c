#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int grau9(int a){
	if(a==9){
		return 1;
	}else{
		int r =0;
		while(a>0){
			r+=a%10;
			a/=10; 
		}
		return 1+grau9(r); 
	}
}
int multiplo(char* n){
	int soma =0;
	for (int i=0; i<strlen(n);i++){
		soma+=n[i]-'0'; 
	}
	if(soma%9==0) return grau9(soma);
	else return 0; 
	}

int main(){

	char palavra[1000];
	while (scanf("%s", palavra) && palavra[0]!='0'){
		if(multiplo(palavra) != 0){
			printf("%s is a multiple of 9 and has 9-degree %d. \n", palavra, multiplo(palavra)); 
		}else{
			printf ("%s is not a multiple of 9. \n", palavra);
		}
	}

return 0;
}
