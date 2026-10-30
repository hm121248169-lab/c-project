#include <stdio.h>

#define MAXSIZE 100
int priority(char op)
{
    if(op == '(')
        return 0;
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    return -1;
}

int main()
{
    char stack[MAXSIZE];   
    int top = -1;         
    char ch;

  
    while(scanf("%c", &ch) == 1 && ch != '#')
    {
       
        if(ch >= 'A' && ch <= 'Z')
        {
            putchar(ch);
        }
       
        else if(ch == '(')
        {
            stack[++top] = ch;
        }
      
        else if(ch == ')')
        {
            while(stack[top] != '(')
            {
                putchar(stack[top--]);
            }
            top--;  
        }
     
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
        
            while(top != -1 && priority(stack[top]) >= priority(ch))
            {
                putchar(stack[top--]);
            }
            stack[++top] = ch;  
        }
    }
    
    while(top != -1)
    {
        putchar(stack[top--]);
    }
    printf("\n");
    return 0;
}
