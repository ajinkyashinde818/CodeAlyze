import math
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

n=int(input())
ans=0
if n>1:
    array=factorization(n)
    # print(array)
    ans=0
    for a in array:
        ans+=(-1+math.sqrt(1+8*a[1]))//2
        # print(ans)

print(int(ans))
