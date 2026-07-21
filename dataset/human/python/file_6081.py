import sys
N = int(input())
A = list(map(int, input().split()))+[0] 
B = list(map(int, input().split()))
C = list(map(int, input().split()))+[0] 
sum=sum(B)

for i in range(N):
    if A[i+1]-A[i]==1:
        sum+=C[A[i]-1]
        
print(sum)
