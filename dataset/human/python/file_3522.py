n=int(input())
def fact(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
    if temp!=1:
        arr.append([temp, 1])
    if arr==[]:
        arr.append([n, 1])
    return arr
if n==1:
    print(0)
    exit()

f = fact(n)
ans=0
for itm in f:
    p,num=itm
    nxt=1
    while num > 0:
        if nxt<=num:
            ans+=1
            num-=nxt
            nxt+=1
        else:
            break
print(ans)
