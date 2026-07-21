def solve():
    N = int(input())
    S = input()
    MOD= int(1e9)+7

    from collections import Counter
    c = Counter(S)
    ans = 1
    for k in c.keys():
        ans = (ans * (c[k] + 1)) % MOD
    ans = (ans - 1) % MOD

    print(ans % MOD)

if __name__ == "__main__":
    solve()
