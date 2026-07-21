r, g, b, n = map(int, input().split())

import math
ans = 0
for i in range(math.ceil(n / r)+1):
    for j in range(math.ceil(n / g)+1):
        if n - r * i - g * j < 0:
            break
        if  (n - r * i - g * j) % b == 0:
            ans += 1
print(ans)
