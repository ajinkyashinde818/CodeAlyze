def solve():
    r, g, b, n = map(int, input().split())
    cnt = 0
    for i in range(n+1):
        for j in range(n+1):
            x = n-r*i-g*j
            if x % b == 0 and x >= 0:
                cnt += 1
    print(cnt)
    return 0

if __name__ == "__main__":
    solve()
