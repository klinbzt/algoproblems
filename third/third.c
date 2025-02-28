//#3699
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DEFAULT_SIZE 200001
typedef int (*TFCmp)(int, int);
typedef struct heap {
    int nrElem, nrMaxElem;
    int* v;
    TFCmp cmp;
} THeap;
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
void DistrugeHeap(THeap* H) {
    free(H->v);
    free(H);
}
void SwapInt(int* a, int* b) {
    int aux = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = aux;
}
int CmpMax(int a, int b) {
    return a > b;
}
void InsHeap(THeap* H, int x) {
    if (H->nrElem == H->nrMaxElem) {
        fprintf(stderr, "Heap-ul a atins nr maxim de elemente alocate.");
        return;
    }

    H->v[H->nrElem++] = x;
    
    int pos = H->nrElem - 1;
    while (pos != 0) {
        if (!H->cmp(H->v[pos], H->v[(pos - 1) / 2])) {
            SwapInt(&H->v[pos], &H->v[(pos - 1) / 2]);
        } else {
            break;
        }
        pos = (pos - 1) / 2;
    }
}
int PopHeap(THeap *H) {
    if (H->nrElem == 0) {
        return -1;
    }

    int ret = H->v[0];
    SwapInt(&H->v[0], &H->v[H->nrElem - 1]);
    H->nrElem--;

    int pos = 0, maximum;
    while (pos < H->nrElem) {
        maximum = pos;
        if (2 * pos + 1 < H->nrElem && H->cmp(H->v[maximum], H->v[2 * pos + 1])) {
            maximum = 2 * pos + 1;
        }
        if (2 * pos + 2 < H->nrElem && H->cmp(H->v[maximum], H->v[2 * pos + 2])) {
            maximum = 2 * pos + 2;
        }

        if (maximum != pos) {
            SwapInt(&H->v[pos], &H->v[maximum]);
            pos = maximum;
        }
        else {
            break;
        }
    }

    return ret;
}

void PopSpecificNumber(THeap *H, int x) {
    int index = -1;
    for (int i = 0; i < H->nrElem; i++) {
        if (H->v[i] == x) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        return;
    }

    H->v[index] = H->v[H->nrElem - 1];
    H->nrElem--;

    if (index < H->nrElem) {
    int pos = 0, maximum;
    while (pos < H->nrElem) {
        maximum = pos;
        if (2 * pos + 1 < H->nrElem && H->cmp(H->v[maximum], H->v[2 * pos + 1])) {
            maximum = 2 * pos + 1;
        }
        if (2 * pos + 2 < H->nrElem && H->cmp(H->v[maximum], H->v[2 * pos + 2])) {
            maximum = 2 * pos + 2;
        }

        if (maximum != pos) {
            SwapInt(&H->v[pos], &H->v[maximum]);
            pos = maximum;
        }
        else {
            break;
        }
    }
    }
}

int FindThird(THeap* H) {
    if (H->nrElem < 3) {
        fprintf(stderr, "Heap does not contain enough elements.\n");
        return -1; // Or handle the error as appropriate
    }

    int first = H->v[0];
    int second = DEFAULT_SIZE;
    int third = DEFAULT_SIZE;

    for (int i = 1; i <= 6 && i < H->nrElem; i++) {
        if (H->v[i] <= second) {
            third = second;
            second = H->v[i];
        } else if (H->v[i] <= third) {
            third = H->v[i];
        }
    }

    return third;
}
int main() {
    THeap* H = AlocaHeap(DEFAULT_SIZE, CmpMax);
    if (!H) {
        fprintf(stderr, "ERR: Nu s-a putut aloca memorie pentru Heap.");
        return -1;
    }

    FILE* in = fopen("third.in", "r");
    if (!in) {
        free(H);
        fprintf(stderr, "ERR: Nu s-a gasit fisierul de intrare.");
        return -1;
    }

    FILE* out = fopen("third.out", "w");
    if (!out) {
        free(H);
        fclose(in);
        fprintf(stderr, "ERR: Nu s-a gasit fisierul de iesire.");
        return -1;
    }

    int n, k, sum = 0, j = 0;

    fscanf(in, "%d %d", &n, &k);

    int* v = (int*)malloc(sizeof(int) * n);
    if (!v) {
        free(H);
        fclose(in);
        fclose(out);
        fprintf(stderr, "ERR: Nu s-a putut aloca memorie pentru un vector.");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        fscanf(in, "%d", &v[i]);
        InsHeap(H, v[i]);
        if (H->nrElem >= k) {
            sum += FindThird(H);
            PopSpecificNumber(H, v[j]);
            j++;
        }
    }

    fprintf(out, "%d", sum);
    DistrugeHeap(H);
    free(v);
    fclose(in);
    fclose(out);
    return 0;
}