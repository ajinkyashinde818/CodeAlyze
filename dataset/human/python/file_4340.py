import collections
n=int(input())
a=[]
count=0
while n%2==0:
    a.append(2)
    n=n/2
num=3
while num**2<=n+1:
    if n%num==0:
        a.append(num)
        n=n/num
    else:
        num+=2
if n!=1:
    a.append(n)
a=collections.Counter(a)
for i in a.values():
    x=1
    while x<=i:
        count+=1
        i-=x
        x+=1
print(count)
