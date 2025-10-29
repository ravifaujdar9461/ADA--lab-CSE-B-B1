// #include <stdio.h>

// typedef struct {
//     int idx;
//     int value;
//     int weight;
//     int ratio;   // value per weight
// } Item;

// // bubble sort se sorted kiya gya  
// void sortItems(Item items[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         for (int j = 0; j < n - i - 1; j++) {
//             if (items[j].ratio < items[j + 1].ratio) {
//                 Item temp = items[j];
//                 items[j] = items[j + 1];
//                 items[j + 1] = temp;
//             }
//         }
//     }
// }

// int main() {
//     int n, capacity;

//     printf("Number of items: ");
//     scanf("%d", &n);

//     Item items[n];
//     float fraction[n];   // array to store fraction taken (0 to 1)

//     // Input items
//     for (int i = 0; i < n; i++) {
//         int v, w;
//         printf("Enter value and weight for item %d: ", i + 1);
//         scanf("%d %d", &v, &w);
//         items[i].idx = i + 1;
//         items[i].value = v;
//         items[i].weight = w;
//         items[i].ratio = v / w;  // integer division
//         fraction[i] = 0.0;        // initially nothing taken
//     }

//     printf("Knapsack capacity: ");
//     scanf("%d", &capacity);

//     // Sort by ratio
//     sortItems(items, n);

//     printf("\nItems sorted by ratio (descending):\n");
//     for (int i = 0; i < n; i++) {
//         printf("Item %d: value=%d, weight=%d, ratio=%d\n",
//                items[i].idx, items[i].value, items[i].weight, items[i].ratio);
//     }

//     // Knapsack logic
//     int remaining = capacity;
//     int totalProfit = 0;

//     for (int i = 0; i < n && remaining > 0; i++) {
//         if (items[i].weight <= remaining) {
//             // pura item lo
//             fraction[i] = 1.0;
//             totalProfit += items[i].value;
//             remaining -= items[i].weight;
//         } else {
//             // fraction lo
//             fraction[i] = (float)remaining / items[i].weight;
//             totalProfit += (int)(items[i].value * fraction[i]);
//             remaining = 0;
//         }
//     }

//     // Print fractions taken
//     printf("\nFraction of items taken (in sorted order):\n[ ");
//     for (int i = 0; i < n; i++) {
//         if (fraction[i] == 1.0)
//             printf("1 ");
//         else if (fraction[i] == 0.0)
//             printf("0 ");
//         else {
//             // print as numerator/denominator (approx)
//             printf("%d/%d ", (int)(fraction[i] * items[i].weight), items[i].weight);
//         }
//     }
//     printf("]\n");

//     // Total profit
//     printf("\nTotal Profit = %d\n", totalProfit);

//     return 0;
// }

#include<stdio.h>
float fractionalknapsack(int n, int weight[],int values[],int capacity){
float ratio[n];
for(int i=0;i<n;i++){
    ratio[i]=(float)values[i]/weight[i];
}
 // sort items by ratio in desecending order

 for(int i=0;i<n-1;i++){
    for(int j=0;j<n-i-1;j++){
        if(ratio[j]<ratio[j+1]){
            float tempr=ratio[j];
            ratio[j]=ratio[j+1];
            ratio[j+1]=tempr;
            // swap values
            int tempp=values[j];
            values[j]=values[j+1];
            values[j+1]=tempp;
            // swap weight
            int tempq=weight[j];
            weight[j]=weight[j+1];
            weight[j+1]=tempq;

        }
    }
 }
float totalvalues=0;
for(int i=0;i<n;i++){
if(capacity==0)
break;

if(weight[i]<=capacity){
    capacity-=weight[i];
    totalvalues+=values[i];
}
else{
    totalvalues+=values[i]*((float)capacity)/weight[i];
    capacity=0;
}

}
return totalvalues;



}
int main(){
    int item;
    int w[4]={5,2,4,4};
    int v[4]={5,6,7,8};
    int c=15;
    printf("please enter the item : ");
    scanf("%d",&item);
    float result=fractionalknapsack(item,w,v,c);
    printf("%f\n",result);


    return 0;
}