n=int(input())
d={}

for i in range(2, int(n**0.5)+1):
    while n % i == 0:
        if n<2:
            break
        d[i] = d.get(i, 0)+1
        n //=i
    if n<2:
        break
if n>1:
    d[n] = 1
def get(n):
    cur, total = 0, 0
    while cur+total<n:
        cur +=1
        total +=cur
    return cur
ans = 0
for v in d.values():
    ans += get(v)
print(ans)
