#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int ssn;
    char name[100], dept[100], desg[100];
    float phnum, sal;
    struct node *next;
};
typedef struct node *NODE;
NODE start = NULL;
int count = 0;
void insertatlast()
{
    NODE snode, temp;
    snode = (NODE)malloc(sizeof(NODE));
    printf("enter ssn,name,dept,desg,sal,phnum");
    scanf("%d%s%s%s%f%f", &snode->ssn, snode->name, snode->dept, snode->desg, &snode->sal, &snode->phnum);
    snode->prev = NULL;
    snode->next = NULL;
    if (snode == NULL)
        printf("error");
    if (start == NULL)
        start = snode;
    else
    {
        temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = snode;
        snode->prev = temp;
    }
    count++;
}
void insertatfront()
{
    NODE snode, cur;
    snode = (NODE)malloc(sizeof(NODE));
    printf("enter ssn,name,dept,desg,sal,phnum");
    scanf("%d%s%s%s%f%f", &snode->ssn, snode->name, snode->dept, snode->desg, &snode->sal, &snode->phnum);
    snode->next = NULL;
    snode->prev = NULL;
    if (snode == NULL)
        printf("error");
    if (start == NULL)
        start = snode;
    else
    {
        snode->next = start;
        start->prev = snode;
        start = snode;
    }
    count++;
}
void deleteatend()
{
    NODE temp, prev;
    if (start == NULL)
        printf("no elments");
    if (start->next == NULL)
    {
        free(start);
        count--;
    }
    else
    {
        temp = start;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        free(temp);
        prev->next = NULL;
        count--;
    }
}
void deleteatfront()
{
    NODE temp;
    if (start == NULL)
        printf("no elements in list");
    else if (start->next == NULL)
    {
        free(start);
        count--;
    }

    else
    {
        temp = start;
        start = start->next;
        start->prev = NULL;
        free(temp);
        count--;
    }
}
void display()
{
    NODE temp;
    temp = start;
    printf("number of elemnts in list %d", count);
    while (temp != NULL)
    {
        printf("%d%s%s%s%f%f", temp->ssn, temp->name, temp->dept, temp->desg, temp->sal, temp->phnum);
        temp = temp->next;
    }
}
void dequeuedemo()
{
    int ch;
    printf(“enter ch”);
    scanf(“% d”, &ch);
    switch (ch)
    {
    case 1:
        insertatlast();
        break;
    case 2:
        insertatfront();
        break;
    case 3:
        deleteatend();
        break;
    case 4:
        deleteatfront();
        break;
    case 5:
        return;
    }
}
main()
{
    int ch;
    while (1)
    {
        printf("enter ch");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertatlast();
            break;
        case 2:
            insertatfront();
            break;
        case 3:
            deleteatend();
            break;
        case 4:
            deleteatfront();
            break;
        case 5:
            display();
            break;
        case 6:
            dequeuedemo();
            break;
        default:
            printf("invalid choice");
        }
    }
}
