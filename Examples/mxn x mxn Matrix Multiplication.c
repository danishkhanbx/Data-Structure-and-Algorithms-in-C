/* Aim : mxn*mxn Matrix Multiplication
   Author : Danish Khan */
#include <stdio.h>
void scan_array(int a[][20],int n){
    int i,j;
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                printf("%d,%d:",i,j);
            scanf("%d", &a[i][j]);
        }
    }
}

void mul_array(int x[][20],int y[][20],int mul[][20],int n){
    int i,j,k;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
                mul[i][j]=0;
                for(k=0;k<n;k++){
                        mul[i][j]+= x[i][k]*y[k][j]; //Remember this Formula
            }
        }
    }
}

void print_array(int a[][20], int n){
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
          printf("%d  ", a[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int a[20][20],b[20][20],n,mul[20][20];

    printf("Enter n:");
    scanf("%d", &n);

    printf("Enter First Matrix:\n");
    scan_array(a,n);

    printf("\nEnter Second Matrix:\n");
    scan_array(b,n);

    mul_array(a,b,mul,n);

    print_array(a,n);
    printf("\t *\n");
    print_array(b,n);
    printf("\t =\n");
    print_array(mul,n);

    return 0;
}

