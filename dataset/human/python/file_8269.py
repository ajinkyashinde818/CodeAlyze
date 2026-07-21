def main():
    n = int(input())
    a = list(map(int, input().split()))
    s = sum(a)
    if s % ((n+1) * n // 2) != 0:
        print('NO')
        return
    s //= ((n+1) * n // 2)

    b = [a[(i+1)%n] - a[i] for i in range(n)]
    for i in range(n):
        b[i] -= s

    for i in range(n):
        if b[i] > 0 or b[i] % n != 0:
            print('NO')
            return
    print('YES')

main()
