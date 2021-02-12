#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 50
int top=-1;
int stack[MAX];
void push();
int pop();
int match();
int check();
main()
{
    char exp[MAX];
    int valid;
    printf("enter en elgebraic expression");
    gets(exp);
    valid=check(exp);
    if(valid==1)
        printf("valid expression");
    else
        printf("invalid expression");
}
int check(char exp[MAX])
{
    int i;
    char item;
   for(i=0;i<strlen(exp);i++)
   {
       if(exp[i]=='(' || exp[i]=='{' || exp[i]=='[')
            push(exp[i]);
        if(exp[i]=')' || exp[i]=='}' || exp[i]==']')
            if(top=-1)
                return 0;
            else
            {
                item=pop();
                if(!match(exp[i],item))
                    return 0;
            }
   }
   if(top==-1)
    return 1;
   else
    return 0;
}
void push(char item)
{
    if(top==MAX-1)
    {
        printf("overflow condition");
        return;
    }
    top=top+1;
    stack[top]=item;


}
int pop()
{
    char item;
    if(top==-1)
    {
        printf("underflow condition");
        exit(1);
    }
    item=stack[top];
    top=top-1;
    return item;
}
int match(char a,char b)
{
    if(a=='[' && b==']')
        return 1;
    if(a=='{' && b=='}')
        return 1;
    if(a=='(' && b==')')
        return 1;
    return 0;
}






















