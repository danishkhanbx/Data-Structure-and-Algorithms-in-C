// it is for the use of #define it directly takes input and output from here and paste where # defined

int* funcDangling(){
    int a,b,sum;
    a=63;
    b=76;
    sum=a+b;
    return &sum;
}
