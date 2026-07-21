N = int(input())

def factorize(n):#factorize(24) => [[2,3],[3,1]]
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
    if temp!=1:#2*97みたいなとき
        arr.append([temp, 1])
    if arr==[]:#n自体が素数の時
        arr.append([n, 1])
    return arr

ans = 0
for f in factorize(N):
    if f[0]==1:
        continue
    num = f[1]
    i = 1
    while num-i>=0:
        num = num - i
        ans += 1
        i += 1
print(ans)
