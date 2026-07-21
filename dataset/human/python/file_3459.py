from functools import reduce
from bisect import bisect

def soinsuu_bunkai(n):
    ret = {}
    p = 2
    while p * p <= n:
        while n % p == 0:
            ret[p]= ret[p]+1 if p in ret else 1
            n //= p
        p += 1
    if n != 1:
        ret[n] = 1
    return ret   
    
def make_triangle(n):
    cnt = 0
    sum_ = 0
    for i in range(1,n+1):
        sum_ += i
        if sum_ > n:
            break
        else:
            cnt += 1
    return cnt    

dic = soinsuu_bunkai(int(input()))
ans = 0
for k,v in dic.items():
    ans += make_triangle(v)  
print(ans)
