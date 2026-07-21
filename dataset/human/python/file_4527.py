def prime(n):
    nums = [True]*n
    primes = []
    for i in range(2,n):
        if nums[i]:
            primes.append(i)
            for j in range(2*i,n,i):
                nums[j] = False
    return primes

def prime_fac(n):
    fac = {}
    primes = prime(int(n**0.5)+1)
    for p in primes:
        while n%p==0:
            fac[p] = fac.get(p,0)+1
            n//=p
    if n > 1:
        fac[n] = 1
    return fac

def main():
    n = int(input())
    fac = prime_fac(n)

    ans = 0
    for i in fac.values():
        ct = 1
        while i >= ct*(ct+1)//2:
            ct += 1
            ans+=1
    print(ans)
main()
