from collections import Counter

def solve():
    N = int(input())

    def getPrimeFactors(x):
        anss = []
        while x%2 == 0:
            anss.append(2)
            x //= 2
        for d in range(3, int(x**0.5)+1, 2):
            while x%d == 0:
                anss.append(d)
                x //= d
        if x != 1:
            anss.append(x)
        return anss

    PFs = getPrimeFactors(N)
    cnt = Counter(PFs)

    ans = 0
    for p, e in cnt.items():
        for i in range(1, 50):
            if e >= i:
                ans += 1
                e -= i

    print(ans)


solve()
