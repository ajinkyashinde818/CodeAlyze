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

N = int(input())
if N == 1:
    print(0)
    sys.exit()
a = factorization(N)
ans = 0

for i in range(len(a)):
    k = a[i][1]
    cnt = 1
    while k-cnt>=0:
        k -= cnt
        cnt += 1
    ans += cnt-1
    
    
print(ans)
