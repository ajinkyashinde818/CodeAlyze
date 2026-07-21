import math
from collections import Counter
def solve():
    N = int(input())
    primeFac = prime_factorize(N)
    counter = Counter(primeFac)
    divisors = []
    for key, val in counter.items():
        for i in range(1,val+1):
            divisors.append(pow(key,i))

    divisors.sort()
    now = N
    ans = 0
    for d in divisors:
        if now % d == 0:
            ans += 1
            now //= d
    
    print(ans)

def prime_factorize(n):
    prime_numbers = []
    for p in range(2, int(math.sqrt(n)+1)):
        if n % p != 0:
            continue
        while n % p == 0:
            n /= p
            prime_numbers.append(p)

    if n != 1:
        prime_numbers.append(n)
    return prime_numbers
    
if __name__ == '__main__':
    solve()
