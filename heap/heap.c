//1885
#include <stdio.h>
#include <stdlib.h>
#define DEFAULT_SIZE 1000000
typedef int (*TFCmp)(int, int);
typedef struct heap {
    int nrElem, nrMaxElem;
    int *v;
    TFCmp cmp;
} THeap;
int cmpMax(int a, int b) {
    return a < b;
}
THeap* AlocaHeap(int nrMaxElem, TFCmp cmp) {
    THeap* H = (THeap*)malloc(sizeof(THeap));
    if (!H) {
        return NULL;
    }
    H->v = (int*)malloc(sizeof(int) * nrMaxElem);
    if (!H->v) {
        free(H);
        return NULL;
    }
    H->nrElem = 0;
    H->nrMaxElem = nrMaxElem;
    H->cmp = cmp;

    return H;
}
void SwapInt(int* a, int* b) {
    int aux = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = aux;
}
void UpdateHeap(THeap* H, int pos) {
    while (pos != 0) {
        if (!cmpMax(H->v[pos], H->v[(pos - 1) / 2])) {
            SwapInt(&H->v[pos], &H->v[(pos - 1) / 2]);
        }
        pos = (pos - 1) / 2;
    }
}
void InsertHeap(THeap* H, int x) {
    // functia presupune ca avem deja Heap-ul declarat corect (not NULL)

    H->v[H->nrElem++] = x;

    UpdateHeap(H, H->nrElem - 1);
}

int PopHeap(THeap *H) {
    if (H->nrElem == 0) {
        return -1;
    }

    int ret = H->v[0];

    SwapInt(&H->v[0], &H->v[H->nrElem - 1]);
    H->nrElem--;

    int pos = 0;

    while (pos <= H->nrElem) {
        int maximum = pos;
        if (2 * pos + 1 < H->nrElem && cmpMax(H->v[maximum], H->v[2 * pos + 1])) {
            maximum = 2 * pos + 1;
        }
        if (2 * pos + 2 < H->nrElem && cmpMax(H->v[maximum], H->v[2 * pos + 2])) {
            maximum = 2 * pos + 2;
        }

        if (maximum != pos) {
            SwapInt(&H->v[pos], &H->v[maximum]);
            pos = maximum;
        }
        else {
            break;
        }
        pos = maximum;
    }

    return ret;
}

void PrintHeap(THeap *H) {
    for (int i = 0; i < H->nrElem; i++) {
        printf("%d ", H->v[i]);
    }
    printf("\n");
}
int main() {
    int m, op, x;
    THeap *H = AlocaHeap(DEFAULT_SIZE, cmpMax);
    if (!H) {
        fprintf(stderr, "ERR: Eroare alocare HEAP!");
        return -1;
    }

    FILE* in = fopen("heap.in", "r");
    if (!in) {
        fprintf(stderr, "ERR: Input file not found!");
        free(H);
        return -1;
    }
    FILE* out = fopen("heap.out", "w");
    if (!out) {
        free(H);
        fclose(in);
        fprintf(stderr, "ERR: Output file not found!");
        return -1;
    }

    fscanf(in, "%d", &m);
    for (int i = 0; i < m; i++) {
        fscanf(in, "%d", &op);
        if (op == 1) {
            fscanf(in, "%d", &x);
            InsertHeap(H, x);
        } else if (op == 2) {
            int ans = PopHeap(H);
            if (ans != -1) {
                fprintf(out, "%d\n", ans);
            }
        }
    }
}