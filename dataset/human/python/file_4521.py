n = int(input())

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

s = factorization(n)

if n == 1:
    print(0)
    exit()

count,ans = 1,0
for i in range(len(s)):
    while(s[i][1] >= count):
        ans += 1
        s[i][1] -= count
        count += 1
    count = 1

print(ans)
