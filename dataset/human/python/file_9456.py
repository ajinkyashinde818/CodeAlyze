def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    to = [[None]*n for _ in range(60)]
    to[0] = a[:]
    for i in range(1, 60):
        for j in range(n):
            to[i][j] = to[i-1][to[i-1][j]-1]
    p = 1
    for i in range(59, -1, -1):
        num = 1 << i
        if k >= num:
            k -= num
            p = to[i][p-1]
    print(p)
            

if __name__ == "__main__":
    main()
