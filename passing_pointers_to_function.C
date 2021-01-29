#include<stdio.h>

void funct1(int u, int v);
void funct2(int *pu, int *pv);

int main()
{
    int u = 1;
    int v = 3;

    printf("\nBefore calling funct1: u= %d    v= %d",u,v);
    funct1(u,v);
    printf("\nAfter calling funct1: u= %d    v= %d",u,v);

    printf("\nBefore calling funct2: u= %d\t v= %d",u,v);
    funct2(&u,&v);

    printf("\nAfter calling funct2: u= %d\t v= %d",u,v);
}

void funct1(int u, int v)
{
    u = 0;
    v = 0;
    printf("\nWithin funct1:\tu= %d\t v=%d",u,v);
    return;
}

void funct2(int *pu, int *pv)
{
    *pu = 0;
    *pv = 0;
    printf("\nWithin funct2:\t*pu= %d\t *pv= %d",*pu, *pv);
    return;
}