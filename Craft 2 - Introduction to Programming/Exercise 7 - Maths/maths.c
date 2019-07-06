#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void calculateSphere(double radius, double *area, double *volume);

int main()
{
    // Get radius input
    double radius;
    printf("Enter the radius: ");
    scanf("%lf", &radius);

    double area, volume;
    calculateSphere(radius, &area, &volume);

    // Print values
    printf("Area: %lf, Volume: %lf\n", area, volume);

    return 0;
}

void calculateSphere(double radius, double *area, double *volume)
{
    // Update values on reference variables at pointer address
    *area = 4 * M_PI * pow(radius, 2);
    *volume = (4 / 3) * M_PI * pow(radius, 3);
}
