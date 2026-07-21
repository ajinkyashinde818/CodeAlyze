from collections import deque

def main():
  rev = False
  s = deque(input())
  q = int(input())
  query = tuple(input() for i in range(q))

  for i in range(q):
    temp = query[i].split()
    if int(temp[0]) == 1:
      rev = not rev
    else:
      if (int(temp[1]) == 1 and (not rev)) or (int(temp[1]) == 2 and rev):
        s.appendleft(temp[2])
      else:
        s.append(temp[2])

  if rev:
    s.reverse()

  print(''.join(s))

if __name__ == '__main__':
  main()
