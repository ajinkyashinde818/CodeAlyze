if __name__ == "__main__":
    K, N = list(map(int, input().split()))
    a = list(map(int, input().split()))
    d = [0 for i in range(N)]
    for i in range(N):
        if i == N - 1:
            d[i] = K - a[i] + a[0]
        else:
            d[i] = a[i+1] - a[i]
    print(sum(d) - max(d))
