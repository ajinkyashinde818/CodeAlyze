from sys import exit, stdin
K, N = [int(_) for _ in stdin.readline().rstrip().split()]
A = [int(_) for _ in stdin.readline().rstrip().split()]
distances = []
for i in range(N-1):
    distances.append(A[i+1]-A[i])
distances.append(A[0]+K-A[N-1])
print(K-max(distances))
