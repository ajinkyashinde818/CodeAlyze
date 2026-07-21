from collections import Counter
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

def solv_quadratic_equation(a, b, c):
    """ 2次方程式を解く  """
    D = (b**2 - 4*a*c) ** (1/2)
    x_1 = (-b + D) / (2 * a)
    x_2 = (-b - D) / (2 * a)
    if x_2 > 0:
        return x_2
    else:
        return x_1

n = int(input())
A = Counter(prime_factorize(n))
#print(A)
ans = 0
for (i, j) in A.items():
    c = int(solv_quadratic_equation(1, 1, -2 * j))
    ans += c

print(ans)
