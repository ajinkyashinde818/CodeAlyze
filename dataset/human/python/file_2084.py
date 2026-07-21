def solve():
    n = int(input())
    s = input()
    ans = 1
    mod = 1000000007
    for i in range(26):
        c = chr(ord('a') + i)
        a = s.count(c)
        a = (a + 1) % mod
        ans = (ans * a) % mod

    ans = (ans + mod - 1) % mod
    print(ans)


if __name__ == "__main__":
    solve()
