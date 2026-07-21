def int_(num_str):
    return int(num_str) - 1


N, M = map(int, input().split())
graph = [set() for _ in range(N)]
for _ in range(M):
    a, b = map(int_, input().split())
    graph[a].add(b)
    graph[b].add(a)
for i in range(1, N-1):
    if (0 in graph[i]) and (N-1 in graph[i]):
        print("POSSIBLE")
        break
else:
    print("IMPOSSIBLE")
