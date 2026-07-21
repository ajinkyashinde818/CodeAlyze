import sys
import re
import math

S = input()
Sd = re.sub('x', '', S)
Sd_rev = Sd[::-1]

if Sd != Sd_rev:
    print(-1)
    sys.exit()

x_n = re.split('[abcdefghijklmnopqrstuvwyz]', S)
res = 0
for i in range(0, len(x_n)):
    i_rev = len(x_n) - i - 1
    res += int(math.fabs(len(x_n[i]) - len(x_n[i_rev])))
print(res // 2)
