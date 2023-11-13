#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

int strlenPlus(char *str)
{ // A fuction to avoid the setback of "strlen" which can not cope with the null pointer
    int len = 0;
    if (str != NULL)
    {
        len = strlen(str);
    }
    return len;
}

void output(char arr[])
{ // The fuction aims to output the array.
    int len = strlenPlus(arr);
    if (len == 0)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Empty-set\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
        return;
    }
    printf("{");
    for (int i = 0; i < len; i++)
    {
        printf(" %c ", arr[i]);
    }
    printf("}\n");
}

void check(char *ptr)
{ // Check whether the memory is overflowed
    if (ptr == NULL)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        printf("Memory allocation error!\n");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        exit(1);
    }
}

char *getString(void)
{ // Get a string from the user
    char *str = NULL;
    int len = 0;
    int chara;
    while ((chara = getchar()) != '\n' && chara != EOF)
    {
        str = (char *)realloc(str, len + 2);
        check(str);
        str[len++] = chara;
        str[len] = '\0';
    }
    return str;
}

char *unionArr(char arrA[], char arrB[])
{ // Get the union array between the two arrays
    int lenA = strlenPlus(arrA);
    int lenB = strlenPlus(arrB);
    char *newArr = NULL;
    int len = 0;
    for (int i = 0; i < lenA; i++)
    {
        newArr = (char *)realloc(newArr, len + 2);
        check(newArr);
        newArr[len++] = arrA[i];
    }
    for (int i = 0; i < lenB; i++)
    {
        int flag = 0;
        for (int j = 0; j < len; j++)
        {
            if (arrB[i] == newArr[j])
            {
                flag = 1;
                break;
            }
        }
        if (flag)
        {
            continue;
        }
        else
        {
            newArr = (char *)realloc(newArr, len + 2);
            check(newArr);
            newArr[len++] = arrB[i];
        }
    }
    if (newArr != NULL)
    {
        newArr[len] = '\0';
    }
    return newArr;
}

char *intersectionArr(char arrA[], char arrB[])
{ // Get the intersection array between the two arrays
    int lenA = strlenPlus(arrA);
    int lenB = strlenPlus(arrB);
    char *newArr = NULL;
    int len = 0;
    for (int i = 0; i < lenA; i++)
    {
        for (int j = 0; j < lenB; j++)
        {
            if (arrA[i] == arrB[j])
            {
                newArr = (char *)realloc(newArr, len + 2);
                check(newArr);
                newArr[len++] = arrA[i];
            }
        }
    }
    if (newArr != NULL)
    {
        newArr[len] = '\0';
    }
    return newArr;
}

char *subtractionArr(char arrA[], char arrB[])
{ // Get the subtraction array between the two arrays
    int lenA = strlenPlus(arrA);
    int lenB = strlenPlus(arrB);
    char *newArr = NULL;
    int len = 0;
    for (int i = 0; i < lenA; i++)
    {
        int flag = 0;
        for (int j = 0; j < lenB; j++)
        {
            if (arrA[i] == arrB[j])
            {
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            newArr = (char *)realloc(newArr, len + 2);
            check(newArr);
            newArr[len++] = arrA[i];
        }
    }
    if (newArr != NULL)
    {
        newArr[len] = '\0';
    }
    return newArr;
}

void show(char arrA[], char arrB[])
{ // To show the three kinds of arrays
    printf("\nunion:\n");
    char *unionArray = unionArr(arrA, arrB);
    output(unionArray);
    printf("\nintersection:\n");
    char *intersectionArray = intersectionArr(arrA, arrB);
    output(intersectionArray);
    printf("\nsubtraction:\n");
    char *subtractionArray = subtractionArr(arrA, arrB);
    output(subtractionArray);
}

