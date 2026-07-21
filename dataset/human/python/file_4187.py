def factorization(n):
    arr=[]
    tmp=n
    for i in range(2,int(n**0.5)+1):
        if(tmp%i==0):
            cnt=0
            while tmp%i==0:
                cnt+=1
                tmp//=i
            arr.append([i,cnt])
    if(not arr):
        arr.append([1,1])
    if(tmp!=1):
        arr.append([tmp,1])
    return arr

N=int(input())
if N==1:
    print(0)
    exit()
arr=factorization(N)
ans=0
for i in range(len(arr)):
    if arr[i][0]==1:
        continue
    cnt=1
    while arr[i][1]>0:
        if arr[i][1]>=cnt:
            arr[i][1]-=cnt
            ans+=1
            cnt+=1
        else:
            break
print(ans)
