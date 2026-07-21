def main():
    MOD = 10**9 + 7
    n = int(input())
    s = input().rstrip()
    alp = [1]*26
    ans = 0
    for c in s:
        p = ord(c) - ord("a")
        alp[p] += 1
        x = 1
        for i in range(26):
            if i == p:
                continue
            x *= alp[i]
            x %= MOD
        ans += x
        ans %= MOD
    print(ans)

if __name__ == "__main__":
    main()
