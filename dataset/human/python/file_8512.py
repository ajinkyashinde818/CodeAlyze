import sys
sys.setrecursionlimit(10**7)

k,n = map(int,input().split())
ai = [int(i) for i in input().split()]

sukima = ai[0] + k - ai[n-1]

for i in range(n-1):
    sukima = max(sukima,ai[i+1]-ai[i])
    
print(k-sukima)
