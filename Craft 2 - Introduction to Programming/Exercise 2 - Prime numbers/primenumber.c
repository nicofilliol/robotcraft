#include <stdio.h>
#include <stdlib.h>

int getNumber()
{
    int n;
    scanf("Enter a number: %d", &n);
    return n;
}

int main()
{

    int number = getNumber();

    return 0;
}
