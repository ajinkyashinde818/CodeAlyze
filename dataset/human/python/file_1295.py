def main():
  n=int(input())
  a=list(map(int,input().split()))
  ans,s,x=abs(sum(a)-2*a[0]),sum(a),a[0]
  for i in range(1,n-1):
    x+=a[i]
    ans=min(ans,abs(s-2*x))
  print(ans)
if __name__=='__main__':
  main()
