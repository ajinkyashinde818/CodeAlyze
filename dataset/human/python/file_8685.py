import heapq

k, n = map(int, input().split())
a = [int(x) for x in input().split()]
qa = []
heapq.heapify(qa)

for x in range(len(a) - 1):
    heapq.heappush(qa, abs(a[x] - a[x + 1]))
heapq.heappush(qa, k - a[-1] + a[0])

dis = 0
for x in range(len(qa) - 1):
    dis += heapq.heappop(qa)

print(dis)
