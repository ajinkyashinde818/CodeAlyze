from sys import stdin
N = int(stdin.readline().rstrip())
A = [int(_) for _ in stdin.readline().rstrip().split()]
minus = []
for i in range(N):
  if A[i] < 0:
    minus.append(A[i])
abs_A = [abs(i) for i in A]
if len(minus) % 2 == 0:
  print(sum(abs_A))
else:
  print(sum(abs_A)-min(abs_A)*2)
