#include<stdio.h>
void printfibnaccio(int n){
    int n1=0,n2=1;
    int next_term;
    int sum=0;
    for(int i=1;i<=n;i++){
        sum=sum+n1;
        next_term=n1+n2;
        n1=n2;
        n2=next_term;
    }
    printf("%d",sum);
}
int main(){
    int term;
    printf("enter the  number of term: ");
    scanf(" %d",&term);
    printfibnaccio(term);
}