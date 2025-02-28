# Sume partiale

A, S = [], []

with open("secvk.in") as f:
    n, k = f.readline().split()
    n, k = int(n), int(k)

    A.extend([int(elem) for elem in f.readline().split()])

S = [0] + [A[0]] + [0] * (n - 1)
for i in range(2, n):
    S[i] = S[i - 1] + A[i]

st, max = 0, 0
for i in range(1, n - k):
    if S[i + k - 1] - S[i - 1] > max:
        max = S[i + k - 1] - S[i - 1]
        st = i

with open("secvk.out", "w") as f:
    for i in range(st, st + k):
        f.write(str(A[i]) + " ")