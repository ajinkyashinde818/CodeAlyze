from collections import deque
s = deque(input())
cnt = 0
while len(s) > 1:
  if s[0] == s[-1]:
    s.pop()
    s.popleft()
  elif s[0] == "x" and s[-1] != "x":
    s.append("x")
    cnt += 1
  elif s[0] != "x" and s[-1] == "x":
    s.appendleft("x")
    cnt += 1
  else:
    print(-1)
    exit()
print(cnt)
