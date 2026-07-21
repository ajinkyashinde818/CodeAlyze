from collections import deque

s_input = [char for char in input()]
q = int(input())
s = deque()
s_rev = deque()
s.extend(s_input)
s_rev.extendleft(s_input)
flag = True #T:inputと同順、F:逆順
count_append = 0 #文字の追加回数
for i in range(q):
  query = input().split()
  if query[0] == "1":
    flag = not flag
  else:
    if flag:
      if query[1] == "1":
        s.appendleft(query[2])
        s_rev.append(query[2])
      else:
        s.append(query[2])
        s_rev.appendleft(query[2])
    else:
      if query[1] == "1":
        s.append(query[2])
        s_rev.appendleft(query[2])
      else:
        s.appendleft(query[2])
        s_rev.append(query[2])
    count_append += 1
s_output = ""
if flag:
  for i in range(len(s_input) + count_append):
    s_output += s.popleft()
else:
  for i in range(len(s_input) + count_append):
    s_output += s.pop()
print(s_output)
