import sys
inputs = sys.stdin.readlines()

N = int(inputs[0])
A = list(map(int, inputs[1].split()))
B = list(map(int, inputs[2].split()))
C = list(map(int, inputs[3].split()))

x = 0
pre = -1
for a in A:
  x += B[a-1]
  if pre+1 == a:
  	x += C[pre-1]
  pre = a

print(x)
