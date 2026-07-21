import math

N = int(input())
S = input()
mod = 10**9 + 7

left = 0
ret = 1
for i in range(len(S)):
    if S[i] == 'W':
        if left % 2 == 1:
            left += 1
        else:
            if left > 0:
                ret *= left
                ret %= mod
                left -= 1
            else:
                print(0)
                exit()
    else:
        if left % 2 == 1:
            ret *= left
            ret %= mod
            left -= 1
        else:
            left += 1

if left > 0:
    print(0)
    exit()
            
for i in range(1, N+1):
    ret *= i
    ret %= mod
print(ret)
