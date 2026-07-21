N,M = map(int,input().split())
A = [input() for i in range(N)]
B = [input() for j in range(M)]
frd = N-M

def check(A,B,i,j):
    for yoko in range(M):
        for tate in range(M):
            if A[tate+i][yoko+j] != B[tate][yoko]:
                return False
    return True
    
for i in range(frd+1):
    for j in range(frd+1):
        if check(A,B,i,j):
            print("Yes")
            exit()
print("No")
