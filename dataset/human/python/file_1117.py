def numcount(x):
    ans=[0]*n
    res=1
    for i in range(n-1):
        if x[i]!=x[i+1]:
            ans[x[i]-1]=res
            res=0
        res+=1
    ans[x[n-1]-1]=res
    return ans

n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

a2=numcount(a)
b2=numcount(b)
ans1=False
for i in range(n):
    if a2[i]+b2[i]>n:
        ans1=True
        break


ans2=a2[0]
res=a2[0]
for i in range(n-1):
    res+=a2[i+1]-b2[i]
    ans2=max(ans2,res)


if ans1:
    print("No")
else:
    print("Yes")
    c=[0]*n
    for i in range(n):
        c[(i+ans2)%n]=b[i]
    print(" ".join([str(n) for n in c]))
