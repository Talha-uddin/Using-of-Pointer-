#include<stdio.h>

int main()
{
    static int x[10] = {10,11,12,13,14,15,16,17,18,19};
    int i;

    for(i=0; i<=9; ++i)
    {
        printf("\ni= %d \t x[i]= %d \t *(x+i)= %d",i,x[i], *(x+i));

        /*display the corresponding array address*/
        printf("\t *x[i]= %x \t x+i= %x",&x[i], (x+i));
    }
}