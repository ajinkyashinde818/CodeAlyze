def resolve():
    n, m = map(int, input().split())
    a = list(input() for _ in range(n))
    b = list(input() for _ in range(m))
    if n == m:
        if a == b:
            print('Yes')
        else:
            print('No')
        exit()
    for i in range(n - m + 1):
        for j in range(n - m + 1):
            part = [ai[j:j + m] for ai in a[i:i + m]]
            if part == b:
                print("Yes")
                exit()
    print("No")


if __name__ == "__main__":
    resolve()
