#include <stdio.h>
#include <math.h>
#include "functions.h"
#include <conio.h>
#include <stdbool.h>
#define MAX_SIZE 100


int main() {
    bool errorInput;
    int x1=0, x2=0, dx=0;
    double e=0; double current_x=0;
    int iterations=0;
    double x[MAX_SIZE], TaylorValue[MAX_SIZE], standardValue[MAX_SIZE], difference[MAX_SIZE];
//перенести змінні в цикл do
    do {
        printf("Hello,\nThis program calculates Sines, Taylor series, Standard values and their difference\nin the specified range with the given accuracy.\n");

        do{
            printf("Enter value for x1 (degrees) [-360; 360]:\n");
            errorInput = false;
            if (scanf("%d", &x1)!=1) {
                errorInput = true;
                printf("Invalid input, enter integer number:\n");
                fflush(stdin);
            }
            else if (x1<-360 || x1 > 360 ) {
                errorInput = true;
                printf("Invalid input, enter number from -360 to 360:\n");
                fflush(stdin);
            }
        }while (errorInput || x1<-360 || x1 > 360);
       errorInput = true;

        do {
            printf("Enter value for x2 (degrees) [-360; 360]:\n");
            errorInput = false;
            if  (scanf("%d", &x2)!=1) {
                errorInput = true;
                printf("Invalid input, enter integer number:\n");
                fflush(stdin);
            }
            else if (x2<-360 || x2 > 360 ) {
                errorInput = true;
                printf("Invalid input, enter number from -360 to 360:\n");
                fflush(stdin);
            }
        }while (errorInput || x2<-360 || x2 > 360);

        dx = Step(x1, x2);
        do {
            printf("Enter value for accuracy from 1e-1 to 1e-15:\n");
            errorInput = false;
            if (scanf("%lf", &e)!=1 || e<1e-15 || e>1e-1) {
                errorInput = true;
                printf("Invalid input, enter correct number:\n");
                fflush(stdin);
            }
        }while (errorInput || e<1e-15 || e>1e-1);

        current_x=x1;

        do {
            double radians=toRadians(current_x);
            x[iterations] = current_x;
            TaylorValue[iterations] = TaylorSin(radians, e);
            standardValue[iterations] = sin(radians);
            difference[iterations] = standardValue[iterations]-TaylorValue[iterations];
            iterations++;
            current_x+=(double)dx;
        } while (dx > 0 && current_x <= x2 || dx < 0 && current_x >= x2 && iterations < MAX_SIZE);

        printf("--------------------------------------------------------------------------\n");
        printf("|   x     (degrees)    |     Taylor_sin   |   Standard_sin   |   Difference   |\n");
        printf("--------------------------------------------------------------------------\n");
        for(int i = 0; i < iterations; i++)
        {
            printf("|   %2.0f   |   %e   |   %e   |   %e   |\n",
                x[i], TaylorValue[i], standardValue[i], difference[i]);
        }
        printf("Do you want to continue?(ENTER for YES/any key to EXIT):\n");
    }while (getch() == 13);
    return 0;
}