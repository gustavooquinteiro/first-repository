#include <stdio.h> 
int fibo(int N){
if (N==1) return 1;
if (N==2) return 1;
return fibo(N-1)+fibo(N-2);
}
int main(){
int c;
scanf("%d", &c);
printf("%d \n", fibo(c));
}
