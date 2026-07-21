def solve(N,K,S):
    if K != 0 and K != N:
        for i in range(0, K):
            print(S)
        for i in range(K, N):
            if S == 1:
                print(S+1)
            else:
                print(S-1)
    elif K == 0:
        for i in range(N):
            if S == 1:
                print(S+1)
            else:
                print(S-1)
    elif K == N:
        for i in range(N):
            print(S)
N ,K ,S = map(int,input().split())
solve(N,K,S)
