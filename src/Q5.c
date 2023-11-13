#include "lib\Q5.h"

int main(void)
{
    CONSOLE_CURSOR_INFO cursor_info = {1, 0};
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    do
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        printf("The badminton match is about to start! But we still need to finalize the list of athletes to log in...\n");
        int m, n, k, i;
        printf("Please enter how many male athletes participated in this competition:\n");
        do
        {
            scanf("%d", &m);
            if (m <= 1)
            {
                printf("Error:We need at least 2 players to finish the match, please enter a valid number.\n");
            }
            else
            {
                break;
            }
        } while (1);
        printf("Please enter how many female athletes participated in this competition:\n");
        do
        {
            scanf("%d", &n);
            if (n <= 1)
            {
                printf("Error:We need at least 2 players to finish the match, please enter a valid number.\n");
            }
            else
            {
                break;
            }
        } while (1);
        printf("So, how many rounds of competition do we need to play?\n");
        do
        {
            scanf("%d", &k);
            if (m < 1)
            {
                printf("Error:The rounds of match should be positive.\n");
            }
            else
            {
                break;
            }
        } while (1);
        LinkQuene *M, *N;
        M = (AthleteLink)malloc(sizeof(Athletes));
        N = (AthleteLink)malloc(sizeof(Athletes));
        InitQuene(M);
        InitQuene(N);
        int tempNumber, tempAge, tempNumberStore[100] = {0}, j, tempFlag, store = 0;
        printf("Initializing male athletes");
        for (i = 0; i < 3; i++)
        {
            Sleep(400);
            printf(".");
        }
        printf("\n");
        system("cls");
        for (i = 0; i < m; i++)
        {
            printf("Please enter the number of athlete %d\n", i + 1);
            do
            {
                tempFlag = 0;
                scanf("%d", &tempNumber);
                for (j = 0; j < 100; j++)
                {
                    if (tempNumberStore[j] == tempNumber)
                    {
                        printf("This number is already used,please try another number.\n");
                        tempFlag = 1;
                        break;
                    }
                }
                if (tempFlag == 0)
                {
                    tempNumberStore[store] = tempNumber;
                    store++;
                    break;
                }
            } while (1);
            printf("Considering the health of athletes, please enter the Age of athlete %d\n", i + 1);
            tempAge = AgeScanMan(tempNumber);
            EnQuene(M, tempNumber, tempAge);
        }
        printf("Data initializied successful!\n");
        system("pause");
        system("cls");
        printf("Initializing female athletes");
        for (i = 0; i < 3; i++)
        {
            Sleep(400);
            printf(".");
        }
        printf("\n");
        system("cls");
        for (i = 0; i < n; i++)
        {
            printf("Please enter the number of athlete %d\n", i + 1);
            do
            {
                tempFlag = 0;
                scanf("%d", &tempNumber);
                for (j = 0; j < 100; j++)
                {
                    if (tempNumberStore[j] == tempNumber)
                    {
                        printf("This number is already used,please try another number.\n");
                        tempFlag = 1;
                        break;
                    }
                }
                if (tempFlag == 0)
                {
                    tempNumberStore[store] = tempNumber;
                    store++;
                    break;
                }
            } while (1);
            printf("Considering the health of athletes, please enter the Age of athlete %d\n", i + 1);
            tempAge = AgeScanWoman(tempNumber);
            EnQuene(N, tempNumber, tempAge);
        }
        printf("Initializing competition");
        for (i = 0; i < 3; i++)
        {
            Sleep(400);
            printf(".");
        }
        printf("\n");
        printf("Competition is about to start!\n");
        system("pause");
        system("cls");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
        for (i = 1; i <= (m * k / 2 + 1); i++)
        {
            printf("Competition %d starts!\n", i);
            printf("Team A:\n");
            DeQuene(M, &tempNumber, &tempAge);
            printf("Male Athlete:Number %d, he is %d years old.\n", tempNumber, tempAge);
            EnQuene(M, tempNumber, tempAge);
            DeQuene(N, &tempNumber, &tempAge);
            printf("Female Athlete:Number %d, she is %d years old.\n", tempNumber, tempAge);
            EnQuene(N, tempNumber, tempAge);
            printf("Team B:\n");
            DeQuene(M, &tempNumber, &tempAge);
            printf("Male Athlete:Number %d, he is %d years old.\n", tempNumber, tempAge);
            EnQuene(M, tempNumber, tempAge);
            DeQuene(N, &tempNumber, &tempAge);
            printf("Female Athlete:Number %d, she is %d years old.\n", tempNumber, tempAge);
            EnQuene(N, tempNumber, tempAge);
            Sleep(2000);
            printf("\n\n\n");
        }
        system("pause");
        system("cls");
        printf("The match is over, do you want to start a new match?If so,please enter 1\n");
        scanf("%d", &global);
        if (global == 1)
        {
            global = 0;
            continue;
        }
        else
        {
            break;
        }
    } while (1);
    return 0;
}
