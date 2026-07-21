def solve():
    N,M = map(int, input().split())
    graph = [[] for _ in range(N+1)]
    for _ in range(M):
        a,b = map(int, input().split())
        graph[a].append(b)
        graph[b].append(a)
        
    ret = False
    for cod_1 in graph[1]:
        if N in graph[cod_1]:
            ret = True
            
    print('POSSIBLE' if ret else 'IMPOSSIBLE')
    
solve()
