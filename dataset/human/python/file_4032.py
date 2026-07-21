import math
from collections import defaultdict

def main2():
    N = int(input())
    fac = defaultdict(int)
    lim = int(math.sqrt(N))

    for i in range(2, lim + 1):
        while N % i == 0:
            is_p = False
            fac[i] += 1
            N = N // i

        if i == lim:
            if N != 1:
                fac[N] += 1

    ans = 0
    for k, v in fac.items():
        e = 1
        for i in range(10000000):       
            if e <= v:
                ans += 1
                v -= e
                e += 1
            else:
                break
    print(ans)

if __name__ == "__main__":
    main2()
