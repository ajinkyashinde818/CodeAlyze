import sys
input=sys.stdin.readline
ns=input().rstrip()
ans=0
l=[]
ls=len(ns)
for i in range(ls):
    l.append(int(ns[ls-1-i]))
for i in range(10**6+1-ls):
    l.append(0)
for i in range(10**6+1):
    if 0<=l[i]<=4:
        ans+=l[i]
    elif 6<=l[i]<=9:
        ans+=10-l[i]
        l[i+1]+=1
    elif l[i]==10:
        l[i+1]+=1
    elif l[i]==5:
        ans+=5
        if 0<=l[i+1]<=4:
            pass
        else:
            l[i+1]+=1
print(ans)
