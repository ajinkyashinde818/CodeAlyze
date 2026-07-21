from bisect import *
N = int(input())
S = input()

swapleft = []
swapright = []

for i in range(N):
    if S[i] == "B":
        if (i+1) % 2 == 0:
            swapright.append(i+1)
    else:
        if (i+1) % 2 == 1:
            swapright.append(i+1)

for i in range(N, 2*N):
    if S[i] == "B":
        if (i+1) % 2 == 1:
            swapleft.append(i+1)
    else:
        if (i+1) % 2 == 0:
            swapleft.append(i+1)


swapleft = set(swapleft)
swapright = set(swapright)

if len(swapleft) > len(swapright):
    swapleft |= set([i for i in range(1, N+1)]) - swapright
    swapright = set([i for i in range(1, 2*N+1)]) - swapleft

else:
    swapright |= set([i for i in range(N+1, 2*N+1)]) - swapleft
    swapleft = set([i for i in range(1, 2*N+1)]) - swapright

if len(swapright) != len(swapleft):
    print(0)
else:

    swapleft = list(swapleft)

    swapleft.sort(reverse = True)
    swapright = list(swapright)
    swapright.sort()

    ans = 1

    for i in range(N):
        ans *= (N - bisect_left(swapright, swapleft[i]) - i)
        ans %= 1000000007


    for i in range(1, N+1):
        ans *= i
        ans %= 1000000007

    print(ans)
