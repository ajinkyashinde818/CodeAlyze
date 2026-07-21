import math

def f(n):
    arr = list()
    temp = n
    for i in range(2, int(math.sqrt(n)) + 1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append(tuple([i, cnt]))

    if temp != 1:
        tup = tuple([temp, 1])
        arr.append(tup)

    if len(arr) == 0:
        tup = tuple([n, 1])
        arr.append(tup)

    return arr

N = int(input())
if N == 1:
    print(0)
    exit()

t = f(N)
res = 0

for a in t:
    cnt = 0
    c = 0
    while cnt <= a[1]:
        c += 1
        cnt += c
    res += c - 1
    
print(res)
