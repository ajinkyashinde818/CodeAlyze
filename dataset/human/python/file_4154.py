import math
import bisect


def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp % i == 0:
            cnt = 0
            while temp % i ==0:
                cnt += 1
                temp //= i
            arr.append([i, cnt])
    if temp != 1:
        arr.append([temp, 1])
    if arr == []:
        arr.append([n, 1])
    return arr


def cal(num):
    D = 1 + 8 * num
    return (-1 + math.sqrt(D))/2


N = int(input())
n_f = factorization(N)
if N == 1:
    print(0)
    exit()
ans = 0
for i in n_f:
    ans += math.floor(cal(i[1]))
print(ans)
