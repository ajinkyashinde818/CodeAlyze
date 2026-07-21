import sys

R, G, B, N = list(map(int, sys.stdin.readline().strip().split(" ")))

count = 0

for r in range(int(N/R) + 1):
    N1 = N - R*r
    for g in range(int(N1/G) + 1):
        N2 = N1 - G*g
        if N2 % B == 0:
            count += 1
        #for b in range(int(N2/B) + 1):
        #if r*R + g*G + b*B == N:
        #count += 1
print(count)
