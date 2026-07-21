def prime_factorize(n):
    a = []
    while n % 2 == 0:
        a.append(2)
        n //= 2
    f = 3
    while f * f <= n:
        if n % f == 0:
            a.append(f)
            n //= f
        else:
            f += 2
    if n != 1:
        a.append(n)
    return a

import collections

N = int(input())
val = collections.Counter(prime_factorize(N))
val = {key:cnt for key,cnt in val.most_common()} 
if val=={}:
    print(0)
else:
    prev_ans = -1
    cnt = 1
    ans = 0
    while ans!=prev_ans:
        prev_ans = ans
        for key in val:
            if val[key]>=cnt:
                val[key]-=cnt
                ans+=1
        cnt+=1
    print(ans)
