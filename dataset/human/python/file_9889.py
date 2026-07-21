def main():
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    da = [[None]*n for _ in range(64)]
    for i in range(n):
        da[0][i] = a[i]-1
    for i in range(1, 64):
        for j in range(n):
            da[i][j] = da[i-1][da[i-1][j]]
    ans = 0
    for i in range(64):
        p = k&1
        if p == 1:
            ans = da[i][ans]
        k//= 2
    print(ans+1)

if __name__ == "__main__":
    main()
