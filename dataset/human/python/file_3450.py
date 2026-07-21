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
ans = 0
if n == 1:
    ans = 0
else:
    bunkai = factorization(n)
    for i in bunkai:
        if i[1] < 3:
            ans += 1
        elif i[1] < 6:
            ans += 2
        elif i[1] < 10:
            ans += 3
        elif i[1] < 15:
            ans += 4
        elif i[1] < 21:
            ans += 5
        elif i[1] < 28:
            ans += 6
        elif i[1] < 36:
            ans += 7
        elif i[1] < 45:
            ans += 8
        else:
            ans += 9

print(ans)
