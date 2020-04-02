#include<stdio.h>
#include<stdlib.h>
struct Term
{
    int coeff;
    int exp;
};
struct Poly
{
  int n;
  struct Term *t;
};

void create(struct Poly *p)
{
    printf("ENTER NUMBER OF NON-ZERO TERM\n");
    scanf("%d",&p->n);
    p->t = (struct Term *) malloc(sizeof(struct Term)*p->n );
    printf("ENTER ALL NON-ZERO TERMS\n");
    for(int i=0;i<p->n;i++)
    {
        scanf("%d%d",&p->t[i].coeff,&p->t[i].exp);
    }
}
void display(struct Poly p)
{
    int i;
    for(i=0;i<p.n;i++)
    {
        printf("%dx^%d",p.t[i].coeff,p.t[i].exp);
        if(i<p.n-1){
            printf("+");
        }
    }
    printf("\n");
}
struct Poly *add(struct Poly p1,struct Poly p2){
    int i,j,k;
    i = 0;
    j = 0;
    k =0;
    struct Poly *sum =(struct Poly *) malloc(sizeof(struct Poly));
    sum->t  = (struct Term *) malloc(p1.n+p2.n*(sizeof(struct Term)));
    while(i<p1.n&&j<p2.n){
        if(p1.t[i].exp>p2.t[j].exp)
        {
            sum->t[k++] = p1.t[i++];
        }
        else if(p1.t[i].exp<p2.t[j].exp)
        {
            sum->t[k++] = p2.t[j++];
        }
        else{
            sum->t[k].exp = p1.t[i].exp;
            sum->t[k++] .coeff = p1.t[i++].coeff + p2.t[j++].coeff;
        }
    }
    for(;i<p1.n;i++){
        sum->t[k++] = p1.t[i];
    }
    for(;j<p2.n;j++){
        sum->t[k++] = p2.t[j];
    }
    sum->n = k;
    return sum;
}
int main()
{
    struct Poly p1,p2,*p3;
    create(&p1);
    create(&p2);
    p3 = add(p1,p2);
    printf("FIRST POLYNOMIAL\n");
    display(p1);
    printf("\n");
    printf("SECOND POLYNOMIAL\n");
    display(p2);
    printf("\n");
    printf("THIRD POLYNOMIAL\n");
    display(*p3);
    printf("\n");
    
    return 0;
}