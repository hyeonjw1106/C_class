#include<stdio.h>

int main(void) {
    int time, goal, left_time;
    scanf("%d %d", &time, &goal);
    left_time = 90 - time;
    for(int i=0; i<left_time; i++) {
        if ((i == 0) || (i%5 == 0)) {
            goal++;
        }
    }
    printf("%d", goal);
    
    
    
    return 0;
}