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
n = int(input())
l = factorization(n)
ans = 0
for c in l:
    if c[0]==1:
        break
    lim = c[1]
    num = 1
    while lim >= num:
        lim -= num
        num += 1
    ans += num-1
print(ans)
