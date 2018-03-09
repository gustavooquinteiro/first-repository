#include <stdlib.h>
#include <stdio.h>

int f91(int l){
	if(l<=100) return f91(f91(l+11));
	if (l>=101) return l-10;
}

int main(){
int k; 
while (scanf("%d", &k)){
	if (k==0) break; 
	printf("f91(%d) = %d \n", k, f91(k)); 
}

return 0;
}
