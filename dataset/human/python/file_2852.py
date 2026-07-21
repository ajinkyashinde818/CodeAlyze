from sys import stdin
def solve():
    n = int(stdin.readline())
    ans = 0
    if n == 1: return 0
    prime = {}
    i = 2
    while i**2 <= n:
        if n%i != 0:
            i += 1
            continue
        ex = 0
        while n%i == 0:
            ex += 1
            n //= i
        prime[i] = ex
    if n != 1: prime[n] = 1
    for key in prime:
        cur = 1
        while prime[key] >= cur:
            ans += 1
            prime[key] -= cur
            cur += 1
    return ans

print(solve())
