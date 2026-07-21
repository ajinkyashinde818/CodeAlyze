n = int(input())
ans = 0

if n == 1:
    print(0)
    quit()


def fac(n):
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


li = fac(n)
kaijo = [0, 1, 3, 6, 10, 15, 21, 28, 36, 45]

for i in range(len(li)):
    for j in range(len(kaijo)):
        if kaijo[j] <= li[i][1] < kaijo[j + 1]:
            ans += j

print(ans)
