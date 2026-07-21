from collections import deque
import sys
input = sys.stdin.readline


ss = list(input())
n = len(ss)-1

s = deque([])
for i in range(n):
    s.append(ord(ss[i]))

p = 1

q = int(input())
for i in range(q):
    inp = list(input())

    if inp[0] == '1':
        p *= -1
    else:
        c = ord(inp[4])
        f = inp[2]
        if (f == '1' and p == 1) or (f == '2' and p == -1):
            s.appendleft(c)
        else:
            s.append(c)


n = len(s)
if p == 1:
    for e in s:
        print(chr(e),end = '')
else:
    for i in range(n-1,-1,-1):
        print(chr(s[i]),end = '')
