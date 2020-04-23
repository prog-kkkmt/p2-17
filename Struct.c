#include <stdio.h>

struct data {
    int year;
    int month;
};

int main() {
    struct data d1;
    struct data d2;
    struct data d3;
    scanf("%d %d %d %d", &d1.year, &d1.month, &d2.year, &d2.month);
    scanf("%d %d", &d3.year, &d3.month);
    if (d1.year < d3.year && d3.year < d2.year)
        printf("Да");
    else if(d3.year == d1.year)
        if (d3.month >= d1.month)
            printf("Да");
        else printf("Нет");
    else if(d3.year == d2.year)
        if (d3.month <= d2.month)
            printf("Да");
        else printf("Нет");
    else
        printf("Нет");
    return 0;
}
