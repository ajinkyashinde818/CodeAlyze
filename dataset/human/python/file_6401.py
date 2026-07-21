import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

N = int(read())

def F(N):
    if N & 1:
        return 0
    N //= 2
    x = 0
    while N:
        N //= 5
        x += N
    return x

answer = F(N)
print(answer)
