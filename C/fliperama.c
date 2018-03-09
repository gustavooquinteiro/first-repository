#include <stdlib.h>
#include <stdio.h>

int main(){
int M, N;
scanf("%d%d", &N, &M);
int pontuacao[N], aux; 
for (int i =0; i<N; i++)
	scanf("%d", &pontuacao[i]);
	
for(int i =0; i<N;i++){
	for(int j =0; j<N;j++){
		if(pontuacao[i]>pontuacao[j]){
			aux = pontuacao[i];
			pontuacao[i] = pontuacao[j];
			pontuacao[j]=aux;
		}
	}
}
for (int j =0; j<M; j++)
	printf("%d\n", pontuacao[j]); 
return 0;
}
