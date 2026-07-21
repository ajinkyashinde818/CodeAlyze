def resolve():
    K, N = map(int, input().split())
    A = list(map(int, input().split()))
    B = [max(A)-min(A)]
    for i in range(N-1):
        B.append(A[i+1]-A[i])
    for j in B:
        if j > K/2:
            B.remove(j)
            B.append(K-j)
    print(K-max(B))
resolve()
