def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])
    if temp!=1:
        arr.append([temp, 1])
    return arr

z = factorization(int(input()))
i = 1
ans = 0
flag = True
while flag:
    flag2 = False
    for j in range(len(z)):
        if z[j][1] >= i:
            z[j][1] -= i
            ans += 1
            flag2 = True

    i += 1
    if flag2 == False: flag = False
print(ans)
