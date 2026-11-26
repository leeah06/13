#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *pc = NULL;
    int i = 0;

    pc = (char*)malloc(100 * sizeof(char));   /* 100 bytes */
    if (pc == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }

    for (i = 0; i < 26; i++) {
        pc[i] = 'a' + i;                      /* a ~ z */
    }
    pc[i] = 0;                                /* i == 26 : null terminator */

    printf("%s\n", pc);
    free(pc);
    return 0;
}