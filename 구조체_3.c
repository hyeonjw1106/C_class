#include <stdio.h>

struct Date {
    int year;
    int month;
    int day;
};

struct Employee {
    char name[20];
    int num;
    struct Date date;
};

int main(void) {
    struct Employee e[3];
    int min_idx = 0;

    for (int i = 0; i < 3; i++) {
        scanf("%s %d %d %d %d", e[i].name, &e[i].num, &e[i].date.year, &e[i].date.month, &e[i].date.day);

        if (i > 0) {
            struct Date d1 = e[min_idx].date;
            struct Date d2 = e[i].date;

            if (d2.year < d1.year || 
               (d2.year == d1.year && d2.month < d1.month) || 
               (d2.year == d1.year && d2.month == d1.month && d2.day < d1.day)) {
                min_idx = i;
            }
        }
    }

    printf("%s %d %d-%02d-%02d\n", e[min_idx].name, e[min_idx].num, e[min_idx].date.year, e[min_idx].date.month, e[min_idx].date.day);

    return 0;
}
