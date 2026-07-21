import sys
read = sys.stdin.buffer.read

N,C, *XV = map(int, read().split())#全部
X=XV[::2]
V=XV[1::2]

m1=[0]
m2=[0]

s=0
ans=0
for x,v in zip(X,V):
    s+=v
    ans=max(ans,s-x)
    m1.append(max(m1[-1],s-x))
    m2.append(max(m2[-1],s-2*x))
s=0
i=0
for x,v in reversed(list(zip(X,V))):
    s+=v
    x=C-x
    ans=max(ans,s-2*x+m1[-2-i],s-x+m2[-2-i])
    i+=1
print(ans)
