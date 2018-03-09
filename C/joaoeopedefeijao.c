#include <stdlib.h>
#include <stdio.h>
int isKaprekar(int n){
	int n2 = n*n;
	int q, r, P;
	P=10;
	q = r =0; 
	while(P<n2){
		q=n2/P;
		r=n2%P;
		P *=10;
		if (n == (q+r)&& r!=0) 
			return 0;
	}
	return 1;
}
int main(){
	int n;
	while (scanf("%d", &n) && n!=0){
		if (!isKaprekar(n) || n == 1){
			printf("%d: S\n", n);
		}else{
			printf("%d: N\n", n); 
		}	
	}
return 0;
}
