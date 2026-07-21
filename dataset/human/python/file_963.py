import math
mod = 10**9+7
N = int(input())
S = input()
cnt = 0
ans = 1
for i in range(N*2):
    if S[i]=='W':
        if cnt%2 == 0:
            ans*=cnt
            ans%=mod
            cnt-=1
        else:
            cnt+=1
    else:
        if cnt%2 == 0:
            cnt+=1
        else:
            ans*=cnt
            ans%=mod
            cnt-=1
if cnt==0:
    for i in range(1, N+1):
        ans*=i
        ans%=mod
    print(ans)
else:
    print(0)
