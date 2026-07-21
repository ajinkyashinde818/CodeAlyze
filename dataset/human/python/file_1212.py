from itertools import accumulate
n=int(input())
A=list(map(int,input().split()))
S=list(accumulate(A))
ans=float('inf')
for i in range(n-1):
    ans=min(ans,abs(S[-1]-S[i]*2))
print(ans)
