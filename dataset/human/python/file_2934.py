from collections import Counter
import sys

def prime_factorize(n):
    ans = []
    while not n%2:
        ans.append(2)
        n //= 2
    mod = 3
    while mod**2 <= n:
        if n%mod == 0:
            ans.append(mod)
            n //= mod
        else:
            mod += 2
    if n != 1:
        ans.append(n)
    counter = Counter(ans)
    return counter


def main():
    input = sys.stdin.readline
    n = int(input())
    primes = prime_factorize(n)
    ans = 0
    for v in primes.values():
        value = v
        if value <= 2:
            ans += 1
            continue
        ans += 1
        value -= 2
        k = 3
        while value > 0:
            value -= k
            k += 1
            ans += 1
            
          
    print(ans)
    
    
if __name__ == "__main__":
    main()
