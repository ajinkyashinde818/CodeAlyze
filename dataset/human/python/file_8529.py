def resolve():
    k, n = map(int, input().split())
    a = list(map(int, input().split()))
    far = 0
    for i in range(n - 1):
        far = max(far, a[i + 1] - a[i])
    far = max(far, k + a[0] - a[-1])
    print(k - far)


if __name__ == '__main__':
    resolve()
