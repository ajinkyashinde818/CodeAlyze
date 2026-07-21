N = int(input())

def p_adic_valuation_factorial(n, p):
    result = 0
    pow_p = p
    while n >= pow_p:
        result += n // pow_p
        pow_p *= p
    return result

if N % 2 == 0:
    e2 = N // 2 + p_adic_valuation_factorial(N // 2, 2)
    e5 = p_adic_valuation_factorial(N // 2, 5)
    result = min(e2, e5)
else:
    result = 0
print(result)
