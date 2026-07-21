n=int(input())
if n==1:
    print(0)
    exit()
def sosuu(n):
    if n == 1:
        return False
    for i in range(2,int(n**0.5)+1):
        if n % i == 0:
            return False
    return True
if sosuu(n):
    print(1)
    exit()
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

 


ff=factorization(n) 
d=[]
ans=0
for i,j in ff:
    tmp=0
    while j>0:
        tmp+=1
        j-=tmp

        if j<0:
            break
        ans+=1
print(ans)
