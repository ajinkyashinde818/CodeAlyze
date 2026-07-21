x = int(input())
import math
from collections import defaultdict

res = 0
value = defaultdict(int)
def isprime(n):
    if n <= 1:
        return 0
    m = int(math.sqrt(n)) + 1
    for i in range(2, m):
        if n % i == 0:
            return 0
    return 1
if isprime(x):
    print(1)
else:
    def bprime(n):
        cnt = 2
        m = int(math.sqrt(n)) + 1
        while n != 1 and cnt < m:
            while n % cnt == 0:
                n //= cnt
                value[cnt] += 1
            cnt += 1
        if cnt == m and n != 1:
            value[n] += 1
    def cal(n):
        if n <= 2:
            return 1
        j = 1
        cnt = 0
        while n >= j:
            n -= j
            j += 1
            cnt += 1
        return cnt
    bprime(x)
    for key in value.keys():
        res += cal(value[key])
    print(res)
