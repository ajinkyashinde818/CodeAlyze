def main():
    n = int(input())
    a = list(map(int,input().split()))
    x = a[0]
    y = sum(a) - x
    x_y = abs(x - y)
    for i in range(1, n - 1):
        x += a[i]
        y -= a[i]
        x_y = min(x_y, abs(x - y))
    print(x_y)

if __name__ == '__main__':
    main()
