#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int comp(const void *elem1, const void *elem2) {
    return *((int*)elem1) - *((int*)elem2);
}

int main() {
    int fd = open("test2.in", O_RDONLY);
    if (fd == -1) {
        perror("Failed to open file");
        return 1;
    }

    int n;
    if (read(fd, &n, sizeof(int)) != sizeof(int)) {
        perror("Failed to read the number of elements");
        close(fd);
        return 1;
    }

    int *v = malloc(sizeof(int) * n);
    if (v == NULL) {
        perror("Failed to allocate memory");
        close(fd);
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (read(fd, &v[i], sizeof(int)) != sizeof(int)) {
            printf("%d\n", i);
            perror("Failed to read array element");
            free(v);
            close(fd);
            return 1;
        }
    }

    qsort(v, n, sizeof(int), comp);

    // Optionally, you can print the sorted array to verify the result
    for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");

    free(v);
    close(fd);

    return 0;
}