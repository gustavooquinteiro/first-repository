#include <stdlib.h>
#include <stdio.h>

int main(){
int n, m, pos, d;
scanf("%d %d", &n, &m);
int pedras[n]; 
for (int i =0; i<n; i++)
	pedras[i]=0;
	
for (int i=0;i<m; i++){
	scanf("%d%d", &pos, &d); 
	int aux = pos-1;
	pedras[aux]=1; 
	while(aux+d <n){
		aux+=d;
		pedras[aux]=1;
	}
	aux = pos -1;
	while (aux-d >=0){
		aux-=d;
		pedras[aux]=1;
	}
}
for (int i =0; i<n; i++)
	printf("%d \n", pedras[i]); 

return 0;
}
