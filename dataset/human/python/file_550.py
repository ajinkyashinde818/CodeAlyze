import sys

N = int(sys.stdin.readline().strip())
A = map(int, sys.stdin.readline().strip().split())

ans = 0
neg_count = 0
zero_count = 0
a_min = float("inf")
for a_i in A:
    ans += abs(a_i)
    a_min = min(a_min, abs(a_i))
    if a_i == 0:
        zero_count += 1
    elif a_i < 0:
        neg_count += 1

#print(ans)
if neg_count % 2 == 0 or zero_count > 0:
    print(ans)
else:
    #print(a_min)
    print(ans - 2 * a_min)
