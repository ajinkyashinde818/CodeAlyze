from collections import Counter

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

if __name__ == "__main__":
    n = int(input())
    sosuu_list = prime_factorize(n)
    c = Counter(sosuu_list)
    cnt = 0
    for _, v in c.items():
        i = 1
        while(v > 0):
            v -= i
            i += 1
            cnt += 1
        if v < 0:
            cnt -= 1
    print(cnt)
