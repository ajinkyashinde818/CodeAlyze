from sys import stdin
import math
def I(): return int(stdin.readline().rstrip())

n = I()
m = n
l = []
for i in range(2,int(math.sqrt(n))+1):
    if n==1 or n<i:
        break
    if n%i==0:
        c = 0
        while n%i==0:
            n//=i
            c += 1
        for j in range(1,c+1):
            l.append(i**j)
    i += 1
if n!=1:
    l.append(n)

l.sort()
ans = 0
for i in l:
    if m==1 or m<i:
        break
    else:
        if not m%i:
            m/=i
            ans += 1

print(ans)
