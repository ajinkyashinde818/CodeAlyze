N = int(input())
a = [int(0.5*i*(i+1)) for i in range(10)]
import math
res = 0
top = int(math.sqrt(N))
for i in range(2,top+1):
    count = 0
    while N%i == 0:
        N = N//i
        count += 1
    for j in range(10):
        if count < a[j]:
            res += (j-1)
            break
if N != 1:
    print(res+1)
else:
    print(res)
