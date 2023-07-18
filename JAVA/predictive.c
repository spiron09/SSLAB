#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char prod[3][10] = {"A->aBa", "B->bB", "B->@"};
char input[10];
char stack[25];
int top = -1;
void push(char item) { stack[++top] = item; }
void pop() { top--; }
void display()
{
    for (int i = 0; i <= top; i++)
        printf("%c", stack[i]);
}

void stackpush(char p)
{
    if (p == 'A')
    {
        pop();
        for (int j = strlen(prod[0]) - 1; j >= 3; j--)
            push(prod[0][j]);
    }
    else
    {
        pop();
        for (int j = strlen(prod[1]) - 1; j >= 3; j--)
            push(prod[1][j]);
    }
}
void validateInputString()
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if ((input[i] != 'a') && (input[i] != 'b') && (input[i] != '$'))
        {
            printf("Invalid string");
            exit(0);
        }
    }
    if (input[strlen(input) - 1] != '$')
    {
        printf("Input string entered without end marker $\n");
        exit(0);
    }
}

void parseInputString()
{
    push('$');
    push('A');
    int i = 0;
    printf("\n\nStack\tInput\tAction\n---------\n");
    while (i != strlen(input) && stack[top] != '$')
    {
        printf("\n");
        display();
        printf("\t%s\t", input+i);
        if (stack[top] == 'A')
        {
            printf("A->aBa");
            stackpush('A');
        }
        else if (stack[top] == 'B')
        {
            if (input[i] != 'b')
            {
                printf("\tmatched @");
                pop();
            }
            else
            {
                printf("B->bB");
                stackpush('B');
            }
        }
        else
        {
            if (stack[top] == input[i])
            {
                printf("\tmatched %c", input[i]);
                pop();
                i++;
            }
            else
            {
                break;
            }
        }
    }
    if (stack[top] == '$' && input[i] == '$')
        printf("\n$\t$\nValid string Accepted\n");
    else
        printf("\nInvalid string rejected\n");
}

int main()
{
    printf("Grammar:\nA->aBa\nB->bB\nB->@\n\n");
    printf("First = {a,b,@}\n");
    printf("Follow = {$,a,a}\n\n");
    printf("\ta\tb\t$\n");
    printf("A\t%s\n", prod[0]);
    printf("B\t%s\t%s\n\n", prod[2], prod[1]);
    printf("Input string: ");
    scanf("%s", input);
    validateInputString();
    parseInputString();
    return 0;
}