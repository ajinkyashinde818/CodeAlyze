N,M=map(int,input().split())
A=[0 for k in range(N)]
B=[0 for k in range(M)]
for i in range(N):
    A[i]=input()
for i in range(M):
    B[i]=input()
L=N-M
mark=0
import sys
for k in range(L+1):
    for l in range(L+1):
        count=0
        for i in range(M):    
            for j in range(M):
                if B[i][j]==A[i+k][j+l]:
                    count+=1
                else:
                    break
        if mark==0 and count==M**2:
            print("Yes")
            mark=1
            sys.exit()
if mark==0:
    print("No")
