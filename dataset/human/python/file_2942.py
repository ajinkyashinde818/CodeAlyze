import math
n = int(input())

def is_prime(num):
    if num == 2:
        return True
    elif num <  3 or num % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(num)) + 1, 2):
        if num % i == 0:
            return False
    return True


c = []
for i in range(1, int(math.sqrt(n))+1):
    if n%i == 0:
        k = n//i
        if is_prime(k):
            c.append(k)
        if is_prime(i):
                c.append(i)

d = {}
ans = 0
for i in set(c):
    while n%i == 0:
        n //= i
        if i in d:
            d[i] += 1
        else:
            d[i] = 1

ans = 0
for v in d.values():
    for i in range(1, 41):
        if v >= i:
            v -= i
            ans += 1
        else:
            break
print(ans)
