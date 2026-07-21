def D():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    next = a[0]
    path = [1]
    visited = [True] + [False]*(n-1)
    while not visited[next-1]:
        k -= 1
        if k==0:
            print(next)    
            break
        path.append(next)
        visited[next-1] = True 
        next = a[next-1]
    if k!=0:
        cyclic = path[path.index(next):]
        print(cyclic[k%(len(cyclic))-1])

D()
