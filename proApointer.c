#include<stdio.h>

int main(void) {
    // int* pi;
    // char* pc;
    // double* pd;
    // printf("int* 크기 : %zu 바이트\n", sizeof(pi));
    // printf("char* 크기 : %zu 바이트\n", sizeof(pc));
    // printf("double* 크기 : %zu 바이트\n", sizeof(pd)); ---포인터 크기 확인
    // // 포인터의 크기는 모두 같다. (8바이트)

    // int a = 10;
    // int *p;
    // p = &a;
    // printf("a의 주소 : %p\n", &a);
    // printf("p의 값 : %p\n", p);
    // printf("*p의 값 : %d\n", *p);
    // *p = 20;
    // printf("변경 후 a의 값 : %d\n", a); ---포인터를 이용한 값 변경

    // int x = 50;
    // int y = 200;
    // int* px = &x;
    // int* py = &y;    ---포인터에 값 저장

    // int temp = *px;
    // *px = *py;
    // *py = temp;
    // printf("x : %d y : %d\n", x, y); ---포인터를 사용한 값 치환


    // 실습해보기.
    int a = 30;
    int b = 10;

    // 1. 정수형 포인터 pa, pb 선언 후 a, b의 주소 저장
    int *pa = &a;
    int *pb = &b;

    // 2. 변수 a의 값, 주소 출력
    printf("a의 값 : %d\n", *pa);
    printf("a의 주소 : %p\n", pa);

    // 3. 포인터 pa,pb가 가리키는 주소값 출력
    printf("pa가 가리키는 주소값 : %p\n", pa);
    printf("pb가 가리키는 주소값 : %p\n", pb);

    // 4. 포인터 pa, pb가 가리키는 주소에 저장된 값 출력
    printf("pa가 가리키는 주소에 저장된 값 : %d\n", *pa);
    printf("pb가 가리키는 주소에 저장된 값 : %d\n", *pb);    

    // 5. a의 값 90으로 변경(포인터 사용)
    *pa = 90;
    printf("변수 a의 변경된 값 : %d\n", a);
    
    // 6. a, b 값 치환(포인터 사용)
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
    printf("a : %d b: %d\n", a, b);
    
    return 0;
}
