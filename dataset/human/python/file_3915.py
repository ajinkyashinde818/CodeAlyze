import sys
N = int(input())
ans = 0
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

for i, j in factorization(N):
    if i == 1:
        print("0")
        sys.exit()
    n= 1
    while 2*j >= n*(n+1):
        n += 1
        ans += 1
    
print(ans)
