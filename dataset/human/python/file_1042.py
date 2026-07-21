import math

n = int(input())
cell = map(lambda x: {"B": True, "W": False}[x], input())
section = 0
ans = 1
for val in cell:
    if section % 2 == 0:
        buf = val
    else:
        buf = not val
    if buf:
        section += 1
    else:
        ans *= section
        ans %= 10 ** 9 + 7
        section -= 1
if section == 0:
    print(((math.factorial(n) % (10 ** 9 + 7)) * ans) % (10 ** 9 + 7))
else:
    print(0)
