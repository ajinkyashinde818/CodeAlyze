"""素因数分解"""
def prime_decomposition(n):
    i = 2
    tank = []
    while i * i <= n:
        while n%i == 0:
            n /= i
            tank.append(i)
        i += 1
    if n > 1:
        tank.append(int(n))
    return tank

from collections import Counter

n = int(input())
if n==1:
    print(0)
    exit()

lst = prime_decomposition(n)
c = Counter(lst)
ans = 0

for k,v in c.items():
    j = 1
    while True:
        if j*(j+1)//2 <=v:
            j += 1
        else:
            break
    ans += j-1
print(ans)
