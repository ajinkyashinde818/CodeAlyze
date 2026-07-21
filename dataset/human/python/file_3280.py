def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

import itertools
import bisect
n = int(input())
if n == 1:
    print(0)
    exit()
arr = list(range(1, 50))
arr_sum = list(itertools.accumulate(arr))
ans = 0
for i in factorization(n):
    if i[1] in arr_sum:
        ans += (bisect.bisect_left(arr_sum, i[1])+1)
    else:
        ans += bisect.bisect_left(arr_sum, i[1])
print(ans)
