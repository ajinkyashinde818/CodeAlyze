x=int(input())
def cal(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a
num=cal(x)
numset=sorted(list(set(num)))
cnt=[0]*len(numset)
now=0
for i in range(len(num)):
    if numset[now]==num[i]:
        cnt[now]+=1
    else:
        now+=1
        cnt[now]+=1
ans=0
for j in range(len(cnt)):
    s=1
    plu=2
    c=0
    flag=0
    while flag!=1:
        if s<=cnt[j]:
            c+=1
            s+=plu
            plu+=1
        else:
            ans+=c
            flag=1
print(ans)
