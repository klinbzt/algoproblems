import heapq

heap = []

heapq.heappush(heap, 2)
heapq.heappush(heap, 4)
heapq.heappush(heap, 9)

print(heapq.heappop(heap))