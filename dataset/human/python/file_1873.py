import sys
input = sys.stdin.readline
n,m=map(int,input().split())
A=[input().strip() for _ in range(n)]
B=[input().strip() for _ in range(m)]
for i in range(n-m+1):
    for j in range(n-m+1):
        flg=True
        for k in range(m):
            #print(A[i+k][j:j+m],B[k])
            if A[i+k][j:j+m]!=B[k]:
                flg=False
        if flg:
            print("Yes")
            exit()

print("No")
