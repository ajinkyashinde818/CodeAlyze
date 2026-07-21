n=int(input())
a=list(map(int,input().split()))
from numpy import cumsum
left_cumsum=cumsum(a)
a.reverse()
right_cumsum=cumsum(a)
ans=10000000000
for i in range(n-1):
    ans=min(ans,abs(left_cumsum[i]-right_cumsum[-i-2]))
print(ans)
