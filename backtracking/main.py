import numpy as np

def verificare(arr, k):
    return len(set(arr[:(k + 1)])) == len(arr[:(k + 1)])

def bkt(arr, k, n):
    if k == n:
        print(arr)
        return None
    for i in range(1, n + 1):
        arr[k] = i
        if verificare(arr, k):
            bkt(arr, k + 1, n)

bkt(np.zeros(3, dtype=int), 0, 3)
