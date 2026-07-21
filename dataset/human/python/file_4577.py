N=int(input())
def factorization(n):
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

plist=factorization(N)
if [1,1] in plist:
    plist.remove([1,1])
elist=[v[1] for v in plist]
ans=0
for e in elist:
    k=0
    n=0
    while n<=e:
        ans+=1
        k+=1
        n+=k
print(ans-len(elist))
