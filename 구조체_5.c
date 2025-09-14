#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[20];
    int score;
};

int main(void) {
    int n;
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%s %d", students[i].name, &students[i].score);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += students[i].score;
    }

    double average = (double)sum / n;
    printf("%.2f\n", average);

    free(students);
    return 0;
}
