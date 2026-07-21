import math
N = int(input())
if N == 1:
    print(0)
    exit()
div = {}
for i in range(2, int(math.sqrt(N))+1):
    while N % i == 0:
        N = N // i
        if i in div:
            div[i] += 1
        else:
            div[i] = 1
    if N == 1:
        break
if N != 1:
    div[N] = 1
ans = 0
for v in div.values():
    i = 1
    while v >= i:
        v -= i
        i += 1
        ans += 1
print(ans)
