from collections import defaultdict
import math

def soi(num_ref):
    arr = []
    num = num_ref
    for i in range(2, int(math.sqrt(num))+1):
        if num%i == 0:
            cnt = 0
            while num%i == 0:
                cnt += 1
                num //= i
            arr.append([i, cnt])
    if num != 1:
        arr.append([num, 1])
    if arr == []:
        arr.append([num_ref, 1])
    return arr

N = int(input())
if N == 1:
    print(0)
    exit()
arr = soi(N)
cnt = 0
for i in arr:
    minus = 1
    tmp = i[1]
    while(tmp - minus >= 0):
        tmp -= minus
        minus += 1
        cnt += 1
print(cnt)
