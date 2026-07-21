def resolve():
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

    n=int(input())
    fact = dict(Counter(prime_factorize(n)))
    cal={}
    ans=0
    for i in fact.values():
        if i not in cal.keys():
            cal[i]=int(((1+8*i)**(1/2)-1)//2)
        ans+=cal[i]
    print(ans)

if __name__ == '__main__':
    resolve()
