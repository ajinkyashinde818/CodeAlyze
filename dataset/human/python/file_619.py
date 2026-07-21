from datetime import datetime as dt
N = int(input())
Ns = list(map(int,input().split(" ")))

l1 = len(Ns)
c = 0
for i in Ns:
    if i <= 0:
        c += 1

Ns = list(map(abs,Ns))
if c % 2 == 0:
    diff = 0
else:
    diff = min(Ns)
ans = sum(Ns) -2*diff
print(ans)
