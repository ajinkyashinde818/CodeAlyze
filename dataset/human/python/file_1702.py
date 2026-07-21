n, m = map(int, input().split())
a = [input() for _ in range(n)]
b = [input() for _ in range(m)]

from itertools import permutations
import sys

def match(lt):
    if m == 1:
        rng = [(0, 0)]
    else:
        rng = permutations(range(m), 2)
    for b_x, b_y in rng:
        a_x = lt[0] + b_x
        a_y = lt[1] + b_y
        if a[a_y][a_x] != b[b_y][b_x]:
            return False

    return True

cnt = 0
for i in range(n - m + 1):
    for j in range(n - m + 1):
        if match((i, j)):
            print("Yes")
            sys.exit()

print("No")
