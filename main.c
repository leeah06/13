#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[30];   /* slide: title[10] -> too small for "C Programming"(13+1) */
};

int main(void) {
    struct Book *p;

    p = (struct Book*)malloc(2 * sizeof(struct Book));   /* 2 Book structs */
    if (p == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    p->number = 1;
    strcpy(p->title, "C Programming");

    (p + 1)->number = 2;
    strcpy((p + 1)->title, "Electronics");

    printf("book 0 : %i, %s\n", p->number, p->title);
    printf("book 1 : %i, %s\n", (p + 1)->number, (p + 1)->title);

    free(p);
    return 0;
}