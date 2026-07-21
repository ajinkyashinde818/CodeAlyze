import sys
input = sys.stdin.readline
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
    
def div_game(n):
    zs = []
    li = list(set( prime_factorize(n)))
    #print(li)
    for p in li:
        a = 1
        z = 1        
        while n > 1 and n >= z:
            z = p ** a
            if n % z == 0 and z not in zs:
                n = n/z
                zs.append(z)
                #print(p**a,n,z)
            a += 1
    #print(zs)
    return len(zs)

if __name__ == "__main__":
    n = int(input())
    print(div_game(n))
