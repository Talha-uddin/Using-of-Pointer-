/*reorder a one-dimensional, integer array from smaller to larger
using a pointer*/

#include<stdio.h>
#include<stdlib.h>

void reorder(int n, int *x);

int main()
{
    int i,n,*x;

    printf("How many number will be entered? ");
    scanf("%d",&n);
    printf("\n");

    /*allocated memory*/
    x = (int *)malloc(n * sizeof(int));

    for(i=0; i<n; i++)
    {
        printf("i = %d\t x= ",i+1);
        scanf("%d",x+1);
    }

    reorder(n,x);

    printf("\nReordered list of numbers:\n\n");
    for(i=0; i<n; i++){
        printf("i = %d \t x = %d\n",i+1, *(x+1));
    }
}

void reorder(int n, int *x)
{
    int i,item,temp;

    for(item=0; item<n-1; ++item){
        for(i=item+1; i<n; ++i){
            if(*(x+i) < *(x+item)){
                temp = *(x+item);
                *(x+item) = *(x+i);
                *(x+i) = temp;
            }
        }
    }
    return;
}