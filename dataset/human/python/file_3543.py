from math import sqrt
n=int(input())
rn=int(sqrt(n))
s=[0]*(rn+1)
s[0]=-1
s[1]=-1
t=[0]*(rn+1)
for i in range(2,rn+1):
    if s[i] != 0:
        continue
    s[i] = i
    j = i
    while j < rn + 1:
        t[j] = 1
        j *= i
    for j in range(i * i, rn + 1,i):
        if s[j] == 0:
            s[j] = i

result = 0
last = -1
for i in range(2,rn+1):
    if t[i] == 0:
        continue
    if n % i == 0:
        result += 1
        n //= i
        last =i
if n != 1 and n > rn:
    result += 1
print(result)
