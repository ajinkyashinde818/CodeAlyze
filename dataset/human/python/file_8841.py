import sys 

K, N = [int(i) for i in sys.stdin.readline().strip().split(" ")]
A = [int(i) for i in sys.stdin.readline().strip().split(" ")]

s = 0 
m = -1
a = []
for i in range(0, N-1):
    n = A[i+1] - A[i]
    m = max(m, n)
    s += n

n = K-A[-1] + A[0]
m = max(m, n)
s += n

print(s - m)
