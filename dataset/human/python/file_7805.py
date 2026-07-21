def main():
    N,K,S = map(int,input().split())
    A = []
    if N >= K:
        for i in range(K):
            A.append(S)
        tmp = N-K
        for i in range(tmp):
            if S != 1000000000:
                A.append(S+1)
            else:
                A.append(1)
    else:
        for i in range(N):
            A.append(S)

    return A

A = main()
A = map(str,A)
print(' '.join(A))
