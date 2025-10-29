// #include <stdio.h>
// int main()
// {
//     int ma[4][4] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};

//     int mb[4][4] = {1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4};
//     int matrix3[4][4];

    //    for(int i=0;i<4;i++){
    //     printf(" enter %d  row element is:" ,i+1);
    //     for(int j=0;j<4;j++){
    //         scanf("%d",&ma[i][j]);
    //     }
    //    }
    //    printf("second matrix :\n");
    //    for(int i=0;i<4;i++){
    //     printf(" enter %d  row element is:" ,i+1);
    //     for(int j=0;j<4;j++){
    //         scanf("%d",&mb[i][j]);
    //     }
    //    }

//     for (int i = 0; i < 4; i++)
//     {
//         for (int j = 0; j < 4; j++)
//         {
//             int temp = 0;
//             for (int k = 0; k < 4; k++)
//             {
//                 temp += ma[i][k] * mb[k][j];
//             }

//             matrix3[i][j] = temp;
//          printf("%d " ,matrix3[i][j]);
//     }
//    }

    
//     return 0;
// }
#include<stdio.h>
int main(){
    int A[4][4],B[4][4];
    int matrix3[4][4];
    
    for(int i=0;i<4;i++){
        printf(" please enter matrix A  row %d element",i+1);
        for(int j=0;j<4;j++){
          scanf("%d",&A[i][j]); 
        }
    }
    for(int i=0;i<4;i++){
        printf(" please enter matrix B  row %d element",i+1);
        for(int j=0;j<4;j++){
          scanf("%d",&B[i][j]); 
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int temp=0;
            for(int k=0;k<4;k++){
              temp+=A[i][k]*B[k][j];
               matrix3[i][j]=temp;
               
            }
            
        }
         
    }
 


return 0;
}