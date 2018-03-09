#include <stdio.h>

int main(){
	int n,x, k;

	scanf("%d%d", &n, &k); 
	int tipo[k];
	for (int i =0; i<k; i++){
		tipo[i]=0;
	}
	
	for (int i =0; i<n;i++){
		scanf ("%d", &x);
		tipo[x-1]++; 
	}
	int minimo = tipo[0]; 
	for(int i =0; i<k; i++){
		if(tipo[i] < minimo) 
			minimo = tipo[i];
	}
	
	printf("%d\n", minimo); 
return 0;
}
