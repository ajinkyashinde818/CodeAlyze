from math import sqrt
from sys import stdin, stdout

int_in = lambda: int(stdin.readline())
arr_in = lambda: [int(x) for x in stdin.readline().split()]
mat_in = lambda rows: [arr_in() for y in range(rows)]
str_in = lambda: stdin.readline().strip()
out = lambda o: stdout.write("{}\n".format(o))
arr_out = lambda o: out(" ".join(map(str, o)))
bool_out = lambda o: out("YES" if o else "NO")
tests = lambda: range(1, int_in() + 1)
case_out = lambda i, o: out("Case #{}: {}".format(i, o))


def prime_factors(n):
    i = 2
    result = []
    while i * i <= n:
        if n % i == 0:
            n //= i
            result.append(i)
        else:
            i += 1
    if n > 1:
        result.append(n)
    return result

def solve(n):
    primes = sorted(prime_factors(n))
    used = set()
    result = 0
    i = 0
    while n > 1 and i < len(primes):
        curr = primes[i]
        while curr in used:
            i += 1
            if i == len(primes):
                return result
            if primes[i - 1] != primes[i]:
                curr = primes[i]
            else:
                curr *= primes[i]
        n //= curr
        used.add(curr)
        result += 1
        i += 1
    return result

if __name__ == "__main__":
    n = int_in()
    out(solve(n))
