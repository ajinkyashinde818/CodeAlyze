import math

N = int(input())

def bunkai(n):
    factor={}
    tmp = int(math.sqrt(n)) + 1
    
    for num in range(2, tmp):
        while n%num == 0:
            n /= num
            try:
                factor[num] += 1
            except:
                factor[num] = 1
    if int(n) != 1:
        factor[int(n)] = 1
    
    return factor

bunchan = bunkai(N)
ans = 0

for k in bunchan.keys():
    cnt = 1
    while bunchan[k] - cnt >= 0 :
        bunchan[k] -= cnt
        cnt += 1
        ans += 1

print(ans)
