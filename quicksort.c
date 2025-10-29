#include<stdio.h>
int partation(int arr[],int low,int high){
int pivot=arr[low];
int i=low+1;
int j=high;
int temp;
do
    {
        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    } while (i<j);
    temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}


void print(int arr[],int low,int high){
    for(int i=0;i<=high;i++){
        printf("%d ",arr[i]);
    }
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int p=partation(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}
int main(){
    int arr[]={5,8,2,9,4,7,2,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    print(arr,0,size-1);
    return 0;


}