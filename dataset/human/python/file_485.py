import sys
input = sys.stdin.readline
N = int(input())
A = list(map(int, input().split()))

minus_num = 0
minimum_abs = int(1e20)
total_sum = 0
for v in A:
    minimum_abs = min(abs(v), minimum_abs)
    total_sum += abs(v)
    if v < 0:
        minus_num += 1
if minus_num % 2 == 0:
    print(total_sum)
else:
    print(total_sum-minimum_abs*2)
