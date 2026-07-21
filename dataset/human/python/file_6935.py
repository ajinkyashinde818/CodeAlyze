from collections import deque
flag = 1
s = deque(input())
q = int(input())
for i in range(q):
         z = list(map(str,input().split()))
         if z[0] == "1":
                  flag = flag*(-1)
         else:
                  if (flag == 1 and z[1] == "1")  or (flag == (-1) and z[1] == "2"):
                           s.appendleft(z[2])
                  else:
                           s.append(z[2])
if flag == (-1):
         s.reverse()
ans = "".join(s)
print(ans)
