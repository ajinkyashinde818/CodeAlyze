s=input()
q=int(input())
queries = []
rev = [0]*q
flag=0
for i in range(q):
    query = list( input().split() )
    queries.append( query )
    if query==["1"]:
        flag+=1
    rev[i]=flag

n_rev = flag
from collections import deque
left=deque([])
right=deque([])
for r,query in zip(rev,queries):
    if query!=["1"]:
        q1 = query[1]
        q2 = query[2]
        if (r+n_rev)%2==0:
            if q1=="1":
                left.appendleft(q2)
            else:
                right.append(q2)
        else:
            if q1=="1":
                right.append(q2)
            else:
                left.appendleft(q2) 
#     print(i,left,s,right)
if n_rev%2==1:
    s=s[::-1]
print("".join(["".join(left),s,"".join(right)]) )
