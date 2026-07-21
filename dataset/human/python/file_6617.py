import sys
input=sys.stdin.readline
s=input().rstrip()
q=int(input())
count=0
pre=[]
post=[]
for i in range(q):
    l=input().split()
    if len(l)==1:
        count+=1
    else:
        f=int(l[1])
        c=l[2]
        if count%2==0:
            if f==1:
                pre.append(c)
            else:
                post.append(c)
        else:
            if f==1:
                post.append(c)
            else:
                pre.append(c)
if count%2==0:
    pre.reverse()
    for i in pre:
        print(i,end='')
    print(s,end='')
    for i in post:
        print(i,end='')
else:
    post.reverse()
    for i in post:
        print(i,end='')
    n=len(s)
    for i in range(n-1,-1,-1):
        print(s[i],end='')
    for i in pre:
        print(i,end='')
