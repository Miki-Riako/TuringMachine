#include "lib\Q3.h"
int main(void)
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
    complex num[3];
    char operation;
    num[0] = input();
    printf("Please enter an operator:\n");
    scanf(" %c", &operation);
    num[1] = input();
    num[2] = operate(num[0], num[1], operation);
    print(num, operation);
    printf("\nPress any key to exit.\n");
    char leave = _getch();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return 0;
}
