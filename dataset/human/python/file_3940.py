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


f = factorization(N)
total = 0
for c in f:
    if c[0] == 1:
        continue
    target = c[1]
    cnt = 0
    for i in range(1, c[1] + 1):
        target -= i
        if target < 0:
            break
        cnt += 1
    total += cnt

print(total)
