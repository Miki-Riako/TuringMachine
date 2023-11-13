#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <conio.h>

typedef struct complex
{ // Complex number
    double real;
    double imag;
} complex;

complex input(void)
{ // Get a complex number
    complex c;
    printf("Enter the real and imaginary parts of the complex number, separated by spaces:\n");
    scanf("%lf %lf", &c.real, &c.imag);
    return c;
}

void output(complex c)
{ // Calculate and output the complex number
    if (c.imag > 0)
    {
        printf("(%.2f+%.2fi)", c.real, c.imag);
    }
    else if (c.imag < 0)
    {
        printf("(%.2f-%.2fi)", c.real, -c.imag);
    }
    else
    {
        printf("(%.2f)", c.real);
    }
}

void print(complex num[3], char operation)
{ // Print the complex number
    printf("Result:\n");
    output(num[0]);
    printf("%c", operation);
    output(num[1]);
    printf("=");
    output(num[2]);
    printf("\n");
}

complex add(complex a, complex b)
{ // Add two complex numbers
    complex c;
    c.real = a.real + b.real;
    c.imag = a.imag + b.imag;
    return c;
}

complex sub(complex a, complex b)
{ // Subtract two numbers
    complex c;
    c.real = a.real - b.real;
    c.imag = a.imag - b.imag;
    return c;
}

complex mul(complex a, complex b)
{ // Multiply two complex numbers
    complex c;
    c.real = a.real * b.real - a.imag * b.imag;
    c.imag = a.real * b.imag + a.imag * b.real;
    return c;
}

complex divide(complex a, complex b)
{ // Divide two complex numbers
    complex c;
    double m = b.real * b.real + b.imag * b.imag;
    if (m == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Math Error!\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        return a;
    }
    c.real = (a.real * b.real + a.imag * b.imag) / m;
    c.imag = (a.imag * b.real - a.real * b.imag) / m;
    return c;
}

complex operate(complex numA, complex numB, char operation)
{ // Chose the operation
    complex output;
    switch (operation)
    {
        case '+':
            output = add(numA, numB);
            break;
        case '-':
            output = sub(numA, numB);
            break;
        case '*':
            output = mul(numA, numB);
            break;
        case '/':
            output = divide(numA, numB);
            break;
        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("Invalid operation!\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            exit(1);
    }
    return output;
}
