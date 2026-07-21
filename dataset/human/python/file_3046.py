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
arr = factorization(n)
#print(arr)
if(n==1):
    print(0)
    exit()
ans = 0
for i in arr:
    for j in range(1,1000):
        if(i[1]+1<=j*(j+1)//2):
            ans += j-1
            break

print(ans)
