def f(i):
    while True:
        a[i]=(a[i]+1)%10
        if a[i]==0: i+=1
        else: break

s=input()
a=[]
for i in range(len(s)-1,-1,-1):
    a.append(int(s[i]))
a.append(0)

ans=0
for i in range(len(a)-1):
    if a[i]<5: ans+=a[i]
    elif a[i]==5:
        if a[i+1]<5: ans+=5
        else:
            ans+=5
            f(i+1)

    else:
        ans+=10-a[i]
        f(i+1)

if a[-1]!=0: ans+=1

print(ans)
