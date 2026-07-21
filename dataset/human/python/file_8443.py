def resolve():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    
    dis = [0]*N
    for i in range(N-1):
        dis[i] = A[i+1]-A[i]
    dis[N-1] = K-A[N-1]+A[0]
    ans = K-max(dis)
    
    print(ans)
resolve()
