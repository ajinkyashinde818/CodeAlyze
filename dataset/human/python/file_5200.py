def resolve():
    '''
    code here
    '''
    import collections
    N, M = [int(item) for item in input().split()]
    edges = [[int(item) for item in input().split()] for _ in range(M)]
    
    togo = [[] for _ in range(N+1)]
    for f, t in edges:
        togo[f] += [t]
    
    is_found = False

    que = collections.deque()
    for goto in togo[1]:
        que.append(goto)

    is_found = False
    while que:
        node = que.popleft()
        for next_node in togo[node]:
            if next_node == N:
                is_found = True
            # print(next_node, is_found)
            
    print('POSSIBLE') if is_found else print('IMPOSSIBLE')

if __name__ == "__main__":
    resolve()
