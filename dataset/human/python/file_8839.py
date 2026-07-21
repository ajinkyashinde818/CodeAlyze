import sys
input = sys.stdin.readline
k,n = map(int,input().split())
l = list(map(int,input().split()))
maxi = -1
for i in range(n-1):
  maxi = max(maxi,l[i+1]-l[i])
maxi = max(maxi,k-l[n-1]+l[0])
print(k-maxi)
