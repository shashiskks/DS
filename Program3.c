#include <stdio.h>
struct bank_customer
{
    char name[20];
    char accno[50];
    float bal;
} s[3];
void printlessthan200(struct bank_customer s);
void add100(struct bank_customer s);
void display(struct bank_customer s);
int main()
{
    int i;
    for (i = 0; i < 3; i++)
    {
        scanf("%s%f%s", s[i].name, &s[i].bal, s[i].accno);
    }
    printlessthan200(s);
    add100(s);
    return 0;
}
void printlessthan200(struct bank_customer s[])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (s[i].bal < 200)
        {
            printf("\nless than 200 %s", s[i].name);
        }
    }
}
void add100(struct bank_customer s[])
{
    int i;
    for (i = 0; i < 3; i++)
    {
        if (s[i].bal > 1000)
        {
            s[i].bal = s[i].bal + 100;
        }
    }
    display(s);
}
void display(struct bank_customer s[])
{
    int i;

    for (i = 0; i < 3; i++)
    {
        printf("\n%3s %3s %3f", s[i].name, s[i].accno, s[i].bal);
    }
}
