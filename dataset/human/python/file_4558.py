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


n = int(input())

z = []

f = sorted(factorization(n), key=lambda x: x[1], reverse=True)
# print(f)
for i in range(len(f)):
    if f[i][1] < 0:
        f[i][1] = -1 * f[i][1]

for i in range(len(f)):
    for j in range(1, f[i][1] + 1):
        if f[i][0] == 1:
            continue
        f[i][1] -= j
        if f[i][1] >= 0:
            z.append(f[i][0] ** j)
# print(z)
print(len(z))
