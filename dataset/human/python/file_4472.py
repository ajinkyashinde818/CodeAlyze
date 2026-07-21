def solve(n):
    for i in range(n+2):
        if (i+1)*i//2 > n:
            return i-1

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


    return arr



N = int(input())
li = factorization(N)
ans = 0
for [a,b] in li:
    ans += solve(b)
    
if ans == 0:
    if N != 1:
        ans += 1
print(ans)
