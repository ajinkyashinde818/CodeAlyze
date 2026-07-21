def solve(N,K,A):
    visited = [None]*N
    cur = 0
    for i in range(K):
        if visited[cur] is None:
            visited[cur] = i
            cur = A[cur]-1
        else:
            break
    else:
        print(cur+1)
        return

    K -= i
    K %= i-visited[cur]

    for i in range(K):
        cur = A[cur]-1

    print(cur+1)


N,K = map(int,input().split())
A = tuple(map(int,input().split()))

solve(N,K,A)
