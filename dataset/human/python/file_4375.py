import math
import functools

def main():
    n = int(input())
    ans = solve(n)
    print(ans)

def solve(n):
    if n == 1:
        return 0
    cnt = [[i] * (i + 1) for i in range(20)]
    cnt = [i for inner in cnt for i in inner]
    factor = prime_factorization(n)
    ans = 0
    for p, e in factor:
        ans += cnt[e]
    return ans

def prime_factorization(n):
    nn = n
    lim = math.floor(n ** (1 / 2))
    primelist = prime_list(lim)
    ans = []
    for p in primelist:
        if n % p == 0:
            e = 0
            while n % p == 0:
                e += 1
                n /= p
            ans.append((p, e))
    if ans == []:
        ans.append((n, 1))
    tmp = functools.reduce(lambda x, y: x * y, [p ** e for p, e in ans])
    if tmp != nn:
        ans.append([int(nn / tmp), 1])
    return ans

def prime_list(n):
    if n < 2:
        return []
    tmp = [True for i in range(n + 1)]
    tmp[:2] = [False, False]
    for i in range(n + 1):
        if tmp[i]:
            for j in range(2 * i, n + 1, i):
                tmp[j] = False
    ans = [num for num, flag in enumerate(tmp) if flag]
    return ans

def test():
    n = int(input())
    ans = prime_factorization(n)
    print(*ans, sep = '\n')

if __name__ == '__main__':
    main()
