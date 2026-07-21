import itertools

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
    N = int(input())
    primes = list(set(prime_factorize(N)))
    cnt = 0
    while len(primes) != 0:
        d = primes.pop(0)
        e = 1
        # print(d,e)
        # print('===================')
        while N%d**e == 0:
            # print(d,N,e,cnt)
            N = N/(d**e)
            e += 1
            cnt += 1
        #     print(d,N,e,cnt)
        # print('===================')
    print(cnt)

if __name__ == '__main__':
    main()
