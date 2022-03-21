/* Aim : nxn matrix addition
   Author : Danish Khan */
#include <stdio.h>

void scan_array(int a[][20],int n){
    int i,j;
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("Element %d,%d:",i,j);
            scanf("%d", &a[i][j]);
        }
    }
}

void add_array(int x[][20],int y[][20],int sum[][20],int n){
    int i,j;
     for(i=0;i<n;i++){
        for(j=0;j<n;j++){
           sum[i][j]= x[i][j] + y[i][j];
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
    int a[20][20],b[20][20],n,sum[20][20],i,j;

    printf("Enter n:");
    scanf("%d", &n);

    printf("Enter First array:");
    scan_array(a,n);

    printf("\nEnter Second array:\n");
    scan_array(b,n);

    add_array(a,b,sum,n);

    print_array(a,n);
    printf("\t +\n");
    print_array(b,n);
    printf("\t =\n");
    print_array(sum,n);



    return 0;
}

