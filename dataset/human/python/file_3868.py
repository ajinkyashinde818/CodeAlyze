dim = 7
prime = [1]*(10**dim+1)
from collections import Counter
p = Counter()
p_set = []
for i in range(2,10**dim+1):
    j = i
    if prime[i] != 0:
        p[i] += 1
        p_set.append(i)
        while(j <= 10**dim):
            prime[j] = 0
            j += i

N = int(input())
cnt = 0
for n in p_set:
    if n > N:
        break
    while(1):
        if N%(n**p[n])==0:
            N //= n**p[n]
            cnt += 1
            p[n] += 1
        else:
            break
for n in p_set:
    if n > N:
        break
    while(1):
        if N%n == 0:
            N //= n
        else:
            break
if N > 1:
    cnt += 1
print(cnt)
