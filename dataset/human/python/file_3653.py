from collections import Counter
n = int(input())
tmp = n
d = []
for i in range(2, int(n ** 0.5) + 1):
    if tmp % i == 0:
        while tmp % i == 0:
            d.append(i)
            tmp //= i
if tmp != 1:
    d.append(tmp)

dv = Counter(d)

cnt = 0
for p in dv.keys():
    for e in range(1, dv[p]+1):
        z = p ** e
        if n % z == 0:
            cnt += 1
            n //= z

print(cnt)
