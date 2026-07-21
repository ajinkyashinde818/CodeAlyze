def main():
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    c = list(map(int, input().split()))

    m = 0
    for i in range(n):
        m += b[a[i]-1]
        if i != 0 and a[i] - a[i-1] == 1:
            m += c[a[i-1]-1]

    print(m)

if __name__ == '__main__':
    main()
