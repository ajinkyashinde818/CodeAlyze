from collections import deque
s = deque(input())
num = int(input())
cnt = 0
for i in range(num):
  a = input().split()

  if a[0] == '2':
    if (int(a[1])+cnt)%2==1:
      s.appendleft(a[2])
    else:
      s.append(a[2])
  else:
    cnt += 1
if cnt%2 == 1:    
	s.reverse()
print("".join(s))
