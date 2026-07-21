import heapq
from collections import defaultdict
N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

d = defaultdict(list)
for i in range(N):
    a = A[i]
    b = B[i]
    if a==b:
        d[a].append(i)

h = []
for a in d:
    heapq.heappush(h,(-len(d[a]),a))

while len(h)>=2:
    x,a = heapq.heappop(h)
    y,b = heapq.heappop(h)
    i = d[a].pop()
    j = d[b].pop()
    B[i],B[j] = B[j],B[i]
    x += 1
    y += 1
    if x<0:
        heapq.heappush(h,(x,a))
    if y<0:
        heapq.heappush(h,(y,b))

if h:
    x,a = heapq.heappop(h)
    d[a] = d[a][::-1]
    for i in range(N):
        if len(d[a])==0:
            break
        if A[i] != a and B[i] != a:
            j = d[a].pop()
            B[i],B[j] = B[j],B[i]

ans = "Yes"
for i in range(N):
    if A[i]==B[i]:
        ans = "No"

print(ans)
if ans=="Yes":
    print(*B)
