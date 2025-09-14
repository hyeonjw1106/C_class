#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Employee {
    char name[20];
    char phone[13];
};

int main(void) {
    int n, m;
    struct Employee *emp;

    scanf("%d", &n);

    emp = (struct Employee *)malloc(n * sizeof(struct Employee));
    if (emp == NULL) {
        printf("메모리 할당 실패\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%s %s", emp[i].name, emp[i].phone);
    }

    scanf("%d", &m);
    char query[20];

    for (int i = 0; i < m; i++) {
        int found = 0;
        scanf("%s", query);

        for (int j = 0; j < n; j++) {
            if (!strcmp(emp[j].name, query)) {
                printf("%s\n", emp[j].phone);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Not found\n");
        }
    }

    free(emp);

    return 0;
}
