#include<stdio.h>

int main()
{
    int *px;
    int i = 1;
    float f = 0.3;
    double d = 0.005;;
    char c = '*';

    px = &i;

    printf("Values: i = %i\t f=%f\t d=%f\t c=%c\n\n",i,f,d,c);
    printf("Addresses: &i=%X\t &f=%X\t &d=%X\t &c=%X\n\n",&i,&f,&d,&c);
    printf("Pointer values: px=%X\t px + 1=%X\t px + 2=%X\t px + 3=%X\t",px,px+1,px+2,px+3);
}