from collections import deque
s=deque(list(input()))
q=int(input())
rev=1

for i in range(q):
    a=list(input().split())
    if a[0]=='1':
        rev*=-1
    else:
        if a[1]=='1':
            if rev>0:
                s.appendleft(a[2])
            else:
                s.append(a[2])
        else:
            if rev>0:
                s.append(a[2])
            else:
                s.appendleft(a[2])

a=[]
for i in range(len(s)):
    a+=s.popleft()    
if rev<0:
    a=a[::-1]
print(''.join(a))
