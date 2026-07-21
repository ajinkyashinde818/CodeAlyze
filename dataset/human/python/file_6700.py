from collections import deque
def main():
  s=deque(list(input()))
  q=int(input())
  ok=1
  for i in range(q):
    query=list(input().split())
    if query[0]=='1':
      ok=(ok+1)%2
    else:
      f,c=query[1],query[2]
      if ok:
        if f=='1':
          s.appendleft(c)
        else:
          s.append(c)
      else:
        if f=='1':
          s.append(c)
        else:
          s.appendleft(c)
  s=list(s)
  if ok:
    print(''.join(s))
  else:
    print(''.join(s[::-1]))
if __name__=='__main__':
  main()
