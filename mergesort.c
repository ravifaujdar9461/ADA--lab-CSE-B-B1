#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right)
{

    int i = 0, j = 0, k = 0;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++, k++;
        }
        else
        {
            arr[k] = R[j];
            j++, k++;
        }
    }
    while(i<n1){
        arr[k]=L[i];
        k++,i++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++,k++;
    }
    free(L);
    free(R);
}

void mergesort(int arr[],int L,int R ){
    if(L<R){
        int mid=(L+R)/2;
        mergesort( arr,L,mid);
        mergesort(arr,mid+1,R);
        merge(arr,L,mid,R);
    }
}
void generateRandomArray(int arr[],int n){
    for(int i=0;i<n;i++){
   arr[i] =rand()%100000;
    //  printf(" %d,",arr[i]);
    }
     
}
int main(){
    int n;
    printf("enter ther number of element: ");
    scanf("%d",&n);
     srand(time(NULL)); // Seed random number generator
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    
    generateRandomArray(arr,n);
     
    clock_t start=clock();
    for(int i=0;i<1000;i++){
        mergesort(arr,0,n-1);
    }
    clock_t end=clock();

    // calculate the trime taken for one itteration
   double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("time taken to sort %d element:%fsecond\n",n,time_taken);
    free(arr);
    return 0;


}

