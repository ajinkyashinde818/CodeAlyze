import sys

A=[]
B=[]
NM=input().split(" ")
N=int(NM[0])
M=int(NM[1])

for i in range(N):
    t=input()
    A.append(t)
for i in range(M):
    t=input()
    B.append(t)



for i in range(N-M+1):
    for j in range(N-M+1):
        k=i
        count=0
        while A[k+count][j:M+j:1]==B[count]:
            count+=1
            if count==M:
                print("Yes")
                sys.exit()

print("No")
