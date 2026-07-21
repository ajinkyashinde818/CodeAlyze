def f(s):
    if s==".":
        return 1
    else:
        return 0

N,M=map(int,input().split())
A=[]
for _ in range(N):
    A.append(list(map(f,input())))

B=[]
for _ in range(M):
    B.append(list(map(f,input())))

F=False
for i in range(N-M+1):
    for j in range(N-M+1):
        G=True
        for k in range(M):
            G=G and (A[j+k][i:i+M]==B[k])
        F=F|G
    
if F:
    print("Yes")
else:
    print("No")
