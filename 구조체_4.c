#include <stdio.h>
#include <math.h>

struct Point {
    int x;
    int y;
};

int main(void) {
    struct Point p1, p2;
    struct Point *ptr1 = &p1, *ptr2 = &p2;
    double dis;

    scanf("%d %d", &ptr1->x, &ptr1->y);
    scanf("%d %d", &ptr2->x, &ptr2->y);

    dis = sqrt((ptr2->x - ptr1->x) * (ptr2->x - ptr1->x) +
                (ptr2->y - ptr1->y) * (ptr2->y - ptr1->y));

    printf("%.2f\n", dis);

    return 0;
}
