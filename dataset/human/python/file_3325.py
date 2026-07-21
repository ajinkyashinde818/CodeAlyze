from math import sqrt, floor
N = int(input())

def factorize(n):
    a = []
    count = 0
    temp = n
    if temp % 2 == 0:
        while temp % 2 == 0:
            count += 1
            temp //= 2
        a.append(count)
    for i in range(3,floor(sqrt(n)) + 1,2):
        if temp % i == 0:
            count = 0
            while temp % i == 0:
                count += 1
                temp //= i
            a.append(count)
    if temp != 1: a.append(1)
    #if a == []: a.append(1)
    return a

ans = 0
for i in factorize(N):
    ans += int((-1 + sqrt(1 + 8 * i)) / 2)
print(ans)
