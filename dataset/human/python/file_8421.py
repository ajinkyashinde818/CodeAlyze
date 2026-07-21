import sys
k, n = map(int,input().split())
l = list(map(int,input().split()))
m = sys.maxsize

for i in range(n):
    if(i == 0):
        f = l[i-1] - l[0]
        s = (k - l[i+1]) + l[i]
    elif(i == n-1):
        f = l[i] - l[0]
        s = (k - l[i]) + l[i-1]
    else:
        f = l[i] + (k - l[i+1])
        s = (k - l[i]) + l[i-1]
    
    if(m > min(f,s)):
        m = min(f,s)

print(m)
