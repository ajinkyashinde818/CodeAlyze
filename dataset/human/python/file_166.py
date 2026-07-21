import sys

R, G, B, N = input().split()
R = int(R)
G = int(G)
B = int(B)
N = int(N)

cnt = 0

for r in range(int(N/R)+1):
    N1 = N - R*r
    for g in range(int(N1/G)+1):
        N2 = N1 - G*g
        if N2 % B == 0:
            cnt += 1

print(cnt)
