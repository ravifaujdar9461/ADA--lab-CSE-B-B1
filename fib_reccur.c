#include<stdio.h>
int fib(int n){
    if(n<=1)
    return n;
    else
    return fib(n-1)+fib(n-2);
}
int main(){
int term;
int sum=0;
printf("please enter the number of term:");
scanf("%d",&term);
for(int i=0;i<term;i++){
  printf("%d",fib(i));
  printf(",");
  sum=sum+fib(i);
}
printf("%d ",sum);

    return 0;
}

