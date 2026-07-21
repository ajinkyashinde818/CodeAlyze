from collections import deque


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i == 0:
                cnt += 1
                temp //= i
            arr.append(cnt)

    if temp != 1:
        arr.append(1)

    if arr == []:
        arr.append(1)

    return arr


n = int(input())
if n == 1:
    print(0)
    exit()
d = factorization(n)
d = deque(d)
count = 0
while d:
    m = 1
    a = d.popleft()
    while a >= m:
        a = a - m
        m += 1
        count += 1

print(count)
