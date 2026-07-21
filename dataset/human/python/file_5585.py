import re
s = input()
s_without_x = s.replace("x", "")
if s_without_x[::-1] != s_without_x:
    print(-1)
else:
    length = len(s_without_x)
    idx = 0
    where = [0 for _ in range(length + 1)]
    for i in range(len(s)):
        now = s[i]
        if now == "x":
            where[idx] += 1
        else:
            idx += 1
    res = 0
    rev = where[::-1]
    for i in range(len(rev)):
        res += abs(where[i] - rev[i])
    print(int(res / 2))
