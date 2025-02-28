import numpy as np

n = int(input())
with open('test.in', 'w') as f:
    nums = np.random.randint(1, 10000, n)
    f.write(str(n) + '\n')
    for i in range(0, n):
        f.write(str(nums[i]) + ' ')
