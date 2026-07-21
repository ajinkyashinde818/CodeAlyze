import sys
def input(): return sys.stdin.readline().strip()

mi = lambda: map(int, input().split())

R, G, B, N = mi()

count = 0
for i in range(N//R + 1):
    for j in range((N-i*R)//G + 1):
        if (N - i*R - j*G) % B == 0:
            count += 1

print(count)
