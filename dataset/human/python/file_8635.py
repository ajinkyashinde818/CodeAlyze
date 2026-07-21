import sys


k, n = map(int, sys.stdin.readline().split())
homes = list(map(int, sys.stdin.readline().split()))
M = -1
for i in range(n-1):
    if homes[i+1] - homes[i] > M:
        M = homes[i+1] - homes[i]
if homes[0] + k - homes[-1] > M:
    M = homes[0] + k - homes[-1]

print(k - M)
