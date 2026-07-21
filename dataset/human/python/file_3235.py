def prime_factorize(n):
    '''引数nの因数分解結果のlistを返す。'''
    arr = []
    while n % 2 == 0:
        arr.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            arr.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        arr.append(n)
    return arr

def main():
    n = int(input())
    f = set(prime_factorize(n))
    s = set()
    for p in f:
        e = 1
        z = p ** e
        while z <= n:
            if n % z == 0:
                if z not in s:
                    n //= z
                    s.add(z)
            e += 1
            z = p ** e
    print(len(s))
        
if __name__ == '__main__':
    main()
