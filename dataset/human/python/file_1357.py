import sys
n=int(input())
a=list(map(int,sys.stdin.readline().strip().split()))
snk=a[0]
rac=sum(a[1:])

s=sum(list(map(abs,a)))
for i in range(1,n-1):
 snk+=a[i]
 rac-=a[i]
 s=min(s,abs(snk-rac))

print(s)
