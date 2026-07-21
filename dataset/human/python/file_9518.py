def solve():
    N,K = map(int,input().split())
    A = list(map(int,input().split()))

    now = 1
    n_move = 0
    graph = []
    visited = set()
    while True:
        graph.append(now)
        visited.add(now)
        now = A[now-1]
        n_move += 1
        if now in visited:
            break

    loop_start = now
    to_loop_start = 0
    for i in range(len(graph)):
        if graph[i] == loop_start:
            to_loop_start = i
    
    per_loop = n_move - to_loop_start
    
    if K <= to_loop_start:
        print(graph[K])
    else:
        print(graph[to_loop_start + (K-to_loop_start) % per_loop])

if __name__ == '__main__':
    solve()
