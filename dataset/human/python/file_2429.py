from math import ceil


def main():
    d, g = [int(x) for x in input().split()]
    pcs = [[int(x) for x in input().split()] for _ in range(d)]
 
    def rec(g, i):
        nonlocal pcs
        if i <= 0:
            return float('inf')

        p, c = pcs[i-1]
        s = 100 * i
        n = min(ceil(g/s), p)
        score = s * n + c if n == p else s * n

        if score >= g:
            m = n
        else:
            m = n + rec(g-score, i-1)

        r = min(m, rec(g, i-1))
        #print(g, i, r)
        return r


    print(rec(g, d))

main()
