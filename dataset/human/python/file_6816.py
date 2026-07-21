import collections

x = collections.deque(input())
n = int(input())
rev = False

for i in range(n):
    y = input().split()
    if len(y) == 1:
      rev = not rev
    elif rev:
      if int(y[1]) == 2:
          x.appendleft(y[2])
      else:
          x.append(y[2])
    else:
      if int(y[1]) == 2:
          x.append(y[2])
      else:
          x.appendleft(y[2])

if rev:
  x.reverse()

print("".join(x))
