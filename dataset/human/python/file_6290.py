def main():
  n=list(input())
  n=[int(i) for i in reversed(n)]
  l=len(n)
  n.append(0)
  
  ans=0
  for i in range(l):
    if n[i]<=4:
      a=n[i]
    elif n[i]==5:
      if n[i+1]<=4:
        a=n[i]
      else:
        a=10-n[i]
        n[i+1]+=1
    else:
      n[i+1]+=1
      a=10-n[i]
    ans+=a
  ans+=n[l]
  print(ans)  
if __name__=='__main__':
    main()
