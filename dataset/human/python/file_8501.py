import sys
read = sys.stdin.buffer.read
 
K, N, *A = map(int, read().split())
 
max_distance = K + (A[0] - A[-1])
 
for i in range(1, N):
  max_distance = max(max_distance, A[i] - A[i - 1])
  
print(K - max_distance)
