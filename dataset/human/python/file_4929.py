def main():
    n = int(input())
    a = list(map(int, input().split()))
    mod = 10**9+7
    ans = 0
    fact = 1
    for i in range(2, n):
        fact = fact*i % mod

    fact_2 = [fact]
    for i in range(2, n):
        fact_2.append((fact_2[-1] + fact * pow(i, mod-2, mod) % mod))

    for i in range(n-1):
        ans = (ans + (a[i+1]-a[i])*fact_2[i]) % mod
    print(ans % mod)


main()
