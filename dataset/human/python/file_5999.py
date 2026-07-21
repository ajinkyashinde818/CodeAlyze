def main():
  n=int(input())
  a= list(map(int,input().split()))
  b= list(map(int,input().split()))
  c= list(map(int,input().split()))
  ans=b[a[0]-1]
  for i in range(1,n):
    ans+=b[a[i]-1]
    if a[i]==a[i-1]+1:
      ans+=c[a[i]-2]
  print(ans)

main()
