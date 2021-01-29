#include<stdio.h>

char x[] = "This string is declared externally\n\n";

int main()
{
    static char y[] = "This string is declared within main";

    printf("%s",x);
    printf("%s",y);
}