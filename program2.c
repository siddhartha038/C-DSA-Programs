#include <stdio.h>

int main()
{
    int day, month, year;
    int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};

    printf("Enter day, month, and year (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    if (month < 3)
        year--;

    int result = (year + year / 4 - year / 100 + year / 400 + t[month - 1] + day) % 7;

    char *dayOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("Day of the week: %s\n", dayOfWeek[result]);

    return 0;
}
