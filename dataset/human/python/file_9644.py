from collections import defaultdict
n,k=map(int,input().split())
l=list(map(int,input().split()))
d=defaultdict(int)
for i in range(n):
    d[i+1]=l[i]
visited=set()
l=[]
i=1
while True:
    l.append(i)
    if i not in visited:
        visited.add(i)
    else:
        break
    i=d[i]
first=l.index(l[-1])
if k<first:
    print(l[k])
else:
    k=(k-first)%((len(l)-1)-first)
    k+=first
    print(l[k])
