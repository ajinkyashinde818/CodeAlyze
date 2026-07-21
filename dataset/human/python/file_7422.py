from collections import deque
def main():
  d=deque(list(input()))
  Q=int(input())
  rev=0
  for i in range(Q):
    q=list(map(str, input().split()))
    if q[0]=='1':
      rev+=1
    else:
      if (int(q[1])+rev)%2==1:
        d.appendleft(q[2])
      else:
        d.append(q[2])
  if rev%2==0:
    print(''.join(list(d)))
  else:
    d.reverse()
    print(''.join(list(d)))
main()
