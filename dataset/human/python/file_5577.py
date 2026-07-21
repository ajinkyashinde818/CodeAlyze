import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")


s = input()
from queue import deque
q = deque(s)
ans = 0
while q:
    if q[0]==q[-1]:
        q.popleft()
        if q:
            q.pop()
    elif q[0]=="x":
        ans += 1
        q.popleft()
    elif q[-1]=="x":
        ans += 1
        q.pop()
    else:
        ans = -1
        break
print(ans)
