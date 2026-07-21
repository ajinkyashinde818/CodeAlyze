N=int(input())
A=list(map(int,input().split()))
B=list(map(int,input().split()))
C=list(map(int,input().split()))

bonus = 0

for i in range(N-1):
    if A[i+1]==A[i]+1:
        bonus+=C[A[i]-1]



from functools import reduce

print(reduce(lambda x,y: x+y,B) + bonus)
