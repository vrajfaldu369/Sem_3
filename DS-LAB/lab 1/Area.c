//WAP to calculate area of a Circle (A = πr^2).

#include <stdio.h>
void main(){
    double radius;

    printf("Enter radius of circle: ");
    scanf("%lf",&radius);

    double area = 3.14 * radius * radius;
    printf("Area: %lf",area);

}