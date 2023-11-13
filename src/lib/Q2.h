#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

#define MAXSIZE 64

typedef struct polynomial
{ // LinkList
    float coefficient;
    int Index;
    struct polynomial *next;
} polynomial;

void initialOutput(int term1, int term2)
{ // To tell the user what the polynomial seems like
    if (!(term1 > 0 && term2 > 0 && term1 <= 12 && term2 <= 12))
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Math Error!\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        exit(1);
    }
    char Letter1 = 'a';
    char Letter2 = 'A';
    printf("polynomials:\n(");
    for (int i = term1; i > 0; i--)
    {
        printf("%cx^%c",Letter1,Letter2);
        if (i != 1)
        {
            printf("+");
            Letter1++;
            Letter2++;
        }
        else printf(")+(");
    }
    Letter1 = 'z';
    Letter2 = 'Z';
    for (int i = term2; i > 0; i--)
    {
        printf("%cx^%c", Letter1, Letter2);
        if (i != 1)
        {
            printf("+");
            Letter1--;
            Letter2--;
        }
        else printf(")\n");
    }
}

void output(polynomial *p)
{ // Print a polynomial
    p = p->next;
    printf("(");
    while(p)
    {
        printf("%.0fx^%d", p->coefficient, p->Index);
        if (p->next)
        {
            printf("+");
        }
        p = p->next;
    }
    printf(")");
}

void createPolynomial(polynomial **p, int m)
{ // Create a polynomial
    int i;
    polynomial *cp, *temp;
    (*p) = (polynomial *)malloc(sizeof(polynomial));
    (*p)->coefficient = 0.0;
    (*p)->Index = -1;
    (*p)->next = NULL;
    for (i = 1; i <= m; ++i)
    {
        cp = *p;
        temp = (polynomial *)malloc(sizeof(polynomial));
        printf("Please enter the coefficient and index for item %d, separated by spaces:\n", i);
        scanf("%f", &temp->coefficient);
        scanf("%d", &temp->Index);
        while (cp->next && temp->Index > cp->next->Index)
        {
            cp = cp->next;
        }
        if (cp->next && temp->Index == cp->next->Index)
        {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("Error: The index is duplicated, and the input result will not appear in the equation.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
            continue;
        }
        temp->next = cp->next;
        cp->next = temp;
    }
}

void add(polynomial **pa, polynomial **pb)
{ // Add two polynomials
    polynomial *cpa, *cpb, *p = (*pa);
    cpa = (*pa)->next;
    cpb = (*pb)->next;
    while(cpa && cpb)
    {
        if(cpa->Index < cpb->Index)
        {
            p->next = cpa;
            p = cpa;
            cpa = cpa->next;
        }
        else if(cpa->Index > cpb->Index)
        {
            p->next = cpb;
            p = cpb;
            cpb = cpb->next;
        }
        else
        {
            if(cpa->coefficient + cpb->coefficient == 0)
            {
                cpa = cpa->next;
                cpb = cpb->next;
            }
            else
            {
                cpa->coefficient += cpb->coefficient;
                p->next = cpa;
                p = cpa;
                cpa = cpa->next;
                cpb = cpb->next;
            }
        }
    }
    if(cpa)
        p->next = cpa;
    else
        p->next = cpb;
    free(*pb);
}

void sub(polynomial **pa, polynomial **pb)
{ // Subtract two polynomials
    polynomial *cpa, *cpb, *p = (*pa);
    cpa = (*pa)->next;
    cpb = (*pb)->next;
    while(cpa && cpb)
    {
        if(cpa->Index < cpb->Index)
        {
            p->next = cpa;
            p = cpa;
            cpa = cpa->next;
        }
        else if(cpa->Index > cpb->Index)
        {
            p->next = cpb;
            p = cpb;
            p->coefficient *= -1;
            cpb = cpb->next;
        }
        else
        {
            if(cpa->coefficient == cpb->coefficient)
            {
                cpa = cpa->next;
                cpb = cpb->next;
            }
            else
            {
                cpa->coefficient -= cpb->coefficient;
                p->next = cpa;
                p = cpa;
                cpa = cpa->next;
                cpb = cpb->next;
            }
        }
    }
    if(cpa)
    {
        p->next = cpa;
    }
    if(cpb)
    {
        p->next = cpb;
        while(cpb){
            cpb->coefficient *= -1;
            cpb = cpb->next;
        }
    }
    free(*pb);
}

void copy(polynomial **pa, polynomial *pb)
{ // The function aims to help the multiplication function
    createPolynomial(pa, 0);
    polynomial *temp, *cpa;
    cpa = *pa;
    pb = pb->next;
    while(pb)
    {
        temp = (polynomial *)malloc(sizeof(polynomial));
        temp->coefficient = pb->coefficient;
        temp->Index = pb->Index;
        temp->next = NULL;
        cpa->next = temp;
        cpa = temp;
        pb = pb->next;
    }
}

void mulOperate(polynomial *pa, polynomial *pb)
{ // The function aims to help the multiplication function
    pa = pa->next;
    while(pa)
    {
        pa->coefficient *= pb->coefficient;
        pa->Index += pb->Index;
        pa = pa->next;
    }
}

void mul(polynomial **pa, polynomial **pb)
{ // Multiplicate two polynomial
    polynomial *cpa, *ccpa;
    cpa = *pa;
    createPolynomial(pa, 0);
    (*pb) = (*pb)->next;
    while (*pb)
    {
        copy(&ccpa, cpa);
        mulOperate(ccpa, *pb);
        add(pa, &ccpa);
        (*pb) = (*pb)->next;
    }
}

void print(polynomial *p)
{ // Print the final polynomial
    polynomial *temp = p->next;
    int a[MAXSIZE];
    double b[MAXSIZE];
    int aid = 0, bid = 0;
    int cnt = 0;
    while (temp)
    {
        if (cnt!=0&& temp->coefficient > 0)
        {
            printf("+");
        }
        b[bid] = temp->coefficient;
        a[aid] = temp->Index;
        printf("%.0fx^%d", b[bid], a[aid]);
        aid++;
        bid++;
        cnt++;
        temp = temp->next;
    }
    if (cnt == 0)
    {
        printf("0");
    }
    printf("\n");
}

void operate(polynomial **pa, polynomial **pb, char operation)
{ // Chose the operation
    switch (operation)
    {
        case '+':
            output(*pa);
            printf("+");
            output(*pb);
            add(pa, pb);
            break;
        case '-':
            output(*pa);
            printf("-");
            output(*pb);
            sub(pa, pb);
            break;
        case '*':
            output(*pa);
            printf("*");
            output(*pb);
            mul(pa, pb);
            break;
        case '/':
            printf("Not a polynomial!\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            exit(1);
        default:
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
            printf("Invalid operation!\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            exit(1);
    }
}
