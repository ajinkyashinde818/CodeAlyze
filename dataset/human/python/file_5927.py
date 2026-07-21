def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    res = 0
    bk = 5
    for i in range(n):
        res += b[a[i]-1]
        if a[i] == bk + 1:
            res += c[a[i]-2]
        bk = a[i]

    print(res)

if __name__ == '__main__':
    main()
