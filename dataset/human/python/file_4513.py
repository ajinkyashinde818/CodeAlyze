from sys import stdin
import collections
N = int(stdin.readline().rstrip())

def prime_decomposition(n):
    i = 2
    table = []
    while i * i <= n:
        while n % i == 0:
            n /= i
            table.append(i)
        i += 1
    if n > 1:
        table.append(n)
    return table
prime = prime_decomposition(N)

c = collections.Counter(prime)
p = c.values()
cnt = 0
for i in p:
    t=1
    while True:
        i = i-t
        if i<=t:
            cnt += t
            break
        t+=1
print(cnt)
