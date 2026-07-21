def fact(n):
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
if n == 1:
    print(0)
    exit()
D = fact(n)
ans = 0
for _, d in D:
    k = int(d**.5)
    while (k+1)*(k+2)//2 <= d:
        k += 1
    ans += k
print(ans)
