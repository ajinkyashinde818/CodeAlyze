import collections

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

N = int(input())
c = collections.Counter(prime_factorize(N))

result = 0
for i in c.values():
    temp = 0
    temp_sum = 0
    while True:
        temp += 1
        temp_sum += temp
        if temp_sum > i:
            break
    result += (temp-1)
        
print(result)
