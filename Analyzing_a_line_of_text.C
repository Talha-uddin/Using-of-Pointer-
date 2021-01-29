#include<stdio.h>
#include<ctype.h>

void scan_line(char line[],int *pv, int *pc, int *pd, int *pw, int *po);

int main(void)
{
    char line[80];
    int vowel = 0;
    int consonants = 0;
    int digits = 0;
    int whitespc = 0;
    int other = 0;

    printf("Enter a line of a text below:\n");
    scanf("%[^\n]", line);

    scan_line(line,&vowel,&consonants,&digits,&whitespc,&other);

    printf("\nNumber of Vowels: %d",vowel);
    printf("\nNumber of Consonants: %d",consonants);
    printf("\nNumber of digits: %d",digits);
    printf("\nNumber of Whitespc: %d",whitespc);
    printf("\nNumber of ohter character: %d",other);
}


void scan_line(char line[],int *pv, int *pc, int *pd, int *pw, int *po)
{
    char c;
    int count = 0;
    while((c = toupper(line[count]))  != '\0'){
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'){
            ++*pv;
        }
        else if(c >= 'A' && c<= 'Z'){
            ++*pc;
        }
        else if(c >= '0' && c <= '9'){
            ++*pd;
        }
        else if(c == ' ' || c == '\t'){
            ++*pw;
        }
        else{
            ++*po;
        }
    count++;
    }
    return;
}
