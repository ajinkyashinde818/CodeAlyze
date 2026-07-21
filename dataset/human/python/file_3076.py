def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])

    if temp != 1:
        arr.append([temp, 1])

    if arr == []:
        arr.append([n, 1])

    return arr


N = int(input())
if N == 1:
    print(0)
    exit(0)

ar = factorization(N)
ans = 0
for i in range(len(ar)):
    tmp = 0
    for j in range(1, 100):
        tmp += j
        if tmp > ar[i][1]:
            ans += j-1
            break

print(ans)
