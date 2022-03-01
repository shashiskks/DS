#include <stdio.h>
int STACK[20], TOP = -1;
void push(int item)
{
    TOP++;
    STACK[TOP] = item;
}
int pop()
{
    int item;
    item = STACK[TOP];
    TOP--;
    return item;
}
main()
{
    char POST[25], sym;
    int op1, op2, i;
    printf("\n ________________________________");
    printf("\n EVALUATION OF POSTFIX EXPRESSION");
    printf("\n --------------------------------");
    printf("\n Enter Postfix expression: ");
    scanf("%s", POST);
    // printf("%d",'0');
    /* length of the string POST*/
    int len = 0;
    while (POST[len] != '\0')
        len++;
    for (i = 0; i < len; i++)
    {
        sym = POST[i];
        switch (sym)
        {
        case '+':
            op2 = pop();
            op1 = pop();
            push(op1 + op2);
            break;
        case '-':
            op2 = pop();
            op1 = pop();
            push(op1 - op2);
            break;
        case '*':
            op2 = pop();
            op1 = pop();
            push(op1 * op2);
            break;
        case '/':
            op2 = pop();
            op1 = pop();
            push(op1 / op2);
            break;
        case '^':
            op2 = pop();
            op1 = pop();
            push(op1 ^ op2);
            break;
        default:
            push(sym - '0');
            break;
        }
    }
    printf("\n The value for the given postfix expression %d", pop());
}
