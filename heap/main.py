import heapq

with open("heap.in", "r") as inp:
    n = int(inp.readline())
    heap = []

    with open("heap.out", "w") as out:
        for _ in range(n):
            data = list(map(int, inp.readline().split()))
            if data[0] == 1:
                heapq.heappush(heap, -data[1])
            else:
                out.write(str(-heapq.heappop(heap)) + "\n")