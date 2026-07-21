def main():
  from collections import deque
  s=deque(input())
  q=int(input())
  count=0
  for _ in [0]*q:
    a=list(input().split())
    if len(a)==1:
      count+=1
    else:
      if count%2==0:
        if a[1]=='1':
           s.appendleft(a[2])
        else:
          s.append(a[2])
      else:
        if a[1]=='1':
          s.append(a[2])
        else:
          l=(a[2],s)
          s.appendleft(a[2])
  if count%2==1:
    s=list(s)[::-1]
  print(''.join(s))
if __name__=='__main__':
  main()
