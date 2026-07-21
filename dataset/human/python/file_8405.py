if __name__ == "__main__":
    k, n = map(int, input().split())
    a = list(map(int, input().split()))

    for i in range(n):
        a.append(a[i] + k)

    ans = 2 * k

    for i in range(n):
        tmp = a[i+n-1] - a[i]
        if tmp < ans:
            ans = tmp

    print(ans)
