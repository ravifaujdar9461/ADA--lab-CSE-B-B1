#include<stdio.h>
int arr_fib[100];
int fib(int n){
    if(n<=1)
    return n;
    if(arr_fib[n]!=-1)
    return arr_fib[n];
    arr_fib[n]=fib(n-1)+fib(n-2);
    return arr_fib[n];
}

int main(){
int term;
printf("please enter the number of term: ");
scanf("%d",&term);
for(int i=0;i<term;i++){
    arr_fib[i]=0;
}
for(int i=0;i<term;i++){
 printf("%d",fib(i));
}
    return 0;
}