#include <stdio.h>
int TOP = -1;
char STACK[20];
/*function to push an item into the stack */
void PUSH(char x)
{
    TOP++;
    STACK[TOP] = x;
}
/*function to pop an item from the stack */
char POP()
{
    char temp;
    temp = STACK[TOP];
    TOP--;
    return temp;
}
int PREC(char sym)
{
    int p;
    switch (sym)
    {
    case '^':
        p = 3;
        break;
    case '/':
    case '*':
        p = 2;
        break;
    case '+':
    case '-':
        p = 1;
        break;
    case '(':
    case ')':
        p = 0;
        break;
    case '#':
        p = -1;
        break;
    }
    return (p);
}

int main()
{
    char POST[25], INF[25], sym, temp;
    inti, pos = 0;
    printf("Enter a Infix expression \n");
    scanf("%s", INF);
    PUSH('#');
    /* length of the string POST*/
    intlen = 0;
    while (INF[len] != '\0')
        len++;
    for (i = 0; i < len; i++)
    {
        sym = INF[i];
        switch (sym)
        {
        case '(':
            PUSH(sym);
            break;
        case ')':
            temp = POP();
            while (temp != '(')
            {
                POST[pos++] = temp;
                temp = POP();
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (PREC(STACK[TOP]) >= PREC(sym))
            {
                temp = POP();
                POST[pos++] = temp;
            }
            PUSH(sym);
            break;
        default:
            POST[pos++] = sym;
            break;
        }
    }
    while (TOP > 0)
    {
        temp = POP();
        POST[pos++] = temp;
    }
    POST[pos] = '\0';
    printf("The Postfix Expression :  %s", POST);
    return 0;
}
