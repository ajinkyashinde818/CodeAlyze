import collections

n = int(input())

numbers = []

while n%2 == 0:
    numbers.append(2)
    n //= 2

i = 3
while i*i <= n:
    if n%i == 0:
        numbers.append(i)
        n //= i
    else:
        i += 2

if n != 1:
    numbers.append(n)

factors = collections.Counter(numbers)

ans = 0

for num in factors.values():
    k = 1
    while num >= k:
        num -= k
        ans += 1
        k += 1

print(ans)
