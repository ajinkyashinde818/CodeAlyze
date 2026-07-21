s=list(input())
import collections 
D=collections.deque(s)
counter=0
lastindex=0
q=int(input())
for i in range(q):
    a=list(input().split())
    if int(a[0])==1:
        counter+=1

    else:
        if (counter+int(a[1]))%2==0:
            D.append(a[2])
        else:
            D.appendleft(a[2])
if counter%2==0:
    D=list(D)
    print("".join(D))
else:
    D=list(D)[::-1]
    print("".join(D))
