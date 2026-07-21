import sys
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

#print(factorization(24)) #[[2, 3], [3, 1]]

N=int(input())
if N==1:
    print(0)
    sys.exit()
A=factorization(N)
#print(A)
ans=0
for i in range(len(A)):
    p=0
    res=A[i][1]
    while res-p>0:
        p+=1
        res-=p
    #print(p)
    ans+=p
print(ans)
