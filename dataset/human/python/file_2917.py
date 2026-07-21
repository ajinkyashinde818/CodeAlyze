import numpy as np

N = int(input())

def solve(n):
    ans = []
    tmp = n
    for i in range(2, int(np.sqrt(n))+1):
        if tmp%i == 0:
            cnt = 0
            while tmp%i==0:
                cnt += 1
                tmp //= i
            ans.append(cnt)
    if tmp != 1:
        ans.append(1)
    return ans

a = solve(N)

def z_num(k):
    tmp = 1
    d = 2
    while True:
        if tmp <= k and tmp+d > k:
            return d-1
        tmp += d
        d += 1
    
b = list(map(z_num, a))
b = np.array(b)

ans = int(b.sum())

print(ans)
