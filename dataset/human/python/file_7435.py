def main():
  from collections import deque
  
  s,q,*r = [list(k.split()) for k in open(0)]
  que = deque(s[0])
  p = False
  for x in r:
    if len(x)==1:
      p = not p
      continue
    if (p==False and x[1]=='1') or (p==True and x[1]=='2'):
        que.appendleft(x[2])
    else:
        que.append(x[2])
  print("".join(que) if p==False else "".join(que)[::-1])
  
if __name__=='__main__':
  main()
