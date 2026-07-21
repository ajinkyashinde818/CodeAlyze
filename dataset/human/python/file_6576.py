import array
def main():
  n=2*10**5
  s=input()
  q=int(input())
  rev=0
  l=n-1
  r=n+len(s)
  s=array.array('b',[0]*n+[ord(c) for c in s]+[0]*n)
  for _ in range(q):
    query=input().split()
    if(query[0]=='1'):
      rev=1-rev
    elif((int(query[1])+rev)%2==1):
      s[l]=ord(query[2])
      l-=1
    else:
      s[r]=ord(query[2])
      r+=1
  s=[chr(c) for c in s if c!=0]
  if rev==1:
    return ''.join(s[::-1])
  return ''.join(s)
print(main())
