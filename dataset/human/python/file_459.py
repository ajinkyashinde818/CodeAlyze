import heapq
N = int(input())
A = list(map(int, input().split()))
heapq.heapify(A)
while True:
  m = heapq.heappop(A)
  n = heapq.heappop(A)
  if m + n >= 0:
    heapq.heappush(A, m)
    heapq.heappush(A, n)
    break
  else:
    heapq.heappush(A, -m)
    heapq.heappush(A, -n)
print(sum(A))
