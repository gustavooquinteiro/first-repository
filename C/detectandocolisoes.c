#include <stdlib.h>
#include <stdio.h>

int main(){
int x, y, x1, y1, x2, y2, x3, y3;
scanf("%d%d%d%d", &x,&y, &x1, &y1); 
scanf("%d%d%d%d", &x2,&y2, &x3, &y3); 
if(x1 < x2 || y1 < y2 || x3 < x || y3 < y)
	printf("0\n"); 
else printf("1 \n"); 
return 0;
}
