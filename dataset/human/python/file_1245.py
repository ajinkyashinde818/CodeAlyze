import numpy as np

N = int(input())
lisA = list(map(int,input().split()))
arrA = np.array(lisA)

cumsumA = np.cumsum(arrA)

ans = 10**9 * 2 * 10**5
for num in cumsumA[:-1]:
    ans = min(ans,abs(num*2 - cumsumA[-1]))

print(ans)
