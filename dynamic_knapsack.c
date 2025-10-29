// #include <stdio.h>

// int max(int a, int b) {
//     return (a > b) ? a : b;
// }

// int main() {
//     int n = 4;                       // number of items
//     int W = 5;                       // knapsack capacity
//     int wt[] = {2, 3, 4, 5};         // weights
//     int val[] = {3, 4, 5, 6};        // values
    
//     int dp[n+1][W+1];

//     // Step 1: Build DP table
//     for (int i = 0; i <= n; i++) {
//         for (int w = 0; w <= W; w++) {
//             if (i == 0 || w == 0)
//                 dp[i][w] = 0;
//             else if (wt[i-1] <= w)
//                 dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
//             else
//                 dp[i][w] = dp[i-1][w];
//         }
//     }

//     // Step 2: Maximum profit
//     printf("Maximum Profit = %d\n", dp[n][W]);

//     // Step 3: Traceback to find selected items
//     int selected[n];
//     for (int i = 0; i < n; i++) selected[i] = 0; // initialize

//     int w = W;
//     for (int i = n; i > 0; i--) {
//         if (dp[i][w] != dp[i-1][w]) {
//             selected[i-1] = 1;       // item i-1 is selected
//             w -= wt[i-1];
//         }
//     }

//     // Step 4: Print selection array
//     printf("Selected items array: { ");
//     for (int i = 0; i < n; i++) {
//         printf("%d", selected[i]);
//         if (i < n-1) printf(", ");
//     }
//     printf(" }\n");

//     return 0;
// }


#include<stdio.h>
int max(int a,int b){
    return (a>b)?a:b;
}
int main(){
int c=5;
int n=4;
int profit[] ={7,8,9,13};
int weight[]= {4,3,5,4};
int m[n+1][c+1];
for(int i=0;i<=n;i++){
    for(int j=0;j<=c;j++){
        if(i==0||j==0){
            m[i][j]=0;
        }
        else if (weight[i-1]<=j){
            m[i][j]=max(m[i-1][j],m[i-1][j-weight[i-1]]+profit[i-1]);

            }
            else
            m[i][j]=m[i-1][j];
        }
    }
    printf("%d\n",m[n][c]);


 int selected[n];
 for(int i=0;i<n;i++){
    selected[i]=0;
 }


 int p=c;
 for(int i=n;i>0;i--){
    if(m[i][p]!=m[i-1][p]){
        selected[i-1]=1;
        p=p-weight[i-1];
    }

 }



 printf("Selected items array: { ");
    for (int i = 0; i < n; i++) {
        printf("%d", selected[i]);
        if (i < n-1) printf(", ");
    }
    printf(" }\n");

    return 0;
}
