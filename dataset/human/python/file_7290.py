from collections import deque

S = input()
q = int(input())
res = deque([S])
reverseFlag = False
for i in range(q):
  tmp = input()
  t = tmp[0]
  if t == "1":
    reverseFlag ^= True # ひっくり返す
  else:
    f,c = tmp[2:].split()
    if f == "1" and reverseFlag == False or f == "2" and reverseFlag == True:
      res.appendleft(c)
    else:
      res.append(c)
if reverseFlag:
  ans = "".join(res)[::-1]
else:
  ans = "".join(res)

print(ans)
