def main():
  n,k=map(int,input().split())
  a=list(map(int,input().split()))
  b=1
  seen=[-1]*n
  c=0
  while seen[b-1]==-1:
    seen[b-1]=c
    b=a[b-1]
    c+=1
  start=seen[b-1]
  end=c
  k=min(k,start+(k-start)%(end-start))
  b=1
  for _ in range(k):
    b=a[b-1]
  print(b)
if __name__=='__main__':
  main()
