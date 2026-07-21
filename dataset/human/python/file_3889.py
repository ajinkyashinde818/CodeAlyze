a=int(input())
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

s=factorization(a) 
ans=0
for i in s:
    if i[0]>1:
        tmp=0
        count=0
        while True:
            tmp+=count
            if i[1]<tmp:
                count-=1
                break
            else:
                count+=1
                
        ans+=count
            
print(ans)
