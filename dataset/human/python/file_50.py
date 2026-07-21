r, g, b, n = list(map(int, input().split()))

import math

counter = 0
for x in range(math.ceil(n / r) + 1):
    left = n - x * r

    for y in range(math.ceil(left / g) + 1):
        left2 = left - y * g

        if left2 >= 0 and left2 % b == 0:
            counter += 1
        # print(x, y, left2 / b)
print(counter)
