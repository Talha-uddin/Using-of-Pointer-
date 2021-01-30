/*Personal Finance Calculation*/

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<math.h>

void table(double (*pf)(double i, int m,double n), double a, int m, double n);
double md1(double i, int m, double n);
double md2(double i, int m, double n);
double md3(double i, int m, double n);

int main()
{
    int m;
    double n;
    double a;
    char freq;

    printf("\nFuture VALUE OF A SERIES OF MONTHLY DEPOSITS\n\n");
    printf("Amount of each month payment: ");
    scanf("%f",&a);
    printf("Number of Year: ");
    scanf("%lf", &n);

    do
    {
        printf("Frequency of Compounding(A, S, Q, M, D, C): ");
        scanf("%1s",&freq);
        freq = toupper(freq);
        if(freq == 'A'){
            m = 1;
            printf("\nAnnual Compounding\n");
        }
        else if(freq == 'S'){
            m = 2;
            printf("\nSemiannual Compounding\n");
        }
        else if(freq == 'Q'){
            m = 4;
            printf("\nQuartarly Compounding\n");
        }
        else if(freq == 'M'){
            m = 12;
            printf("\nMonthly Compounding\n");
        }
        else if(freq == 'D'){
            m = 360;
            printf("\nDaily Compounding\n");
        }
        else if(freq == 'C'){
            m = 0;
            printf("\nContinous Compounding\n");
        }
        else
            printf("\nError - Please Repeat\n\n");
    } while (freq != 'A' && freq != 'S' && freq != 'Q' && freq != 'M' && freq != 'D' && freq != 'C');

    if(freq == 'C'){
        table(md3, a, m, n);
    }
    else if(freq == 'D'){
        table(md2,a, m, n);
    }
    else{
        table(md1, a, m ,n);
    }
}

void table(double (*pf)(double i, int m,double n),double a,int m,double n)
{
    int count;
    double i;
    double f;

    printf("\nInterest rate    Future Amount\n\n");
    for(count = 1; count <= 20; ++count){
        i = 0.01 * count;
        f = a * (*pf)(i,m,n);
        printf("\t %2d\t \t %.2f\n",count,f);
    }
    return;
}

double md1(double i, int m, double n)
{
    /*Monthly Deposit, Periodic Compounding*/
    double factor,ratio;

    factor = 1 + i/m;
    ratio = 12 * (pow(factor,m*n) - 1) / i;
    return(ratio);
}

double md2(double i, int m, double n)
{
    double factor,ratio;

    factor = 1 + i/m;
    ratio = (pow(factor,m*n) - 1) / (pow(factor, m/12) - 1);
    return(ratio);
}

double md3(double i,int m, double n)
{
    double ratio;

    ratio = (exp(i*n) - 1) / (exp(i/12) - 1);
    return(ratio);
}