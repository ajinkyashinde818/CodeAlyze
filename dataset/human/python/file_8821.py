if __name__ == '__main__':
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    dis = [0] * n
    for i in range(n):
        if i == 0:
            dis[i] = a[-1] - a[0]
        else:
            dis[i] = k - a[i] + a[i - 1]
    print(min(dis))
