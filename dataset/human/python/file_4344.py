from collections import Counter as ct

N = int(input())
res = []
x = N
y = 2
while y*y <= x:
    while x % y == 0:
        res.append(y)
        x //= y
    y += 1
if x > 1:
    res.append(x)

res = ct(res)
cnt = 0
for i in res.values():
    tmp = 1
    for j in range(1, i + 1):
        i -= j
        if i >= 0:
            cnt += 1
        else:
            break
print(cnt)
