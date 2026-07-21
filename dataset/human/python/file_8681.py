import sys

k,n=map(int,sys.stdin.readline().split())
a=list(map(int,sys.stdin.readline().split()))

max=0
for i in range(n):
    if i==0:
        pre=a[i]
    else:
        now=a[i]
        if now-pre>max:
            max=now-pre
        pre=now
if k-pre+a[0]>max:
    max=k-pre+a[0]
print(k-max)
