import sys
input = sys.stdin.readline
N = int(input().strip())
A = list(map(int, input().strip().split(" ")))
minus_count = 0
minimum = float("inf")
S = 0
for a in A:
    if a < 0:
        minus_count += 1
        a *= -1
    minimum = min(a, minimum)
    S += a
if minus_count % 2 == 1:
    S -= 2*minimum

print(S)
