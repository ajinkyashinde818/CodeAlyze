def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append(cnt)
    if temp!=1:
        arr.append(1)
    if arr==[]:
        arr.append(1)
    return arr

def calc(n):
    val = 1
    count = 0
    for i in range(2,100000):
        count += 1
        val = val + i
        if val > n:
            return count

N = int(input())
if N == 1:
    print(0)
    exit(0)

arr = factorization(N)

ans = 0 
for val in arr:
    ans += calc(val)
 
print(ans)
