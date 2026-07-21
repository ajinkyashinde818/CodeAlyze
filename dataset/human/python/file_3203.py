import sys
N = int(input())
if N == 1:
    print(0)
    sys.exit()

C = {}
for i in range(2, max(10, int(N**(0.5))+1)):
    while(N % i == 0):
        N = N//i
        if i not in C:
            C[i] = 1
        else:
            C[i] += 1

if len(C) == 0:
    print(1)
    sys.exit()

ans = 0
for i in C.values():
    s = 1
    while(True):
        i -= s
        if i < 0:
            break
        ans += 1
        s += 1
if N == 1:
    print(ans)
else:
    print(ans+1)
