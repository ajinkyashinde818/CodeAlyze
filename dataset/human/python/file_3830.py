n = int(input())

def isPrime(n):
    i = 2
    while i * i <= n:
        if n % i == 0:
            return False
        i += 1
    return True

def f(n):
    if n == 0:
        return 0
    i = 1
    while not(i * (i + 1) // 2 <= n and n < (i + 1) * (i + 2) // 2):
        i += 1
    return i

p = {}

answer = 0
if n % 2 == 0:
    c = 0
    while n % 2 == 0:
        n //= 2
        c += 1
    answer += f(c)

q = 3
while q * q <= n:
    c = 0
    while n % q == 0:
        n //= q
        c += 1
    answer += f(c)
    q += 2

if n > 1:
    answer += 1
print(answer)
