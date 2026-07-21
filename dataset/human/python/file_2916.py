import collections
def prime_factor(n):
    res = collections.Counter()
    i = 2
    while i*i <= n:
        while n % i == 0:
            res[i] += 1
            n //= i
        i += 1
    if n != 1:
        res[n] = 1
    return res

def solve(n):

    tmp = prime_factor(n)

    ans = 0
    x = 0
    for v in tmp.values():
        i = 1
        while i <= v: 
            if v - i >= 0:
                v -= i
                ans += 1
            else:
                x += 1
            i += 1
    ans += x // 2
    return ans


if __name__ == "__main__":
    n = int(input())
    print(solve(n))
