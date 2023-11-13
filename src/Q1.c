#include "lib\Q1.h"
int main(void)
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
    printf("Enter a string: \n");
    char *arrA = getString();
    printf("Enter a string: \n");
    char *arrB = getString();
    show(arrA, arrB);
    printf("\nPress any key to exit.\n");
    char leave = _getch();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return 0;
}
