import collections

s = input()
q = int(input())
rev = 0
ans = collections.deque(['S'])

for _ in range(q):
  query = list(input().split())
  if int(query[0]) == 1:
    rev += 1
  else:
    if int(query[1]) == 1:      # 先頭
      if rev%2 == 0:
        ans.appendleft(query[2])
      else:
        ans.append(query[2])
    else:                       # 末尾
      if rev%2 == 0:
        ans.append(query[2])
      else:
        ans.appendleft(query[2])

ans = ''.join(ans)
mes = ans.replace("S", s)
if rev%2 == 0:
  print(mes)
else:
  print(mes[::-1])
