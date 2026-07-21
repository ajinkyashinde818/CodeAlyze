import sys,math,collections,itertools
input = sys.stdin.readline

N,M=list(map(int,input().split()))

A = [input().rstrip() for _ in range(N)]
B = [input().rstrip() for _ in range(M)]

for h in range(N-M+1):
    for w in range(N-M+1):
        cutA = [ A[h+i][w:w+M] for i in range(M)]
        if cutA == B:
            print('Yes')
            exit()
        else:
            continue
        
print('No')
