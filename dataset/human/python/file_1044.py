n = int(input())
s = input()
d = [0 for _ in range(2*n)]
ans = 1
cnt_l = 1
cnt_r = 0
d[0] = "L"
for i in range(1, 2*n):
    if s[i] != s[i-1]:
        d[i] = d[i-1]
    elif d[i-1] == "R":
        d[i] = "L"
    else:
        d[i] = "R"
    
    if d[i] == "L":
        cnt_l += 1
    elif d[i] == "R":
        ans = ans * (cnt_l - cnt_r) % (10**9 + 7)
        cnt_r += 1

import math
ans = math.factorial(n) % (10**9 + 7) * ans

if cnt_r == cnt_l and s[0] != "W" and s[-1] != "W":
    print(ans %(10**9 + 7))
else:
    print(0)
