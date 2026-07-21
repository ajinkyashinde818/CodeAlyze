from sys import exit, stdin
N, M = [int(_) for _ in stdin.readline().rstrip().split()]
A = [stdin.readline().rstrip() for n in range(N)]
B = [stdin.readline().rstrip() for m in range(M)]
for i in range(N-M+1):
  for j in range(N-M+1):
    tmp = [a[j:j+M] for a in A[i:i+M]]
    if tmp == B:
      print('Yes')
      exit()
print('No')
