#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *ptr;
    char *dptr;

    ptr = (char*)malloc(10 * sizeof(char));
    dptr = (char*)malloc(10 * sizeof(char));

    if (ptr == NULL || dptr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Address of ptr: %p\n", (void*)ptr);
    printf("Address of dptr: %p\n", (void*)dptr);

    printf("\nEnter the String: \n");

    if (fgets(ptr, 10, stdin) == NULL) {
        fprintf(stderr, "Error reading input\n");
        free(ptr);
        free(dptr);
        return 1;
    }

    printf("String entered: %s\n", ptr);

    free(ptr);
    free(dptr);

    return 0;
}
