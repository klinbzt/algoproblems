import numpy as np

with open('test.in') as f:
    n, vec = int(f.readline()), np.array(list(map(int, f.readline().split())))
np.sort(vec)
