def main():
    n, k = map(int, input().split())
    A = list(map(int, input().split()))
    D = [0] * (n+1)
    now = 1
    for i in range(1, k+1):
        tmp = A[now-1]
        if not D[tmp]:
            now = tmp
            D[now] += i
        else:
            pre = D[tmp]
            loop = i - D[tmp]
            print(D.index((k - pre) % loop + pre) if loop > 1 else tmp)
            return
    print(now)
main()
