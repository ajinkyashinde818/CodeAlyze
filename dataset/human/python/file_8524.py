def resolve():
    k, n = map(int, input().split())
    A = list(map(int, input().split()))
    B=[]
    for i in range(n-1):
        B.append(A[i+1]-A[i])
    B.append(k-A[n-1]+A[0])
    print(k-max(B))
resolve()
