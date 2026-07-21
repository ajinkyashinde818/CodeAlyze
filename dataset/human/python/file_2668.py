import math

d, g = map(int, input().split()) 
num = []
comp = []
for i in range(d):
    p, c = map(int, input().split())
    num.append(p)
    comp.append(p * (i + 1) * 100 + c)

ans = 9999999999999
for i in range(1 << d):
    pos = i
    cnt = 0
    total = 0
    last = -1
    for j in range(d):
        if pos % 2 == 1:
            total += comp[j]
            cnt += num[j]
        else:
            last = j
        pos //= 2
    if total >= g:
        ans = min(ans, cnt)
    elif last == -1:
        continue
    else:
        rem = g - total
        if rem <= num[last] * (last + 1) * 100:
            cnt += math.ceil(rem / ((last + 1) * 100))
            ans = min(ans, cnt)
print(ans)
