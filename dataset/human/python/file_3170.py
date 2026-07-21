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

ansNums = factorization(N)
ans = 0

for a in ansNums:
    if a[0] == 1:
        break
    cnt = 1
    while a[1] >= cnt:
        a[1] -= cnt
        ans += 1
        cnt += 1

print(ans)
