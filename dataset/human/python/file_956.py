import sys
N = int(input())
S = list(input())
MOD = 10**9+7

if S[0] == 'B':
    Left = 1
    ans = 1
else:
    print(0)
    sys.exit()
    
flag = True
for i in range(1,2*N):
    if flag:
        if S[i-1] != S[i]:
            Left += 1
        else:
            flag = False
            ans *= Left
            ans %= MOD
            Left -= 1
    else:
        if S[i-1] != S[i]:
            ans *= Left
            ans %= MOD
            Left -= 1
        else:
            Left += 1
            flag = True
            
if Left != 0:
    print(0)
    sys.exit()
    
for i in range(1,N+1):
    ans *= i
    ans %= MOD

print(ans)
