#include <stdio.h>
#include<stdlib.h>
#include<time.h>
int binarysearch(int arr[], int key, int start, int end)
{
int mid = start + (end - start) / 2;
if (arr[mid] < key)
{
return binarysearch(arr, key, mid + 1, end);
}
else if (arr[mid] == key)
{
return mid;
}
else
{
 return binarysearch(arr, key, start, mid - 1);
}
}
void randomSortedArray(int arr[], int n, int key) {
arr[0] = rand() % 10; // Start with small number
for (int i = 1; i < n - 1; i++) {
arr[i] = rand() % 100000;
}
arr[n - 1] = key; // last index par key ko dala
}
void byinsertionsort_sorted_element(int arr[], int n){
for(int i=1;i<n;i++){
int key=arr[i];
int j=i-1;
while(j>=0 && key<arr[j]){
arr[j+1]=arr[j];
j=j-1;
}
arr[j+1]=key;
}
// for(int i=0;i<n;i++){
// printf("%d ",arr[i]);
// }
}
int main(){
srand(time(NULL));
int n , key;
printf("enter the size of array and search number ");
scanf("%d %d", &n, &key);
int *arr = (int *)malloc(n * sizeof(int));
if (arr == NULL)
{
printf("memory allocation is failed");
return 1;
}
int s=0;
int e=n-1;
randomSortedArray(arr,n,key);
byinsertionsort_sorted_element(arr,n);
int m=binarysearch(arr, key, s, e);
printf("%d ",m);
clock_t start=clock();
for(int i=0;i<1000000;i++){
binarysearch(arr, key, s, e);}
clock_t end=clock();
double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
printf("time taken to binary search %d element:%fsecond\n",n,time_taken);
free(arr);
return 0;
}