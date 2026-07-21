import collections

n=int(input())

if n==1:
    print(0)
    exit()
    
a=[]
M=n
p=2

while p <= M**0.5:
    while n%p ==0:
        a.append(p)
        n = n//p       
        if n==1:
            break
    p += 1
if n!=1:
    a.append(n)
if len(a)==0:
    a.append(M)

c=collections.Counter(a)

x=c.most_common()

ans=0
for i in x:
    ans += int((-1+(1+8*i[1])**0.5)/2)

print(ans)
