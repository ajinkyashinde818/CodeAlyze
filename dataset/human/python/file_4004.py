import collections
N = int(input())

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
    c = prime_factorize(N)
    if c == []:
        print(0)
        return
    else:
        coll = collections.Counter(c).values()
        ans = 0
        for i in coll:
            tmp = 0
            while i > 0:
                if(tmp < i):
                    ans += 1
                    tmp += 1
                    i -= tmp
                else:
                    break
        print(ans)
        return

if __name__ == "__main__":
    main()
