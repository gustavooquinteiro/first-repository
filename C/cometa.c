#include <stdlib.h>
#include <stdio.h>

int main(){
int a;
scanf("%d", &a); 
printf("%d", (2062+a-1986)-((a-1986)%76)); 

return 0;
}
