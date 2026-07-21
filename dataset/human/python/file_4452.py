from collections import defaultdict
n = int(input())
d = defaultdict(int)
for i in range(2, int(n**0.5)+1):
    while(n%i == 0):
        n//=i
        d[i]+=1
if n > 1:
    d[n]+=1
ans = 0
for i in d.values():
    val = 1
    while i >= val:
        i-=val
        ans+=1
        val+=1
print(ans)
