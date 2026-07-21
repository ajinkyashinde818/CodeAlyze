import sys
input = sys.stdin.readline
def prime_factorize(n):
    res = []
    for i in range(2, int(n**0.5)+1):
        if n % i != 0:continue
        ex = 0
        while n % i == 0:
            ex += 1
            n = n//i
        res.append((i, ex))
    if n != 1:res.append((n, 1))
    return res
def main():
    N = int(input())
    p = prime_factorize(N)
    ans = 0
    for v, ex in p:
        current = 1
        while ex > 0:
            ex -= current
            if ex >= 0:
                ans += 1
                current += 1
            else:
                break
    print(ans)
if __name__ == "__main__":
    main()
