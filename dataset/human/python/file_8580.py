import heapq

K, N = map(int, input().split())

A = list(map(int, input().split()))


dis = [-abs(A[i + 1] - A[i]) for i in range(N - 1)] + [-abs(abs(A[0]) + abs(K - A[N - 1]))]


heapq.heapify(dis)

heapq.heappop(dis)

print(-sum(dis))
