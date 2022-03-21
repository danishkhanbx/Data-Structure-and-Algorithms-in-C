/* Aim : 3x3 matrix Determinant
   Author : Danish Khan */
#include <stdio.h>
void scan_array(int a[][20]){
    int i,j;
     for(i=0;i<3;i++){
        for(j=0;j<3;j++){
                printf("%d,%d:",i,j);
            scanf("%d", &a[i][j]);
        }
    }
}

int calc_determinant(int x[][20]){
    int i,j,det;
    det=x[0][0]*(x[1][1]*x[2][2]-x[1][2]*x[2][1])-
        x[0][1]*(x[1][0]*x[2][2]-x[1][2]*x[2][0])+
        x[0][2]*(x[1][1]*x[2][1]-x[1][1]*x[2][0]);
     return det;
}


int main(){
    int a[20][20],det,i,j;


    printf("Enter First array:\n");
    scan_array(a);

    det =calc_determinant(a);
    printf("Determinant: %d", det);

    return 0;
}

