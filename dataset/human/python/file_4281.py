from collections import defaultdict

def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a


def main():
    n = int(input())
    pfactor = prime_factorize(n)
    d = defaultdict(int)
    for p in pfactor:
        d[p] += 1
    hoge = []
    a = 0
    for i in range(100):
        tmp = 1 + i
        a += tmp
        hoge.append(a)
    cnt = 1
    score = []
    for i, j in zip(hoge[:-1], hoge[1:]):
        for _ in range(j - i):
            score.append(cnt)
        cnt += 1
    res = 0
    for v in d.values():
        res += score[v-1]
    print(res)

     

if __name__ == '__main__':
    main()
