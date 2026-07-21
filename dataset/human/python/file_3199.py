import collections
import math

N = int(input())

def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        while n % i == 0:
            n /= i
            table.append(i)
        i += 1
    if n > 1:
        table.append(int(n))
    return table


def aaa(num):
    tmp = (math.sqrt(8*num+1)-1)/2
    t = math.floor(tmp)
    return t


c = collections.Counter(prime_decomposition(N))


ans = 0
d = list(c.values())

for i in range(len(d)):
    if d[i] == 1:
        ans += 1
    else:
        ans += aaa(d[i])
        
print(ans)
