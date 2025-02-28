with open('test.in') as f:
    n, vec = int(f.readline()), list(map(int, f.readline().split()))
vec.sort()