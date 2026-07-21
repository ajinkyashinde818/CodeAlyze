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

num = int(input())
val = factorization(num)
ans = 0
for x in val:
    if x[0] == 1: break
    val = 0
    for i in range(40):
        val += i + 1
        if x[1] < val:
            ans += i
            break
print(ans)
