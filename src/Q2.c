#include "lib\Q2.h"

int main(void)
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    polynomial *pa, *pb;
    int term1, term2;
    char operation;
    printf("Please enter the number of terms for two polynomials to be calculated, separated by spaces:\n");
    scanf("%d %d", &term1, &term2);
    initialOutput(term1, term2);
    printf("Polynomial one:\n");
    createPolynomial(&pa, term1);
    printf("Polynomial two:\n");
    createPolynomial(&pb, term2);
    printf("\nPlease enter an operator:\n");
    scanf(" %c", &operation);
    printf("\nCalculation formula:\n");
    operate(&pa, &pb, operation);
    printf("\nResult:\n");
    print(pa);
    printf("\nPress any key to exit.\n");
    char leave = _getch();
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    return 0;
}
