#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void selectionsort(int  arr[],int n){
for(int i=0;i<n-1;i++){
    int min_ind=i;

    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min_ind]){
        min_ind=j;
        }
    }
    int temp=arr[i];
    arr[i]=arr[min_ind];
    arr[min_ind]=temp;
}
}
// void printarray(int arr[],int n){
//     printf("{");
//     for(int i=0;i<n;i++){
//         printf("%d ",arr[i]);
    
//     }
//     printf("}");
    
//     }
    void generateRandomArray(int arr[],int n){
    for(int i=0;i<n;i++){
   arr[i] =rand()%100000;
    //  printf(" %d,",arr[i]);
    }
     
}
     

int main(){
    srand(time(NULL));
    int n;
    printf("enter the array size : ");
    scanf("%d",&n);
     int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL)
    {
        printf("memory allocation is failed");
        return 1;
    }
   generateRandomArray(arr,n);
//    printarray(arr,n);

  clock_t start = clock();
  
   selectionsort(arr,n);
clock_t end=clock();

 double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
  printf("time taken to sort %d element:%fsecond\n",n,time_taken);
    return 0;
}


