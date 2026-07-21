def main():
  import sys
  input = sys.stdin.readline
  n=int(input())
  a=list(map(int,input().split()))
  b=sorted([abs(i) for i in a])
  cnt=0
  for i in a:
    if i<0:
      cnt+=1
  print(sum(b) if cnt%2==0 else sum(b)-2*b[0])
if __name__=='__main__':
  main()
