import math
MOD = 10 ** 9 + 7
N = int(input())
S = list(input())

if S[0] == 'W' or S[-1] == 'W':
    print (0)
    exit()

lst = [0] * (2 * N + 1)
ans = [-1] * (2 * N + 1) #左で選んだ時1, 右で選んだ時0
lst[0] = 1
ans[0] = 1
for i in range(1, 2 * N):
    if S[i] == 'B': #奇数にする必要
        if (lst[i - 1] + lst[i]) % 2 == 0: #前が偶数
            lst[i] += lst[i - 1] + 1
            ans[i] = 1
        else: #前が奇数
            lst[i] += lst[i - 1]
            lst[i + 1] -= 1
            ans[i] = 0

    if S[i] == 'W': #偶数にする必要
        if (lst[i - 1] + lst[i]) % 2 == 0: #前が偶数
            lst[i] += lst[i - 1]
            ans[i] = 0
            lst[i + 1] -= 1
        else: #前が奇数
            lst[i] += lst[i - 1] + 1
            ans[i] = 1

count = 1
tmp = 0
for i in range(2 * N - 1, -1, -1):
    if ans[i] == 0:
        tmp += 1
    else:
        count *= tmp
        count %= MOD
        tmp -= 1
if tmp != 0:
    print (0)
    exit()
    
count *= math.factorial(N)
print (count % MOD)
