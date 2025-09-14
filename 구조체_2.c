#include <stdio.h>

struct Author {
    char name[50];
    int birth;   
};

struct Book {
    char title[100];    
    int price;          
    struct Author author; 
};

int main(void) {
    struct Book b1, b2;

    scanf("%s %d %s %d", 
          b1.title, &b1.price, b1.author.name, &b1.author.birth);

    scanf("%s %d %s %d", 
          b2.title, &b2.price, b2.author.name, &b2.author.birth);

    struct Book cheaper = (b1.price < b2.price) ? b1 : b2;

    printf("%s %d %s %d\n", cheaper.title, cheaper.price, cheaper.author.name, cheaper.author.birth);
    
    return 0;

}
