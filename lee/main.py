import copy
# Algoritmul lui Lee
# Rezolva probleme de Maze: Ai un punct de start (0, 0) intr-o matrice (2d), un punct final (n, m).
#                           Se pune intrebarea care e lungimea minima a drumului de la (0, 0) la (n, m), tinand cont
#                           ca nu toate celule sunt utilizabile.
# 
#                           3x3
#                           0 0 1       
#                           0 1 0
#                           0 0 0

# O (n * m)
# Algoritmul foloseste cozi.
# Alg. functioneza pe principiului Hansel si Gretel, adica marcam in interiorul matricii pe unde am trecut
# In python nu e nevoie sa dai import la nimic pt cozi, pentru ca pratic orice lista e si coada.
di, dj = [0, 0, -1, 1], [-1, 1, 0, 0]

def check_bounds(n, m, i, j):
    return (0 <= i and i < n and 0 <= j and j < m)

def lee(A, start):
    queue = [start]
    A[start[0]][start[1]] = 0

    n, m = len(A), len(A[0])

    while len(queue) > 0:
        i, j = queue.pop(0)

        for k in range(0, 4):
            i_vecin, j_vecin = i + di[k], j + dj[k]
            if check_bounds(n, m, i_vecin, j_vecin) and A[i_vecin][j_vecin] == 0 and (i_vecin != start[0] or j_vecin != start[1]):
                A[i_vecin][j_vecin] = A[i][j] - 1
                queue.append((i_vecin, j_vecin))

def print_matrix(A):
    [print(row) for row in A]
    print()

n = int(input())
A = [list(map(int, input().split())) for _ in range(n)]
# M = [copy.deepcopy(A), copy.deepcopy(A), copy.deepcopy(A)]
# points = [tuple(map(int, input().split())) for _ in range(3)]
points, M = [], [copy.deepcopy(A), copy.deepcopy(A), copy.deepcopy(A)]

for i in range(0, 3):
    points.append(list(map(int, input().split())))
    points[i][0] -= 1
    points[i][1] -= 1
    lee(M[i], (points[i][0], points[i][1]))
    
[print_matrix(mat) for mat in M]

lee(A, (0, 0))
minimum = -1
for i in range(0, 3):
    for j in range(0, 3):
        for k in range(0, 3):
            if i != j and j != k and i != k:
                if minimum == -1:
                    minimum = abs(A[points[i][0]][points[i][1]] + M[i][points[j][0]][points[j][1]] + M[j][points[k][0]][points[k][1]] + M[k][n - 1][n - 1])
                else:
                    minimum = min(minimum, abs(A[points[i][0]][points[i][1]] + M[i][points[j][0]][points[j][1]] + M[j][points[k][0]][points[k][1]] + M[k][n - 1][n - 1]))
# 4 matrici
# Lee -> calculeaza distanta de la un punct la (istart, jstart) la toate punctele

# 4 matrici
# (0, 0) direct A
# pct 1
# pct 2
# pct 3

# 0, 1, 2
# 0, 2, 1
# ...

# A[primul punct ales] + MatriceaP1[P2] + MatriceaP2[P3] + MatriceaP3[(n,n)]

print(minimum) 