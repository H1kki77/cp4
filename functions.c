#include <stdio.h>
#include <math.h>
#include <conio.h>
#include "functions.h"
#include <stdbool.h>

double toRadians(double current_x) {
    double radians = current_x * M_PI / 180;
    return radians;
}

double TaylorSin(double radians, const double epsilon)
{
    double delta = radians, sin = delta;
    int n = 1;
    do
    {
        delta *= -pow(radians, 2.0) / ((double)(n + 1) * (double)(n + 2));
        sin += delta;
        n += 2;
    }
    while (fabs(delta) > epsilon);
    return sin;
}

int Step(int x1, int x2) {
    int dx=0;
    bool errorInput;
    do {

        do {
            errorInput = false;
            printf("Enter a step size (dx):\n");
            if(scanf("%d", &dx)!=1 ) {
                errorInput = true;
                printf("Invalid Input, enter integer number\n");
                fflush(stdin);
            }
        } while(errorInput);

        if (x1 != x2 && dx == 0) {
            printf("In this way the step size can not be 0. Please, enter valid value of dx:\n");
            fflush(stdin);
        } else if (x1 < x2 && dx < 0) {
            printf("In this way the step size can not be less, than 0. Please, enter valid value of dx:\n");
            fflush(stdin);
        } else if (x1 > x2 && dx > 0) {
            printf("In this way the step size can not be bigger than 0. Please, enter valid value of dx:\n");
            fflush(stdin);
        }

    } while ((x1 != x2 && dx == 0) || (x1 < x2 && dx < 0) || (x1 > x2 && dx > 0));
    return dx;
}