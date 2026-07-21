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

divs = factorization(N)

n = len(divs)
ans = 0

for i in range(n):
    div,num = divs[i]
    cnt = 0
    now = 1
    while 1:
        if num >= now:
            num -= now
            now += 1
            cnt += 1
        else:
            break
    ans += cnt
if N == 1:
    print(0)
    exit()
print(ans)
