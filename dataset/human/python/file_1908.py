N,M = map(int,input().split())
A = [input() for _ in range(N)]
B = [input() for _ in range(M)]
def ic(x,y):
    for j in range(0,M):
        if B[j] != A[j+y][x:x+M]:return False
    else:return True
def sc():
    for j in range(0,N-M+1):
        for i in range(0,N-M+1):
            if ic(i,j):return True
    else:return False
print('Yes' if sc() else 'No')
