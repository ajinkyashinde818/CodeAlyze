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
 
n = int(input())
numlist = factorization(n)
result = 0
for i in numlist:
    k = 0
    for j in range(n):
        if(k*(k+1)/2 > i[1]):
            k-=1
            break
        else:
            k+=1
    result+=k
if(n == 1 ):
    result = 0
print(result)
