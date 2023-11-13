#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAXSIZE 100

typedef struct Stack
{                       // Stack
    char data[MAXSIZE]; // Stack data
    int top;            // Stack top pointer
} Stack;

typedef struct DoubleStack
{                         // Double Stack
    double data[MAXSIZE]; // Stack data storing double float
    int top;              // Stack top pointer
} DoubleStack;

void initialize(Stack *stack)
{ // Initialize stack
    stack->top = -1;
}
void initializeDouble(DoubleStack *stack)
{ // Initialize stack
    stack->top = -1;
}

void push(Stack *stack, char item)
{ // Push into stack
    if (stack->top < MAXSIZE - 1)
        stack->data[++stack->top] = item;
}
void pushDouble(DoubleStack *stack, double item)
{ // Push into stack
    if (stack->top < MAXSIZE - 1)
        stack->data[++stack->top] = item;
}

char pop(Stack *stack)
{ // Pop from stack
    if (stack->top >= 0)
        return stack->data[stack->top--];
    return '\0';
}

double popDouble(DoubleStack *stack)
{ // Pop from stack
    if (stack->top >= 0)
        return stack->data[stack->top--];
    return 0.0;
}

char top(Stack *stack)
{ // Get the top character
    if (stack->top >= 0)
        return stack->data[stack->top];
    return '\0';
}
double topDouble(DoubleStack *stack)
{ // Get the top double
    if (stack->top >= 0)
        return stack->data[stack->top];
    return 0.0;
}

char *getString(void)
{ // Get a string from the user
    char *str = NULL;
    int len = 0;
    int chara;
    while ((chara = getchar()) != '\n' && chara != EOF)
    {
        if (isdigit(chara) || (chara >= '(' && chara <= '+') || (chara >= '-' && chara <= '/'))
        {
            str = (char *)realloc(str, len + 2);
            if (str == NULL)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("Memory allocation error!\n");
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                exit(1);
            }
            str[len++] = chara;
            str[len] = '\0';
        }
    }
    return str;
}

void printInfix(char *str)
{ // Print the infix expression
    printf("Your infix expression: ");
    for (int i = 0; i < strlen(str); i++)
        printf("%c", str[i]);
    printf("\n");
}

void continueProgram(bool *flag)
{ // Check whether to continue the program
    printf("\nPress Enter to continue, press any other key to leave . . .\n");
    char leave = _getch();
    if (leave == 13)
        *flag = true;
    else
        *flag = false;
}

int precedence(char op)
{ // Check operator priority
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

void infixToPostfix(char *infix, char *postfix)
{ // Convert infix expression to suffix expression
    Stack stack;
    initialize(&stack);
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    { // Traverse every character
        if (isdigit(infix[i]) || infix[i] == '.')
        {
            postfix[j++] = infix[i++];
            while (isdigit(infix[i]) || infix[i] == '.')
                postfix[j++] = infix[i++];
            postfix[j++] = ' ';
        }
        else if (infix[i] == '(')
        {
            push(&stack, infix[i]);
            i++;
        }
        else if (infix[i] == ')')
        {
            while (top(&stack) != '(')
            {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            pop(&stack);
            i++;
        }
        else
        {
            while (precedence(infix[i]) <= precedence(top(&stack)) && top(&stack) != '\0')
            {
                postfix[j++] = pop(&stack);
                postfix[j++] = ' ';
            }
            push(&stack, infix[i]);
            i++;
        }
    }
    while (top(&stack) != '\0')
    { // If there are stack data remained, pop them all.
        postfix[j++] = pop(&stack);
        postfix[j++] = ' ';
    }
    postfix[j] = '\0';
}

void calculatePostfix(char *postfix)
{ // Calculate the postfix expression
    DoubleStack stack;
    initializeDouble(&stack);
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (isdigit(postfix[i]) || postfix[i] == '.')
        {
            int j = 0;
            char num[MAXSIZE];
            while (isdigit(postfix[i]) || postfix[i] == '.')
                num[j++] = postfix[i++];
            num[j] = '\0';
            pushDouble(&stack, atof(num));
        }
        else if (postfix[i] != ' ')
        {
            double b = popDouble(&stack);
            double a = popDouble(&stack);
            switch (postfix[i])
            {
            case '+':
                pushDouble(&stack, a + b);
                break;
            case '-':
                pushDouble(&stack, a - b);
                break;
            case '*':
                pushDouble(&stack, a * b);
                break;
            case '/':
                if (b == 0)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    printf("Math error!\n");
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
                    return;
                }
                pushDouble(&stack, a / b);
                break;
            }
            i++;
        }
        else
            i++;
    }
    printf("Calculation results: %.2lf\n", popDouble(&stack));
    return;
}
