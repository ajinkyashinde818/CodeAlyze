n = int(input())
if n == 1:
    print(0)
    exit()
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

x = factorization(n)
ans = 0

for i, j in x:
    cnt = 1
    while j >= 1:
        if j == 1:
            ans += 1
            j -= 1
        elif j > 1:
            ans += 1
            j -= cnt
        cnt += 1
        if cnt > j:
            break

print(ans)
