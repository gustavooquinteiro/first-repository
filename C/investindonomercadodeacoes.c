#include <stdlib.h>
#include <stdio.h>
int investe(int n, int k){	
	if (n <= k) return 1;
	if (n > k) {
	  if (n%2 == 0) return 2*investe(n/2, k);
	  else return investe(n/2, k) + investe(n/2 + 1, k);
	}
}

int main(){
	int n, k;
	while (scanf("%d%d", &n, &k) && n!=0 && k!=0){
		printf("%d\n", investe(n, k)); 
	}
}
