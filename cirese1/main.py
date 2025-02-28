# Map function in python
# map() is used to apply a given function to every item of an iterable object, and returns a map object which is also
# iterable

# One cool example:
# Let's say we have v = ['hello', 'my', 'naigger']
# In order to 'strip the world of the bad character 'a' we shall call
# map(str.strip('a'), v)

def partialSums(A, n, m) -> list:
    S = [[0] * (m + 1) for _ in range(0, n + 1)]

    for i in range(0, n + 1):
        for j in range(0, m + 1):
            if i == 0 or j == 0:
                S[i][j] = 0
            else:
                S[i][j] = S[i - 1][j] + S[i][j - 1] - S[i - 1][j - 1] + A[i - 1][j - 1]
    return S

A, ans = [], 0
n, m, k = map(int, input().split())

for i in range(n):
    A.append(list(map(int, input().split())))

S = partialSums(A, n, m)
print(S)

for i in range(k):
    i1, j1, i2, j2 = map(int, input().split())
    ans = max(ans, S[i2][j2] - S[i1 - 1][j2] - S[i2][j1 - 1] + S[i1 - 1][j1 - 1])

print(ans)
