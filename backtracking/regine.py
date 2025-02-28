def print_matrice(mat):
    for i in range(len(mat)):
        for j in range(len(mat)):
            if mat[i][0][j] == 0:
                print('-', end=' ')
            else:
                print('*', end=' ')
        print()
    print()

def check(i, j, k, n):
    return (0 <= i < k and 0 <= j < n)

def verificare(bkt, k, n):
    for idx in range(0, k):
        q_i, q_j = idx, bkt[idx][1]
        for inc in range(1, n):
            if check(q_i + inc, q_j + inc, k, n) and bkt[q_i + inc][0][q_j + inc] == 1:
                return False
            if check(q_i + inc, q_j, k, n) and bkt[q_i + inc][0][q_j] == 1:
                return False            
            if check(q_i + inc, q_j - inc, k, n) and bkt[q_i + inc][0][q_j - inc] == 1:
                return False
    return True
            
def backtracking(bkt, queens, k, n):
    if k == n:
        print_matrice(bkt)
        return True
    for i in range(0, n):
        bkt[k] = (queens[i], i)
        if verificare(bkt, k + 1, n):
            if backtracking(bkt, queens, k + 1, n):
                return True
        
n = int(input())
queens = [[1 if i == j else 0 for j in range(n)] for i in range(n)]

backtracking([0 for _ in range(n)], queens, 0, n)