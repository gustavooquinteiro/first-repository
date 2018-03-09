#include <stdlib.h>
#include <stdio.h>

int main(){
int n, meio, indice, novo =0; 
scanf("%d", &n); 
int a[n]; 
for (int i =0; i<n; i++){
	scanf ("%d", &a[i]); 
	meio += a[i]; 
}
meio = meio/2;
for (int i=0; i<n; i++){
	novo += a[i];
	if(novo == meio){
		indice = i+1; 
		break;
	}
}
printf("%d\n", indice); 
return 0;
}
