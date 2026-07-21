if __name__ == '__main__':
    ans = float("inf")
    n = int(input())
    a = list(map(int, input().split()))

    b = [0]*n
    b[0] = a[0]
    for i in range(1,n):
        b[i] = a[i] + b[i-1]

    for i in range(0,n-1):
        ans = min(ans, abs(2*b[i]-b[n-1]))
    print(ans)
