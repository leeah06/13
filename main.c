#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book {
    int number;
    char title[30];   /* slide: title[10] -> too small for the titles below */
};

int main(void) {
    int i;
    struct Book **bookshelf;

    /* 3 pointers (rows) */
    bookshelf = (struct Book**)malloc(3 * sizeof(struct Book*));
    if (bookshelf == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }
    /* each row : 10 Book structs */
    for (i = 0; i < 3; i++) {
        bookshelf[i] = (struct Book*)malloc(10 * sizeof(struct Book));
        if (bookshelf[i] == NULL) {
            printf("Memory allocation error\n");
            return 1;
        }
    }

    bookshelf[1][3].number = 5;
    strcpy(bookshelf[1][3].title, "C++ Programming");

    (bookshelf[2] + 4)->number = 3;
    strcpy((bookshelf[2] + 4)->title, "Communications Theory");

    printf("book (1,3) : %i, %s\n", (bookshelf[1] + 3)->number, (bookshelf[1] + 3)->title);
    printf("book (2,4) : %i, %s\n", bookshelf[2][4].number, bookshelf[2][4].title);

    /* free in reverse order : rows first, then the pointer array */
    for (i = 0; i < 3; i++)
        free(bookshelf[i]);
    free(bookshelf);

    return 0;
}