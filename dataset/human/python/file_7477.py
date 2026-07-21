from collections import deque
S = input()
aaa = list(S)
aaa.reverse()
sss = "".join(aaa)

Q = int(input())
d = deque()
d.append(S)
rev = 1
cnt = 0

for i in range(Q):
  List = list(input().split())
  a = int(List[0])
  if a == 1:
    rev = rev * -1
  else:
    b = int(List[1])
    if (b == 1 and rev == 1) or (b == 2 and rev == -1):
      d.appendleft(List[2])
      cnt = cnt + 1
    else:
      d.append(List[2])

if rev == -1:
  d[cnt] = sss
  d.reverse()
string = "".join(list(d))
print(string)
