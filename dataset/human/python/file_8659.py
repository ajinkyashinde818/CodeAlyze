if __name__ == "__main__":
    k, n = map(int, input().split())
    k = int(k)
    n = int(n)
    a = list(map(int, input().split()))
    ans = float('inf')

    for start in range(n):
        tmp = 0
        if start == 0:
            tmp = a[-1] - a[start]
        else:
            tmp = k - (a[start] - a[start - 1])
        if ans > tmp:
            ans = tmp

    print(ans)
