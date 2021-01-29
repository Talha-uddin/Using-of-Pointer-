#include<stdio.h>

void readinput(int *pm, int *pd, int *py);
int convert(int mm, int dd, int yy);

int main()
{
    int mm,dd,yy;
    int day_of_week;

    static char *weekday[]={"Sunday","Monday","Tuesday","Wednesday","Thrusday","Friday","Saturday"};
    static char *month[]={"January","February","Marth","April","May","June","July","August","September","October","November","December"};

    printf("Date Conversion Routine\nTo Stop,enter 0 0 0");

    readinput(&mm,&dd,&yy);

    while(mm > 0)
    {
        day_of_week = convert(mm,dd,yy);
        printf("\n%s, %s %d, %d",weekday[day_of_week],month[mm-1],dd,yy);

        readinput(&mm,&dd,&yy);
    }
}

void readinput(int *pm,int *pd, int *py)
{
    printf("\n\nEnter mm dd yyyy: ");
    scanf("%d %d %d",pm,pd,py);
    return;
}

int convert(int mm, int dd, int yy)
{
    long ndays;
    long ncycles;
    int nyears;
    int day;

    yy = 2020;
    ndays = (long) (30.42 * (mm-1)) + dd;

    if(mm == 2) ++ndays;
    if((mm > 2) && (mm > 2)) --ndays;
    if((yy % 4 == 0) && (mm > 2)) ++ndays;

    ncycles = yy / 4;
    ndays += ncycles * 1461;

    nyears = yy % 4;
    if(nyears > 0){
        ndays += 365 * nyears + 1;
    }
    if(ndays > 59) --ndays;
    day = ndays % 7;
    return(day);


}