from collections import deque

s = input()
ss = s.replace('x', '')
ans = 0
i, j = 0, len(s)-1

if ss == ss[::-1]:
    while i<j:
        if s[i] != s[j]:
            ans += 1
            if s[i]=='x': i += 1
            else: j -= 1
        else:
            i += 1
            j -= 1
    print(ans)
else: print(-1)
