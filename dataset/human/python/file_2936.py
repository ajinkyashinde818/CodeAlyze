def prime_factors(n):
    i = 2
    factors = {}
    while i * i <= n:
        if n % i:
            i += 1
        else:
            n //= i
            if i not in factors:
                factors[i] = 0
            factors[i] += 1
    if n > 1:
        if n not in factors:
            factors[n] = 0
        factors[n] += 1
    return factors


def count(factor_count):
    result = 0
    for i in range(1, 10000000000):
        if factor_count < i :
            break
        result += 1
        factor_count -= i
    return result


def solve(n):
    ans = 0
    pfactors = prime_factors(n)
    for factor in pfactors:
        ans += count(pfactors[factor])
    return ans


n = int(input())
print(solve(n))
