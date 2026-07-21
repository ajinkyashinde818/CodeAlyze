import sys

N,M=map(int,input().split())
A=[input() for i in range(N)]
B=[input() for i in range(M)]

for i in range(N-M+1):
    for j in range(N-M+1):
        flag=1
        for k in range(M):
            for l in range(M):
                if B[k][l]!=A[i+k][j+l]:
                    flag=0
                    break

            if flag==0:
                break

        else:
            print("Yes")
            sys.exit()


else:
    print("No")
