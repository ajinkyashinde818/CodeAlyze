def main():
    n, m = map(int, input().split())
    f = [[False]*2 for _ in range(n+1)]
    for _ in range(m):
        a, b = map(int, input().split())
        if a == 1:
            f[b][0] = True
        if b == n:
            f[a][1] = True
    ans = "IMPOSSIBLE"
    for i in range(1, n+1):
        if f[i][0] and f[i][1]:
            ans = "POSSIBLE"
            break
    print(ans)

if __name__ == "__main__":
    main()
