import math
r, g, b, n = map(int, input().split())
ans = 0
for r_num in range(math.floor(n/r)+1):
    for g_num in range(math.floor(math.floor(n - r*r_num)/g)+1):
        if ((n - (r_num * r) - (g_num * g)) % b == 0):
            ans += 1
print(ans)
