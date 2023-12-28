/*
Programmer: Jimmy Reynoso
Date completed: 12/17/2020
Instructor: Karoly Becze
Class: csis 112


Programm Overview: 



*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define PASSWORD 7111

FILE* save;
FILE* savedate;
FILE* fp;

typedef struct{

    int month;
    int day;
    int year;

} Date;

void passcheck();
void orderArray(int num[], int num2[], int size);
int isleapyear(int year);
void getdate(Date* today);
void getbalance(int* balance);
void subscription(int subs[], int time[], int* max);
void calculate(int subs[], int time[], int* max, int* balance, Date* today);

int main(){

    fopen_s(&fp, "csis.txt", "w");
    if (fp == NULL) {
        printf("error opening file");
        exit(1);
    }

    Date today;
    int balance = 0;
    int subs[100];
    int time[100];
    int max = 0;


    passcheck();
    getdate(&today);
    getbalance(&balance);
    subscription(subs, time, &max);
    calculate(subs, time, &max, &balance, &today);

    fclose(fp);

    return (0);
}


void passcheck() {

    int pass = 0;

    printf("Please enter your password:");
    fprintf(fp,"Please enter your password:");
    scanf("cool nuts bro:%d test test", &pass);

    if (pass == PASSWORD) {
        printf("ACCESS GRANTED...\n\n");
    }
    else {

        while (pass != PASSWORD){

            printf(" ERROR incorrect password entered\n\n");
            fprintf(fp," ERROR incorrect password entered\n\n");
            printf("Please enter your password:");
            fprintf(fp,"Please enter your password:");

            scanf(" %d", &pass);

        }

    }


}

void orderArray(int num[], int num2[], int size) {

    int i, temp, temp2, swap;
 
    while (1) {

        swap = 0;

        for (i = 0; i < size-1; i++) {
            if (num[i] > num[i + 1]) {

                temp = num[i];
                temp2 = num2[i];
                num[i] = num[i + 1];
                num2[i] = num2[i + 1];
                num[i + 1] = temp;
                num2[i + 1] = temp2;
                swap = 1;





            }

        }

        if (swap == 0) {
            break;
        }


    }



}

int isleapyear(int year) {

    return ( (!(year % 4) && year % 100) || !(year % 400) );

}

void getdate(Date* today) {

    // holds the maximum days in every month
    int dayspermonth[] = { 31,0,31,30,31,30,31,31,30,31,30,31};
    int savecheck;

    printf("\nThis program saves information for ease of use\n");
    fprintf(fp,"\nThis program saves information for ease of use\n");
    printf("if you have already input the date before\n");
    fprintf(fp,"if you have already input the date before\n");
    printf("input [1]\n");
    fprintf(fp,"input [1]\n");
    printf("if not input[0]\n");
    fprintf(fp,"if not input[0]\n");
    printf("waiting for input:");
    fprintf(fp,"waiting for input:");
    scanf("%d", &savecheck);

    while (savecheck > 1 || savecheck < 0) {

        printf(" Error enter either [0] or [1] ");
        fprintf(fp," Error enter either [0] or [1] ");
        printf("waiting for input:");
        fprintf(fp,"waiting for input:");
        scanf("%d", &savecheck);
    }


    if (savecheck == 0) {

        fopen_s(&savedate, "savefile2.txt", "w");
        if (savedate == NULL) {
            printf("error opening file");
            exit(1);
        }



    printf("Enter todays date as so -> mm/dd/yyyy: ");
    fprintf(fp,"Enter todays date as so -> mm/dd/yyyy: ");
    scanf(" %d/%d/%d", &today->month, &today->day, &today->year);
    fprintf(savedate, "%d %d %d", today->month, today->day, today->year);



        //adjusting the month of february on whether or not its a leap year or not

        if (isleapyear(today->year)) {
            dayspermonth[1] = 29;
        }
        else {
            dayspermonth[1] = 28;
        }


        // CHECKING FOR VALID DATE

        while (today->day > dayspermonth[today->month - 1] || today->day < 0 || today->month > 12 || today->month < 0 || today->year < 2020) {

            if (today->day > dayspermonth[today->month - 1] || today->day < 0) {

                printf(" ERROR the the size of day is invalid\n\n");
                fprintf(fp," ERROR the the size of day is invalid\n\n");

                printf("Enter todays date as so -> mm/dd/yyyy: ");
                fprintf(fp,"Enter todays date as so -> mm/dd/yyyy: ");
                scanf(" %d/%d/%d", &today->month, &today->day, &today->year);
                fprintf(savedate, "%d %d %d", today->month, today->day, today->year);

                if (isleapyear(today->year)) {
                    dayspermonth[1] = 29;
                }
                else {
                    dayspermonth[1] = 28;
                }


            }

            if (today->month > 12 || today->month < 0) {

                printf(" ERROR the the size of month is invalid\n\n");
                fprintf(fp," ERROR the the size of month is invalid\n\n");

                printf("Enter todays date as so -> mm/dd/yyyy: ");
                fprintf(fp,"Enter todays date as so -> mm/dd/yyyy: ");
                scanf(" %d/%d/%d", &today->month, &today->day, &today->year);
                fprintf(savedate, "%d %d %d", today->month, today->day, today->year);

                if (isleapyear(today->year)) {
                    dayspermonth[1] = 29;
                }
                else {
                    dayspermonth[1] = 28;
                }


            }

            if (today->year < 2020) {

                printf(" ERROR the the size of year is invalid\n\n");
                fprintf(fp," ERROR the the size of year is invalid\n\n");

                printf("Enter todays date as so -> mm/dd/yyyy: ");
                fprintf(fp,"Enter todays date as so -> mm/dd/yyyy: ");
                scanf(" %d/%d/%d", &today->month, &today->day, &today->year);
                fprintf(savedate, "%d %d %d", today->month, today->day, today->year);

                if (isleapyear(today->year)) {
                    dayspermonth[1] = 29;
                }
                else {
                    dayspermonth[1] = 28;
                }

            }


        }

        //OUTPUTTING DATE ENTERED
        printf("\nyou have entered -> %d/%d/%d\n\n", today->month, today->day, today->year);
        fprintf(fp,"\nyou have entered -> %d/%d/%d\n\n", today->month, today->day, today->year);

        fclose(savedate);

    }

    if (savecheck == 1) {

        fopen_s(&savedate, "savefile2.txt", "r");
        if (savedate == NULL) {
            printf("error opening file");
            exit(1);
        }

        while (!feof(savedate)) {

            fscanf(savedate, "%d %d %d", &today->month, &today->day, &today->year);

        }

        fclose(savedate);


    }




}

void getbalance(int* balance){

    printf("What is your account balance:");
    fprintf(fp,"What is your account balance:");
    scanf(" %d", balance);
    printf("\nyou have entered -> %d\n\n", *balance);
    fprintf(fp,"\nyou have entered -> %d\n\n", *balance);
}

void subscription(int subs[], int time[], int* max) {



    int i = 0;
    int user = 3;
    int savecheck;
    *max = 0;

    printf("Subcription information will be saved for future runs of the program\n\n");
    fprintf(fp,"Subcription information will be saved for future runs of the program\n\n");

    printf("if you have already input your subscription information before\n");
    fprintf(fp,"if you have already input your subscription information before\n");
    printf("input [1]\n");
    fprintf(fp,"input [1]\n");
    printf("if not input[0]\n");
    fprintf(fp,"if not input[0]\n");
    printf("waiting for input:");
    fprintf(fp,"waiting for input:");
    scanf("%d", &savecheck);

    while (savecheck > 1 || savecheck < 0) {

        printf(" Error enter either [0] or [1] ");
        fprintf(fp," Error enter either [0] or [1] ");
        printf("waiting for input:");
        fprintf(fp,"waiting for input:");
        scanf("%d", &savecheck);
    }

    printf("\n\n");
    fprintf(fp,"\n\n");

    if (savecheck == 0) {

        fopen_s(&save, "savefile.txt", "w");
        if (save == NULL) {
            printf("error opening file");
            exit(1);
        }



        for (i = 0; i < 100; i++) {

            printf("please enter the amount of the subscription:");
            fprintf(fp,"please enter the amount of the subscription:");
            scanf("%d", &subs[i]);
            fprintf(save, "%d\t", subs[i]);//saving
            printf("\nEnter the subcription period\n");
            fprintf(fp,"\nEnter the subcription period\n");
            printf("enter [1] for Monthly\n");
            fprintf(fp,"enter [1] for Monthly\n");
            printf("enter [2] for Yearly\n");
            fprintf(fp,"enter [2] for Yearly\n");
            printf("enter [3] for Weekly\n");
            fprintf(fp,"enter [3] for Weekly\n");
            printf("enter [4] for Bi Weekly\n");
            fprintf(fp,"enter [4] for Bi Weekly\n");
            printf("waiting for input:");
            fprintf(fp,"waiting for input:");
            scanf("%d", &time[i]);


            while (time[i] > 4 || time[i] < 1) {

                printf(" Error enter [1],[2],[3], or[4] ");
                fprintf(fp," Error enter [1],[2],[3], or[4] ");
                printf("waiting for input:");
                fprintf(fp,"waiting for input:");

                scanf("%d", &time[i]);
            }

            switch (time[i]) {

            case 1: time[i] = 30; break;

            case 2: time[i] = 365; break;

            case 3: time[i] = 7; break;

            case 4: time[i] = 14; break;

            }

            fprintf(save, "%d\n", time[i]);//saving

            (*max)++;


            printf("\nWould you like to enter another subscription\n");
            fprintf(fp,"\nWould you like to enter another subscription\n");
            printf("enter [1] for yes\n");
            fprintf(fp,"enter [1] for yes\n");
            printf("enter [0] for no\n");
            fprintf(fp,"enter [0] for no\n");
            printf("waiting for input:");
            fprintf(fp,"waiting for input:");

            scanf("%d", &user);
            putchar('\n');
            fprintf(fp,"\n");

            while (user > 1 || user < 0) {

                printf(" Error enter either [0] or [1] ");
                fprintf(fp," Error enter either [0] or [1] ");
                printf("waiting for input:");
                fprintf(fp,"waiting for input:");

                scanf("%d", &user);
            }

            if (user == 0) {
                break;
            }
            if (user == 1) {
                continue;
            }




        }


        fclose(save);

    }



    if (savecheck == 1) {

        fopen_s(&save, "savefile.txt", "r");
        if (save == NULL) {
            printf("error opening file");
            exit(1);
        }

        i = 0;

        while (!feof(save)) {

            fscanf(save, "%d\t", &subs[i]);

            fscanf(save, "%d\n", &time[i]);

            i++; (*max)++;
        }


        fclose(save);

    }





}

void calculate(int amount[], int days[], int* max, int *balance, Date* today) {

    int i = 0;
    int y = 0;
    int daysPerMonth[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int a, b, c;
    int x, w, z;
    int totalded = 0;
    int tra[100];
    

    orderArray(days, amount, *max);



    a = today->month, b = today->day, c = today->year;

    for (i = 0; i < *max; i++) {



        for (int i = 0; i < days[y]; i++){

            today->day++;

            if (today->day > daysPerMonth[today->month - 1] || (today->month == 2 && today->day == 29 && !isleapyear(today->year) ) ){

                today->day = 1;
                today->month++;

                if (today->month == 13) {

                    today->month = 1;
                    today->year++;

                }

            }

           
        }


        printf("due: %d/%d/%d\t", today->month, today->day, today->year);
        fprintf(fp,"due: %d/%d/%d\t", today->month, today->day, today->year);

        totalded += amount[i];

        printf("after a deduction of %d your balance is %d\n\n", amount[i], *balance -= amount[i]);
        fprintf(fp,"after a deduction of %d your balance is %d\n\n", amount[i], *balance -= amount[i]);

        x = today->month, w = today->day, z = today->year;

        today->month = a, today->day = b, today->year = c;

        y++;


    }

    
    printf("On this date %d/%d/%d the total deducted will be %d\n\n", x, w, z, totalded);
    fprintf(fp,"On this date %d/%d/%d the total deducted will be %d\n\n", x, w, z, totalded);

    
}