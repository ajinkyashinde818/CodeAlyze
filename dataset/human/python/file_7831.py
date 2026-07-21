def main():
    N,K,S = [int(n) for n in input().split()]
    if S == 1:
        A = []
        for i in range(K):
            A.append("1")
        for i in range(N-K):
            A.append("10")
        print(" ".join(A))
        return
    if K==1:
        A = []
        A.append(str(S))
        for i in range(N-1):
            A.append(str(S-1))
        print(" ".join(A))
        return

    if S == 2:
        A = []
        for i in range(K):
            A.append("2")
        for i in range(N-K):
            A.append("10")
        print(" ".join(A))
        return
    # A = []
    # for i in range(N+1):
    #     A.append(S*i)
    # K = N-K
    # for i in range(1,N+1,2):
    #     # print(i)
    #     if K == 1:
    #         A[-1]-=1
    #         break
    #     if K == 0:
    #         break
    #     A[i]-=1
    #     K-=2
    B = []
    for i in range(K):
        B.append(str(S))
    for i in range(N-K):
        B.append(str(S-1))

    print(" ".join(B))
main()
