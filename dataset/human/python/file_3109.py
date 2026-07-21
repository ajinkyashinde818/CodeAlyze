def factorization(n):
    if n==1:
        return [[1,1]]
    temp=n
    ans=[]
    for i in range(2, int(n**0.5+1.01)):
        if temp % i ==0:
            ct=0
            while temp % i == 0:
                temp //= i
                ct += 1
            ans.append([i, ct])
    if temp != 1:
        ans.append([temp, 1])
    return ans

N=int(input())
L=factorization(N)
if N==1:
    print(0)
    exit()
ans=0
for l in L:
    ct=0
    fac=1
    while fac<=l[1]:
        ct+=1
        fac+=ct+1
    ans+=ct
print(ans)
