def main():
  import sys
  input = sys.stdin.readline
  from collections import deque
  s = list(input())
  s = s[:-1]
  s = deque(s)
  q = int(input())
  c = [[i for i in input().split()] for j in range(q)]
  cnt = 1
  for i in c:
    if i[0] == '1':
      cnt *= -1
    else:
      if (i[1] == '1' and cnt == 1) or (i[1] == '2' and cnt == -1):
        s.appendleft(i[2])
      else:
        s.append(i[2])
  if cnt == 1:
    print(''.join(s))
  else:
    print(''.join(s)[::-1])
if __name__ == '__main__':
    main()
