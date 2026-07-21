import os
import sys
from atexit import register
from io import BytesIO
sys.stdin = BytesIO(os.read(0, os.fstat(0).st_size))
sys.stdout = BytesIO()
register(lambda: os.write(1, sys.stdout.getvalue()))
input = lambda: sys.stdin.readline().rstrip('\r\n')
raw_input = lambda: sys.stdin.readline().rstrip('\r\n')


n = int(input())
ans = 0
p = 2
while n > 1:
    cnt = 0
    cntcnt = 1
    while n % p == 0 and n > 0:
        n  = n // p
        cnt += 1
        if cnt == cntcnt:
            ans += 1
            cnt = 0
            cntcnt += 1
    if n <= 1:
        break
    # next prime
    if p == 2:
        p = 3
    else:
        p += 2
        
        is_prime = False
        while not is_prime:
            if n % p != 0:
                p += 2
                if p*p > n:
                    p = n
                    break
                continue
            i = 5
            is_prime = True
            while (i * i <= p):
                if (p % i == 0) or (p % (i+2) == 0):
                    is_prime = False
                    break
                i += 6
            if not is_prime:
                p += 2
                

    
print(ans)
