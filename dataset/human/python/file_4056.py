import bisect
ans = 0
N = int(input())
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
lis = factorization(N)
suum = [0]*(10**5)
for k in range(1,10**5):
    suum[k] = suum[k-1]+k
for j in range(len(lis)):
    index = bisect.bisect_right(suum,lis[j][1])
    ans += index
    if lis[j][1] >= 1:
        ans -= 1
if N != 1:
    print(ans)
else:
    print(0)
