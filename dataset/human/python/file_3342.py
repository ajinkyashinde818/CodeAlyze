from collections import Counter
from itertools import accumulate
from bisect import bisect_right

def prime_factorization(n):
    '''
    Trial division.
    Input: 
        n : a positive integer
    Output:
        a dictionary of #(each prime factors) of n,
    '''
    result = []
    app = result.append
    if n < 2: return Counter()
    while n % 2 == 0:
        app(2)
        n //= 2
    p = 3
    while p*p <= n:
        while n % p == 0:
            app(p)
            n //= p
        p += 2
    if n > 1: app(n)
    return Counter(result)

cumsum = list(accumulate(range(1, 50)))

N = int(input())
factors = prime_factorization(N)
ans = 0
for _, n in factors.items():
    ans += bisect_right(cumsum, n)
print(ans)
