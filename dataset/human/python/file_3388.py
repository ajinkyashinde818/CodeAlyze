import math

N = int(input())
Prime = []
ans = 0

def func(n):
    while n % 2 == 0:
        n = n // 2
        Prime.append(2)
    for i in range(3, int(math.sqrt(n)) + 1, 2):
        while n % i == 0:
            n = n //i
            Prime.append(i)
    if n > 2:
        Prime.append(n)

func(N)

for i in set(Prime):
    c = i
    while N % c == 0:
        N = N // c
        ans += 1
        c = c * i

print(ans)
