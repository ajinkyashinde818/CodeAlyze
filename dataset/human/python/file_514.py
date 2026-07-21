import sys
N = int(sys.stdin.readline().strip())
As = list(map(int, sys.stdin.readline().strip().split()))

ans = 0
num_negative = 0
min_num = float('inf')
for A in As:
    ans += abs(A)
    min_num = min(min_num, abs(A))
    if A < 0:
        num_negative += 1
if num_negative % 2 == 1:
    ans -= 2 * min_num
print(ans)
