def main():
  S=input()
  N=int(input())
  cnt=0
  f=''
  b=''
  for i in range(N):
    tmp=[i for i in input().split() ]
    if tmp[0]=='1':
      cnt+=1
    else:
      if (cnt+int(tmp[1]))%2==1:
        f=tmp[2]+f
        
      else:
        b=b+tmp[2]
  ans=f+S+b        
  if cnt%2!=0:
    ans=''.join(list(reversed(ans)))

  print(ans)
if __name__=='__main__':
  main()
