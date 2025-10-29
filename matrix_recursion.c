#include<stdio.h>
void add(int n,int A[n][n],int B[n][n],int C[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j]=A[i][j]+B[i][j];
        }
    }
}
void matmax(int n,int A[n][n],int B[n][n],int C[n][n]){
    if(n==1){
        C[0][0]=A[0][0]*B[0][0];
    return;
    }
    int newsize=n/2;
    int A11[newsize][newsize],A12[newsize][newsize],A21[newsize][newsize],A22[newsize][newsize];
    int B11[newsize][newsize],B12[newsize][newsize],B21[newsize][newsize],B22[newsize][newsize];
    int C11[newsize][newsize],C12[newsize][newsize],C21[newsize][newsize],C22[newsize][newsize];
    int M1[newsize][newsize],M2[newsize][newsize];

    for(int i=0;i<newsize;i++){
        for(int j=0;j<newsize;j++){
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j+newsize];
            A21[i][j]=A[i+newsize][j];
            A22[i][j]=A[i+newsize][j+newsize];

             B11[i][j]=B[i][j];
            B12[i][j]=B[i][j+newsize];
            B21[i][j]=B[i+newsize][j];
            B22[i][j]=B[i+newsize][j+newsize];

        }
    }
    
    matmax(newsize,A11,B11,M1);
    matmax(newsize,A12,B21,M2);
    add(newsize,M1,M2,C11);

    matmax(newsize,A11,B12,M1);
    matmax(newsize,A12,B22,M2);
    add(newsize,M1,M2,C12);

    matmax(newsize,A21,B11,M1);
    matmax(newsize,A22,B21,M2);
    add(newsize,M1,M2,C21);

    matmax(newsize,A21,B12,M1);
    matmax(newsize,A22,B22,M2);
    add(newsize,M1,M2,C22);
    for(int i=0;i<newsize;i++){
        for(int j=0;j<newsize;j++){
          C[i][j]=C11[i][j];  
          C[i][j+newsize]=C12[i][j];
          C[i+newsize][j]=C21[i][j];
          C[i+newsize][j+newsize]=C22[i][j];
        
        }
    }

}
int main(){
int n=4;
int A[4][4]={{1,2,3,4},{4,5,6,7},{8,9,1,3},{5,6,7,8}};
int B[4][4]={{1,2,3,4},{4,5,6,7},{8,9,1,3},{5,6,7,8}};
int C[n][n];
matmax(n,A,B,C);
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        printf("%d  ",C[i][j]);
    }
}

    return 0;
}