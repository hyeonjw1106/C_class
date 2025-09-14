#include <stdio.h>
#include <string.h>

struct Student {
    char name[20];
    int id;
    int korean;
    int math;
    int english;
    int total;
};

int main(void) {
    int n;
    scanf("%d", &n);

    struct Student students[n];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d %d %d",students[i].name, &students[i].id, &students[i].korean, &students[i].math, &students[i].english);
        students[i].total = students[i].korean + students[i].math + students[i].english;
    }


    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int swap_flag = 0;

            if (students[j].total < students[j + 1].total) {
                swap_flag = 1;
            } else if (students[j].total == students[j + 1].total) {
                if (strcmp(students[j].name, students[j + 1].name) > 0) {
                    swap_flag = 1;
                }
            }

            if (swap_flag) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", students[i].name, students[i].id, students[i].total);
    }

    return 0;
}
