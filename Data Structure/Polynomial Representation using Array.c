/* Aim: Representation, Addition(of two), and Evaluation of POLYNOMIALS using Array
   Author: Danish Khan
           |p|
            |
            |                                      k
structure- ___ Poly                                | 0   1    2    3
     n    |___|                                  _____________________
    terms |___|--------------------->Term: coeff | i0 | i1 | i2 | i3 |
                                            exp  | j0 | j1 | j2 | j3 |
                                                 |___________________|
e.g. of Output(Input) = Term: 4----->number of non-zero terms
       Coefficient<-----2 3------>Exponent                      coeff | 2 | 4 | 1 | 8 |
                        4 2                                      exp  | 3 | 2 | 1 | 0 |
                        1 1
                        8 0
         Output: 2x3 + 4x2 + 1x1 + 8x0
         when x=1 Evaluate :  2*1^3 + 4*1^2  + 1*1^1 + 8*1^0 = 2 + 4 + 1 + 8 = 15

*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void create();
struct Poly *add();
void display();
long Evaluate();

struct Poly
{
    int n;                //  n = total number of non-zero elements there will be
    struct Term *terms;  // terms is a pointer to structure of 2D-Array Term
};

struct Term
{
    int coeff;
    int exp;
};

int main()
{
    struct Poly p1, p2, *p3;

    create(&p1);
    create(&p2);

    p3 = add(&p1,&p2);    // p3 will now point to sum

    printf("\n");
    display(p1);

    printf("\n");
    display(p2);

    printf("\n");
    display(*p3);  // *p3 points to sum, so in other words if we print *p3 it will print the values in sum

    printf("\n%ld\n",Evaluate(*p3,1)); // passing the address of sum & value of x, if it is p1 or p2 we will just pass p1 or p2 as it is and make the necessary changes in Evaluate function

    return 0;
}

void create(struct Poly *p)                                        // pointer p is passed which points to structure-poly
{
    printf("Number of terms: ");
    scanf("%d",&p->n);                                           // it will access int n in struct poly & save the number x
    p->terms = (struct Term *)malloc(p->n*sizeof(struct Term)); // this will create 2 row for coeff & expo, and x columns(starting from 0) array

    printf("Enter terms\n");
    for(int i=0; i<p->n; i++)
        scanf("%d%d",&p->terms[i].coeff, &p->terms[i].exp);

}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{
    struct Poly *sum;
    int i,j,k;

    sum = (struct Poly *)malloc(sizeof(struct Poly));
    sum->terms = (struct Term *)malloc((p1->n+p2->n)*sizeof(struct Term)); // it will create a 2D-Array of 2 row & n(of p1) + n(of p2) columns

    i=j=k=0;                                                             // i will point to p1 index 0, j will point to p2 index 0, & k will point to sum index 0

    while(i<p1->n && j<p2->n)                     // when either one of the structure(p1 or p2) reaches their 2D-Array end, means no addition is remaining, then we stop the loop
    {                                            // Polynomial addition takes placed when the exponent of the n terms are same
        if(p1->terms[i].exp > p2->terms[j].exp) // if exponent of p1 is bigger than p2 then we copy p1(i=index 0) in sum (k=index 0) then we increment i & k to index 1
            sum->terms[k++] = p1->terms[i++];
        else if(p1->terms[i].exp < p2->terms[j].exp)  // if exponent of p2 is bigger than p1 then we copy p2(j=index 0) in sum (k=index 0) then we increment j & k to index 1
            sum->terms[k++] = p2->terms[j++];
        else                                        // if exponent of p1 is equal to p2 then we copy exponent of p1(i=index 0) or p2(j=index 0) in sum(k=index 0) and
        {                                          // then we add coefficient values of p1&p2 then we copy the values of p1(i=index 0) + p2(j=index 0) in sum(k=index 0) and
            sum->terms[k].exp = p1->terms[i].exp; // then we increment i,j & k to index 1
            sum->terms[k++].coeff = p1->terms[i++].coeff + p2->terms[j++].coeff;
        }
    }
     // when either one of the polynomial ended we copy the rest of remaining(either p1 or p2) polynomial in sum
    for(; i<p1->n; i++)
        sum->terms[k++] = p1->terms[i];
    for(; j<p2->n; j++)
        sum->terms[k++] = p2->terms[j];

    sum->n = k;   // k will have the absolute number of how many terms are there in sum

    return sum; // returning sum's address
}

void display(struct Poly p)
{
    for(int i=0; i<p.n; i++)
        printf("%dx^%d+",p.terms[i].coeff, p.terms[i].exp); // p->terms->coeff[i] & p->terms->exp[i], where i is from 0 to n-1
    printf("\n");
}

long Evaluate(struct Poly p,int x)  // we are passing the polynomial(e.g. 2x3 + 4x2 + 1x1 + 8x0) & the value of x, we substitute the value of x in the equation & then solve the equation
{
    long val=0;                                         // if p1 or p2 is passed then the changes will be Evaluate(struct Poly *p,int x)
    for(int i=0; i<p.n; i++)                           // i < p->n
    {
        val+=p.terms[i].coeff*pow(x,p.terms[i].exp); //  p->terms[i].coeff * pow(x,p->terms[i].exp)
    }
    return val;
}
