import sys
from collections import deque
read = sys.stdin.buffer.read
readline = sys.stdin.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10 ** 7)

s = input()
q = int(input())
ans = deque(s)
cnt = 0
for _ in range(q):
    inp = readline().rstrip()
    if inp[0] == "2":
        if inp[2] == "1":
            if cnt % 2 == 0:
                ans.appendleft(inp[4])
            else:
                ans.append(inp[4])
        else:
            if cnt % 2 == 1:
                ans.appendleft(inp[4])
            else:
                ans.append(inp[4])
    else:
        cnt += 1

if cnt % 2 == 1:
    ans = list(ans)[::-1]
    
print("".join(ans))
