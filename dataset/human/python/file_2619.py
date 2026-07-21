def main():
    from itertools import combinations_with_replacement
    from math import ceil

    d, g, *pc = map(int, open(0).read().split())
    p, c = pc[::2], pc[1::2]
    ans = sum(p)
    
    q = ceil(g / (d * 100))
    if q < p[-1]:
        ans = q
        
    l = range(d)
    for x in combinations_with_replacement(l, d):
        y = list(set(x))
        tmp = g
        count = 0
        for i in y:
            tmp -= ((i + 1) * 100 * p[i] + c[i])
            count += p[i]
        if tmp <= 0:
            ans = min(ans, count)
        else:
            j = max(set(l) - set(x))
            k = ceil(tmp / (100 * (j + 1)))
            if k < p[j]:
                count += k
                ans = min(ans, count)

    print(ans)


if __name__ == '__main__':
    main()
