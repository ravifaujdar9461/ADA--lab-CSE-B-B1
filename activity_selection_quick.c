#include<stdio.h>
struct activity{
   int start;
   int end; 
};
int partation(struct activity arr[],int low,int high){
int pivot= arr[low].end;
int i=low+1;
int j=high;
struct activity temp;
do
    {
        while (arr[i].end <= pivot)
        {
            i++;
        }

        while (arr[j].end > pivot)
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


void print(struct activity arr[],int low,int high){
    for(int i=0;i<=high;i++){
        printf("(%d,%d) ",arr[i]);
    }
}
void quicksort(struct activity arr[],int low,int high){
    if(low<high){
        int p=partation(arr,low,high);
        quicksort(arr,low,p-1);
        quicksort(arr,p+1,high);
    }
}
void activity_selection(struct activity act[],int n){
print(act,0,n-1);
quicksort(act,0,n-1);
int last=0;
printf("maximum selected activity: (%d,%d),",act[0].start,act[0].end);
for(int i=1 ;i<n;i++){
    if(act[i].start>act[last].end){
        printf("(%d,%d)",act[i].start,act[i].end);
        last=i;
    }
}

}
int main(){
    struct activity act[]={{5,9},{1,2},{3,4},{0,6},{5,7},{8,9}};
    int n=sizeof(act)/sizeof(act[0]);
    activity_selection(act,n);
    return 0;

}