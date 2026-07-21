import math

k,n = map(int,input().split())
li = list(map(int,input().split()))
cnt=k+li[0]-li[-1]

for i in range(len(li)-1):
    if li[i+1]-li[i]>=cnt:
        cnt=li[i+1]-li[i]
print(k-cnt)
