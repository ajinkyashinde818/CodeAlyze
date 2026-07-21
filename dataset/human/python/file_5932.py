import sys 
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
N = int(readline())
A = list(map(int,readline().split()))
B = list(map(int,readline().split()))
C = list(map(int,readline().split()))

ans = sum(B)
for i in range(N-1):
    for j in range(1,N):
        if A[i] == j and A[i+1] == j+1:
            ans += C[j-1]
print(ans)
