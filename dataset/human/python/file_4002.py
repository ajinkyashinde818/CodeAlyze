def pfactor(n):
    result = []
    for i in range(2, int(n**0.5)+1):
        while n%i == 0:
            result.append(i)
            n //= i
    
    if n != 1:
        result.append(n)
    return result

  
N = int(input())
factor = pfactor(N)
ans = 0

for p in set(factor):
    i = factor.count(p)
    while i > 0:
        c = (1 + 8*i) ** 0.5
        if c.is_integer():
            ans += (int(c)-1) // 2
            break
        i -= 1

print(ans)
