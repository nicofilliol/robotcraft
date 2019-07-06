#include <stdio.h>
#include <stdlib.h>

struct Date
{
    int day;
    int month;
    int year;
};

struct Person
{
    char name[50];
    struct Date birthday;
};

int isValidDate(struct Date date)
{
    if (date.month >= 1 && date.month <= 12)
    {
        return 1;
    }
    return 0;
}

struct Date getDate()
{
    struct Date d;
    int validDate = 0;
    do
    {
        printf("Enter a date: ");
        scanf("%d %d %d", &d.day, &d.month, &d.year);
        validDate = isValidDate(d);
    } while (validDate != 1);

    return d;
}

void getName(struct Person person)
{
    printf("Enter a name: ");
    scanf("%s", person.name);
}

int isOlder(struct Date date1, struct Date date2)
{
    /*
    Returns:
        0 when date1 is younger than date2
        1 when date1 is older than date2
        -1 when date1 and date 2 are equal
     */
    // Compare years
    if (date1.year < date2.year)
    {
        return 1;
    }
    else if (date1.year > date2.year)
    {
        return 0;
    }
    else
    {
        // Same year, check months
        if (date1.month < date2.month)
        {
            return 1;
        }
        else if (date1.month > date2.month)
        {
            return 0;
        }
        else
        {
            // Same month, check day
            if (date1.day < date2.day)
            {
                return 1;
            }
            else if (date1.day > date2.day)
            {
                return 0;
            }
            else
            {
                // Same day, same age
                return -1;
            }
        }
    }
}

int main()
{

    // Read data for first person
    struct Person person1;
    person1.birthday = getDate();
    getName(person1);

    // Read data for second person
    struct Person person2;
    person2.birthday = getDate();
    getName(person2);

    int older = isOlder(person1.birthday, person2.birthday);

    switch (older)
    {
    case 0:
        printf("%s is the oldest.", person2.name);
        break;
    case 1:
        printf("%s is the oldest.", person1.name);
        break;
    case -1:
        printf("%s and %s are the same age.", person1.name, person2.name);
        break;
    default:
        break;
    }
    return 0;
}
