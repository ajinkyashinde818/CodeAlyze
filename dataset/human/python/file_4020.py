import math
import sys

def factorization(n) :
    arr = []
    temp = n
    for i in range(2 , int(math.sqrt(n))+ 1):
        if temp%i == 0:
            cnt=0
            while temp%i == 0:
                cnt += 1
                temp //= i
            arr.append([i , cnt])
    if temp != 1 :
        arr.append([temp,1])
    
    if arr == [] :
        arr.append([n,1])
    
    return arr

N = int(input())
ans = factorization(N)
x = len(ans)
time = 0
count = 2
s = 1

if ans[0][0] == 1 :
    print(0)
    sys.exit()

for i in range(x) :
    while ans[i][1] >= s :
        time += 1
        s += count
        count += 1
    s = 1
    count = 2

print(time)
