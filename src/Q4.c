#include "lib\Q4.h"
int main(void)
{
    for (bool flag = true; flag; continueProgram(&flag))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        system("cls");
        printf("Welcome to the infix to postfix calculator!\n\n");
        char postfix[MAXSIZE];
        printf("Please enter the infix expression: ");
        char *infix = getString();
        if (infix == NULL)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            printf("Syntax error!\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        }
        else
        {
            printInfix(infix);
            infixToPostfix(infix, postfix);
            printf("Suffix expression: %s\n", postfix);
            calculatePostfix(postfix);
        }
        free(infix);
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return 0;
}
