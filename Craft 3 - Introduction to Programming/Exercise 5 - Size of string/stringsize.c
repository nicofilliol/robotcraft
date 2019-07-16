#include <stdio.h>
#include <stdlib.h>

void getString(char *string)
{
    printf("Input string: ");
    //fgets(string, sizeof(string), stdin)
    gets(string);
}

int getLength(char *string)
{
    int count = 0;

    while (*string != '\0')
    {
        count++;
        string++;
    }

    return count;
}

int main()
{
    char str[50];

    /* printf("Input string: ");
    fgets(str, sizeof(str), stdin);*/

    getString(str);

    int length = getLength(str);
    printf("%d", length);

    return 0;
}