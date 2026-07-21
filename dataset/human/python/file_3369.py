import math
from collections import Counter
def pf(n):
    l = []
    while n % 2 == 0: 
        l.append(2)
        n = n / 2
    for i in range(3,int(math.sqrt(n))+1,2): 
        while n % i== 0: 
            l.append(i)
            n = n / i 
    if n > 2: 
        l.append(n)
    return l
def count(n):
    i = 1
    sum = 0
    while sum <= n:
        sum += i
        i+=1
    return (i-2)
n = int(input())
l = Counter(pf(n))
ans = 0
for x in l:
    ans += count(l[x])
print (ans)
