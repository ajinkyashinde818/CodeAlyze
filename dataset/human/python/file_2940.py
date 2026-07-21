def solve(n):
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
arr = solve(n)

cnt = 0
for n in arr:
    a=1
    if n[0]==1:
        break
    while n[1]>=a:
        n[1] -= a
        a += 1
        cnt += 1

print(cnt)
