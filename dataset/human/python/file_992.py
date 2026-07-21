import math
n = int(input())
S = input()

RL = [None]*2*n

for i in range(2*n):
    if i % 2 == 0:
        if S[i] == 'B':
            RL[i] = 'L'
        else:
            RL[i] = 'R'

    else:
        if S[i] == 'B':
            RL[i] = 'R'
        else:
            RL[i] = 'L'

if S[0] == 'W' or S[-1] == 'W':
    print(0)
    exit()

left = 0
count = 1
mod = 10**9 + 7

for check in RL:
    if check == 'L':
        left += 1
    else:
        count = count * left % mod
        left -= 1

    if left < 0:
        print(0)
        exit()

count = count * math.factorial(n) % mod

if left != 0:
    print(0)
else:
    print(count)
