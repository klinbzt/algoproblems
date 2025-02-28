import heapq

n, k, A, B, C, D = list(map(int, input().split()))

heap = [A]
for _ in range(n):
    A = (B * A + C) % D
    heapq.heappush(heap, -A)

for _ in range(k):
    arr.append(-heapq.heappop(heap))

arr.reverse()

for a in arr:
    print(a, end = ' ')