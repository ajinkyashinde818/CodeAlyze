import math
from collections import defaultdict

def prime_fact(n):
    count = defaultdict(int)
    for p in range(2, math.ceil(math.sqrt(n)) + 1):
        while n % p == 0:
            count[p] += 1
            n //= p
    if n != 1:
        count[n] += 1
    return count


def submit():
    n = int(input())
    primes = prime_fact(n)

    ans = 0
    for p, c in primes.items():
        pw = 1
        while c - pw >= 0:
            c -= pw
            ans += 1            
            pw += 1
    print(ans)
            


if __name__ == "__main__":
    submit()
