n = int(input())

if n == 1:
    print(0)
    exit()

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

li = factorization(n)
ans = 0

for a,b in li:
    tmp = 0
    while tmp * (tmp+1) // 2 <= b:
        tmp += 1
    ans += tmp - 1

print(ans)
