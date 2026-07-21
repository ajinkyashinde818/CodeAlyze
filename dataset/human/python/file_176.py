from sys import stdin
r, g, b, n = [int(x) for x in stdin.readline().rstrip().split()]

ans=0
for i in range(int(n/r)+1):
  for j in range(int(n/g)+1):
    if( n < (r*i)+(g*j) ):
      continue
    if( 0 == ((n-((r*i)+(g*j)))%b) ):
      #print(i,j,r*i,g*j)
      ans +=1

print(ans)
