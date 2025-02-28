import numpy as np
# Algoritm de sortare bazat pe ce am discutat la interclasare!!
# Interclasarea stim ca are complexitate O(n + m), unde n si m

def interclasare(vec, st, mij, dr):
    n, m = (mij - st + 1), dr - mij
    L, R = vec[st : (mij + 1)], vec[(mij + 1): (dr + 1)]

    i, j, k = 0, 0, st
    while i < n and j < m:
        if L[i] < R[j]:
            vec[k] = L[i]
            k += 1
            i += 1
        else:
            vec[k] = R[j]
            k += 1
            j += 1

    while i < n:
        vec[k] = L[i]
        k += 1
        i += 1

    while j < m:
        vec[k] = R[j]
        k += 1
        j += 1

def mergeSort(vec, st, dr):
    if st < dr:
        mij = (st + dr) // 2

        mergeSort(vec, st, mij) #[0, 2], [0, 1]
        mergeSort(vec, mij + 1, dr) #[3, 4]

        interclasare(vec, st, mij, dr)

n, vec = int(input()), np.array(list(map(int, input().split())))

mergeSort(vec, 0, n - 1)

for e in vec:
    print(e, end=' ')