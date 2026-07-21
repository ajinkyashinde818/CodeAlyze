def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n ** 0.5 // 1)) + 1):
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

dat = factorization(n)
#print(dat)

buf = []

for a,b in dat:
    for j in range(b):
        buf.append(a)
dat.sort(key=lambda x: x[0])

used = dict()
cur = 1
res = 1

for a, b in dat:
    if a == 1:
        continue
    cur = 1
    for i in range(b):
        cur *= a
        if cur not in used:
            used[cur] = True
            res += 1
            cur = 1

print(len(used))
