import sys;input=lambda:sys.stdin.readline().rstrip();aint=lambda:int(input());ints=lambda:list(map(int,input().split()))
import math;floor,ceil=math.floor,math.ceil
from collections import deque
Yes=lambda b:print('Yes')if b else print('No');YES=lambda b:print('YES')if b else print('NO')
is_even=lambda x:True if x%2==0 else False

def main():
  n,r = ints()
  if n>=10:
    print(r)
  else:
    print(r+100*(10-n))

      
if __name__ == '__main__':
  main()
