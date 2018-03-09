#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int senha[6];

char* decode(){
	char* ret;
	char* tmp;
	for (int i = 0; i < 6; i++) {
		switch(senha[i]){
			case 1: tmp = "0"; break;
			case 2: tmp = "1"; break;
			case 4: tmp = "2"; break;
			case 8: tmp = "3"; break;
			case 16: tmp = "4"; break;
			case 32: tmp = "5"; break;
			case 64: tmp = "6"; break;
			case 128: tmp = "7"; break;
			case 256: tmp = "8"; break;
			case 512: tmp = "9"; break;
		}
		size_t len = strlen(tmp); 	
		ret = malloc(len + 1 + 1); 
		strcpy(ret, tmp); 
		ret[len] = tmp; 
		ret[len + 1] = ' '; 
		ret[len + 2] = '\0'; 
	 }
	 
	 return ret;
}
int readAsBitSet(){
	int tmp, set;
	scanf ("%d", &tmp); 
	set = 1<<tmp;
	scanf ("%d", &tmp); 
	set |= 1<< tmp;
	return set;
	}

char* getSenha(int tam){
	int a, b, c, d, e;
	char s; 
	for (int i=0;i<6; i++) senha[i]=0xfff;
	for (int j =0; j<tam;j++){
		a = readAsBitSet();
		b = readAsBitSet();
		c = readAsBitSet();
		d = readAsBitSet();
		e = readAsBitSet(); 
		for (int i = 0; i<6; i++){
			scanf("%c", &s); 
			switch(s){
				case 'A': senha[i] &= a; break;
				case 'B': senha[i] &= b; break;
				case 'C': senha[i] &= c; break;
				case 'D': senha[i] &= d; break;
				case 'E': senha[i] &= e; break;
			}	
		}
	
	}
	return decode(); 
}
int main(){
int N;
int cont =0;  
while (scanf("%d", &N) && N!=0){
	printf("Teste %d \n %s\n \n ", ++cont, getSenha(N));
}

return 0;
}
