n = int(input())
def make_divisors(n):
    divisors = []
    for i in range(1, int(n**0.5)+1):
        if n % i == 0:
            divisors.append(i)
            if i != n // i:
                divisors.append(n//i)
    divisors.sort()
    return divisors

def prime_factor(n):
    factors = []
    for i in range(2, int(n**0.5)+1):
        count = 0
        while n % i == 0:
            count += 1
            n //= i
        if count != 0:
            factors.append((i, count))
    if n != 1:
        factors.append((n, 1))
    return factors

seen = set()
flag = True
ans = 0
while flag:
    flag = False
    div = make_divisors(n)
    for i in div:
        if len(prime_factor(i)) == 1 and i not in seen:
            seen.add(i)
            n /= i
            ans += 1
            flag = True
            break
print(ans)
