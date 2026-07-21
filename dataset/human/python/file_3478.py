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
def check(n):
    ans=1
    c=0
    for i in range(1,100):
        c+=i
        if(n<c):
            break
        ans=i
    return ans

N=int(input())
if(N>1):
    arr=factorization(N)
    ans=0
    for i in range(len(arr)):
        ans+=check(arr[i][1])
    print(ans)
else:
    print(0)
