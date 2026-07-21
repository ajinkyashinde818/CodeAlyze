def C():
    temp = [int(n) for n in input().split()]
    N = temp[0]
    K = temp[1]
    S = temp[2]
    if S == 10**9:
        ans = [str(S)]*K + [str(S-1)]*(N-K)
    else:
        ans = [str(S)]*K + [str(S+1)]*(N-K)
    print(' '.join(ans))
C()
