#include <stdlib.h>
#include <stdio.h>

void parseTime(int totalTime, int *hours, int *minutes)
{
    // Get hours
    int h = totalTime / 60; //integer divison --> floor division

    int min = totalTime - (h * 60);

    // Change values of pointers
    *hours = h;
    *minutes = min;
}

int main()
{
    int tot;
    printf("Enter a duration in minutes: ");
    scanf("%i", &tot);

    int hours, minutes;

    parseTime(tot, &hours, &minutes);

    printf("%d minutes is %d hours and %d minutes!\n", tot, hours, minutes);

    return 0;
}