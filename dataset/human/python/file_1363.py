N=int(input())
a=list(map(int,input().split()))
cumSum = [0]
for i in range(N):
    cumSum.append(cumSum[i]+a[i])
def csum(l,r):
    return(cumSum[r]-cumSum[l-1])
def value(i):
    return(abs(csum(1,i)-csum(i+1,N)))
ans = value(1)
for i in range(1,N):
    ans = min(ans,value(i))
print(ans)
