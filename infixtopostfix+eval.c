#include<stdio.h>
#include<ctype.h>
char stack[100],postfix[10],infix[10];
int top=-1;
int main()
{
    int choice;
    while(1)
    {
    printf("\n\n1: convert an infix expression to a postfix expression\n2: evaluate a suffix expression\n\nenter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: conversion(); break;
        case 2: evaluate(); break;
        default: printf("invalid choose again: ");
    }
}
}
void push(char element)
{
    top++;
    stack[top] = element;

}
int pop()
{
    top--;
    return stack[top+1];
}
int priority(char c)
{

        if(c=='#') return (0);
        else if(c=='(') return (1);
        else if(c=='+' || c=='-') return (2);
        else if(c=='/'|| c=='%'|| c=='*') return (3);
        else if(c=='^') return (4);


}
void conversion()
{

    printf("input the infix expression:");
    scanf("%s",infix);
    push('#');
    int j=0; int i;
    for(i=0;infix[i]!='\0';i++)
    {
        if(isalnum(infix[i]))
            postfix[j++] = infix[i];

        else if(infix[i]=='(')
            push(infix[i]);

        else if(infix[i]==')')
        {
            while(stack[top]!='(')
            {
                postfix[j++] = pop();
            }
            top--;
        }
        else
        {
            while((priority(infix[i]))<=(priority(stack[top])))
             {
                 postfix[j++] = pop();
             }
            push(infix[i]);
        }
    }
    while(stack[top]!='#')
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("\nInfix expression: %s",infix);
    printf("\nPostfix expression: %s",postfix);
}

void evaluate()
{
    char suffix[100]; int i;
    printf("enter the expression to be evaluated:");
    scanf("%s",suffix);

    for(i=0;suffix[i]!='\0';i++)
    {
        switch(suffix[i])
        {
            case '1' ... '9': push(suffix[i] - '0'); break;
            case '*': case '/': case '^': case '%': case '-': case '+':
                {
                    char op = suffix[i];
                    int a = pop();
                    int b = pop();
                    printf("called");
                    if(op=='*') push(b*a);
                    if(op=='/') push(b/a);
                    if(op=='^') push(b^a);
                    if(op=='%') push(b%a);
                    if(op=='-') push(b-a);
                    if(op=='+') push(b+a);
                } break;
        }
    }
    printf("postfix/suffix expression: %s",suffix);
    printf("\nevaluated postfix expression: %d",stack[top]);
}
