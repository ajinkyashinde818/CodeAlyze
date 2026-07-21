def main():
    N,K = map(int,input().split())
    A = map(int,input().split())

    doubling = [[0]*(N+1) for _ in range(60)]
    for i,a in enumerate(A):
        doubling[0][i+1] = a
    for i in range(1,60):
        for j in range(1,N+1):
            doubling[i][j] = doubling[i-1][doubling[i-1][j]]
            
    t = 1
    for i in range(59,-1,-1):
        if (K>>i)&1:
            t = doubling[i][t]
    print(t)
main()
