def fac(n):
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
        arr.append([n, 0])

    return arr
n = int(input())
p = fac(n)
ans = 0
for i in range(len(p)):
    for j in range(1,10001):
        if j*(j-1)/2 <= p[i][1] < j*(j+1)/2:
            ans += j-1
            break
        else:
            continue
print(ans)
