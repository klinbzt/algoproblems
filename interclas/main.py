import heapq

n = int(input())
v = list(map(int, input().split()))
heap = []

for i in range(n):
    heapq.heappush(heap, v[i])

cost, cost_total = 0, 0

while len(heap) > 1:
    cost = heapq.heappop(heap) + heapq.heappop(heap)
    heapq.heappush(heap, cost)
    cost_total += cost

print(cost_total)