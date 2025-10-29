// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// void search(int arr[], int p, int n)
// {
//     int found = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (arr[i] == p)
//         {
//             found = 1;
//             //  printf("find number %d this index %d", p, i);
//             break;
//         }
        
//     }
 
//     if (!found)
//     {
//         printf("the number is not found");
//     }
// }
// void randomarraygenerate(int arr[], int n, int q)
// {
//     for (int i = 0; i < n; i++)
//     {
//         arr[i] = rand() % 1000000;
//         printf("%d  ",arr[i]);
          
//     }
//      arr[n-1]=q;
//      for (int i = 0; i < n; i++){
//         // printf("%d ",arr[i]);
//      }
    
// }
// int main()
// {
//     int n, p;
//     printf("enter the size of array and which number that found in array");
//     scanf("%d %d", &n, &p);

//     int *arr = (int *)malloc(n * sizeof(int));
//     if (arr == NULL)
//     {
//         printf("memory allocation is failed");
//         return 1;
//     }
//     srand(time(NULL)); // agar me srand function ko hta dun to har par random arrray same generate hogi please try 
//     int q = 78;

//     randomarraygenerate(arr, n, q);
    // clock_t start = clock();
    // for(int i=0;i<1000;i++){
    //     search(arr, p, n);}
    // clock_t end = clock();

//     // calculate the trime taken for one itteration
//     double time_taken = ((double)(end - start))/ CLOCKS_PER_SEC;
//     printf("time taken to sort %d element:%fsecond\n", n, time_taken);

//     return 0;
// }



#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 void linearsearch(int arr[],int p,int n){
    int found=0;
   for(int i=0;i<n;i++){
 if(arr[i]==p){
    found=1;

    }
   } // pura loop chala agar fir bhi nahi mila to return karo
   found=0;
   
}
 void randamarraygenerate(int arr[],int n,int q){
    for(int i=0;i<n;i++){
        arr[i]=rand()%1000000;
        
    }
    arr[n-1]=q;
    for(int i=0;i<n;i++){
        
        printf("%d ",arr[i]);
    }
    
}
int main(){
int p,n,q;

printf("please enter the linear searching number p and n and q 'q' is that number which is fix in our array:");
scanf("%d %d %d",&p,&n,&q);
int *arr=(int*)malloc(n*sizeof(int));
if(arr==NULL){
    printf("memory allocation failed ");
    return 1;
}
srand(time(NULL));
randamarraygenerate(arr,n,q);
clock_t start=clock();
for(int i=0;i<10000;i++){
 linearsearch(arr,p,n);
}
clock_t end=clock();
double time_taken=((double)(end-start)) / CLOCKS_PER_SEC;
printf(" time taken by %d element %f",n,time_taken);

    return 0;
}
