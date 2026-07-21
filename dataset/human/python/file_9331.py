def solve(N, K, A):
    idx = [-1 for _ in range(len(A))]
    now = 0
    period = 0
    bias = 0
    tmp = []
    found = False
    i = 0
    while not found:
        tmp.append(now+1)
        if idx[now] == -1:
            idx[now] = i
        else:
            period = i - idx[now]
            cycle = tmp[-period-1:-1]
            bias = i - period
            break
        now = A[now]-1
        i += 1

    if K <= bias:
        now = 0
        for _ in range(K):
            now = A[now] - 1
        print(now + 1)
    else:
        K -= bias
        K = K % period
        print(cycle[K])

if __name__=="__main__":
    N,K = [int(a) for a in input().split()]
    A = [int(a) for a in input().split()]
    solve(N, K, A)
