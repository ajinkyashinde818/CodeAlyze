n = int(input())

if n == 1:
    print(0)
    exit()

import math
def div(m):
    d = {}
    temp = int(math.sqrt(m))+1
    for i in range(2, temp):
        while m%i== 0:
            m //= i
            if i in d:
                d[i] += 1
            else:
                d[i] = 1
    if d == {}:
        d[m] = 1
    else:
        if m in d:
            d[m] += 1
        elif m != 1:
            d[m] =1
    return d

d = div(n)
#print(d)
ans = 0
for k, v in d.items():
    temp = 0
    i = 1
    while True:
        temp += i
        if temp > v:
            break
        i += 1
    #print(k, v, temp, i)
    ans += (i-1)
print(ans)
