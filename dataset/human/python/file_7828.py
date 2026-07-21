def ii():return int(input())
def iim():return map(int,input().split())
def iil():return list(map(int,input().split()))

n,k,s = iim()
ans = [s]*k+[1 if s==1000000000 else 1000000000]*(n-k)
print(*ans)
