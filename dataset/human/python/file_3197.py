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
if n == 1:
    print(0)
    exit()

a = factorization(n)
#print(a)

ans = 0
for i in range(len(a)):
    check = 1
    while a[i][1] >= check:
        a[i][1] = a[i][1] - check
        ans = ans + 1
        check = check + 1

print(ans)
