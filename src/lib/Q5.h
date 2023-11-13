#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int global = 0;
typedef struct Athletes
{
    int number;
    int age;
    struct Athletes *next;
} *AthleteLink, Athletes;
typedef struct LinkQuene
{
    AthleteLink front;
    AthleteLink rear;
} LinkQuene;

int InitQuene(LinkQuene *Q)
{
    Q->front = Q->rear = (AthleteLink)malloc(sizeof(Athletes));
    if (!Q->front)
    {
        printf("Fatal Error:Malloc failed in Quene initializing, exiting program.\n");
        exit(1);
    }
    Q->front->next = NULL;
    return 0;
}
int EnQuene(LinkQuene *Q, int tempNumber, int tempAge)
{
    Athletes *temp;
    temp = (AthleteLink)malloc(sizeof(Athletes));
    if (!temp)
    {
        printf("Fatal Error:Malloc failed in Quene building, exiting program.\n");
        exit(1);
    }
    temp->age = tempAge;
    temp->number = tempNumber;
    temp->next = NULL;
    Q->rear->next = temp;
    Q->rear = temp;
    return 0;
}
int DeQuene(LinkQuene *Q, int *tempNumber, int *tempAge)
{
    Athletes *temp;
    temp = (AthleteLink)malloc(sizeof(Athletes));
    if (Q->front == Q->rear)
    {
        printf("Fatal Error:Malloc failed in Quene puting, exiting program.\n");
        exit(1);
    }
    temp = Q->front->next;
    *tempAge = temp->age;
    *tempNumber = temp->number;
    Q->front->next = temp->next;
    if (Q->rear == temp)
    {
        Q->rear = Q->front;
    }
    free(temp);
    return 1;
}

int AgeScanMan(int tempNumber)
{
    int tempAge;
    do
    {
        scanf("%d", &tempAge);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        if (tempAge <= 18 && tempAge >= 10)
        {
            printf("It seems that our %d player is very young. Good luck!\n", tempNumber);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        else if (tempAge >= 19 && tempAge <= 30)
        {
            printf("The contestant %d is in his prime, I bet he will achieve good results!\n", tempNumber);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        else if (tempAge >= 31 && tempAge <= 60)
        {
            printf("The player is getting old, but I don't think it will affect his performance.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        else if (tempAge >= 61 && tempAge <= 90)
        {
            printf("What an elderly athlete, let's cheer for his sportsmanship!\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        else
        {

            if (global == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                printf("The age value is invalid. Please enter the age again.\n");
                global++;
            }
            else if (global == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("PLEASE DO NOT BE SILLY,a person with this age shouldn't appear on the field.\n");
                printf("Please enter the age again.\n");
                global++;
            }
            else if (global == 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("ARE YOU KIDDING ME?\n");
                printf("THIS IS THE LAST WARNING,ENTER A VALID NUMBER OR GO AWAY.\n");
                global++;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                exit(0);
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
    } while (1);
    return tempAge;
}

int AgeScanWoman(int tempNumber)
{
    int tempAge;
    do
    {
        scanf("%d", &tempAge);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        if (tempAge <= 18 && tempAge >= 10)
        {
            printf("It seems that our %d player is very young. Good luck!\n", tempNumber);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        else if (tempAge >= 19 && tempAge <= 30)
        {
            printf("The contestant %d is in her prime, I bet she will achieve good results!\n", tempNumber);
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        else if (tempAge >= 31 && tempAge <= 60)
        {
            printf("The player is getting old, but I don't think it will affect her performance.\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        else if (tempAge >= 61 && tempAge <= 90)
        {
            printf("What an elderly athlete, let's cheer for her sportsmanship!\n");
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
            break;
        }
        else
        {

            if (global == 0)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                printf("The age value is invalid. Please enter the age again.\n");
                global++;
            }
            else if (global == 1)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
                printf("PLEASE DO NOT BE SILLY,a person with this age shouldn't appear on the field.\n");
                printf("Please enter the age again.\n");
                global++;
            }
            else if (global == 2)
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                printf("ARE YOU KIDDING ME?\n");
                printf("THIS IS THE LAST WARNING,ENTER A VALID NUMBER OR GO AWAY.\n");
                global++;
            }
            else
            {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                exit(0);
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        }
    } while (1);
    return tempAge;
}
