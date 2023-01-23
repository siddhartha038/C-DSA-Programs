#include <stdio.h>
#include <string.h>

int main()
{
    int dd, mm, yyyy, d, day;
    long int e;

    scanf("%d %d %d", &dd, &mm, &yyyy);
    for (d = 1, e = (365 * (yyyy - 1)) + (dd - 1) + ((yyyy / 4) - (yyyy / 100) + (yyyy / 400)); d < mm;
         d++)
        e += (d == 2) ? (28) : ((d == 4 || d == 6 || d == 9 || d == 11) ? (30) : (31));
    day = e % 7;
    if (day == 0)
        printf("MONDAY");
    else if (day == 1)
        printf("TUESDAY");
    else if (day == 2)
        printf("WEDNESDAY");
    else if (day == 3)
        printf("THURSDAY");
    else if (day == 4)
        printf("FRIDAY");
    else if (day == 5)
        printf("SATURDAY");
    else
        printf("SUNDAY");

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}