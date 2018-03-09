#include <stdio.h>
#include <string.h>
int main(){
	char msg[1002];
	char decoded[1000]; 
	int m, i;
	m = 0; 
		while (scanf ("%s", msg)){
		if (m!=0)
			decoded[m++]=' ';
		for (i = 0; i <strlen(msg); i++)
				decoded[m++]=msg[++i];
		}
	printf("%s\n", decoded);
	return 0;
}
