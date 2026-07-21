def main():
  from collections import deque
  s=input()
  q=int(input())
  turn = 2
  d=deque(s)

  for _ in [0]*q:
      query = input()
      if query[0] == "1":
          t = int(query)
          turn = 3 - turn
      else:
          t,f,c = map(str,query.split())
          if (int(f) + turn)% 2  == 0:
              d.append(c)
          else:
              d.appendleft(c)
  if turn == 2:
      print("".join(d))
  else:
      print("".join(list(d)[::-1]))
main()
