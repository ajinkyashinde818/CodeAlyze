import sys
def MI(): return map(int,sys.stdin.readline().rstrip().split())
def LS2(): return list(sys.stdin.readline().rstrip())  #空白なし

N,M = MI()
A = [LS2() for _ in range(N)]
B = [LS2() for _ in range(M)]

for i in range(N-M+1):
    for j in range(N-M+1):
        if B == [A[i][j:j+M] for i in range(i,i+M)]:
            print('Yes')
            exit()
print('No')
